%******************************************************************************\
%* Technische Universitaet Darmstadt, Institut fuer Nachrichtentechnik
%* Copyright (c) 2003
%*
%* Author:
%*	Alexander Kurpiers, Volker Fischer
%*
%* Description:
%* 	Hilbert Filter for AM demodulation
%*
%******************************************************************************
%*
%* This program is free software; you can redistribute it and/or modify it under
%* the terms of the GNU General Public License as published by the Free Software
%* Foundation; either version 2 of the License, or (at your option) any later 
%* version.
%*
%* This program is distributed in the hope that it will be useful, but WITHOUT 
%* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
%* FOR A PARTICULAR PURPOSE. See the GNU General Public License for more 
%* details.
%*
%* You should have received a copy of the GNU General Public License along with
%* this program; if not, write to the Free Software Foundation, Inc., 
%* 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
%*
%******************************************************************************/

function [] = AMDemodulationFilter()
PLOT = 1;

% Number of taps
nhil = 81;

% Other filter parameters
fstart = 800;
ftrans = 800; % Size of transition region
fadd = 200; % Additional bandwidth. E.g. 10 kHz mode will be 10000 + fadd Hz

fs = 48000; % Constant for all cases

filterbws = [1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, ...
        10000, 11000, 12000, 13000, 14000, 15000];


% Generate filter coefficients
for i = 1:length(filterbws)
    b(i, :) = DesignFilter(fstart, filterbws(i) + fadd, ftrans, nhil, fs);
end

if (PLOT == 1)
    for i = 1:length(filterbws)
        figure;
        freqz(b(i, :), 1);
    end
end


% Export coefficiants to file ****************************************
fid = fopen('AMDemodulationFilter.h', 'w');

fprintf(fid, '/* Automatically generated file with MATLAB */\n');
fprintf(fid, '/* File name: "AMDemodulationFilter.m" */\n');
fprintf(fid, '/* Filter taps in time-domain */\n\n');

fprintf(fid, '#ifndef _AMDEMODULATION_H_\n');
fprintf(fid, '#define _AMDEMODULATION_H_\n\n');


fprintf(fid, '#define NUM_TAPS_AM_DEMOD_FILTER        ');
fprintf(fid, int2str(nhil));
fprintf(fid, '\n');
fprintf(fid, '#define HILB_FILT_BNDWIDTH_ADD          ');
fprintf(fid, int2str(fadd));
fprintf(fid, '\n');
fprintf(fid, '\n\n\n');


% Write filter taps
fprintf(fid, '/* Low pass prototypes for Hilbert-filter */\n');
for i = 1:length(filterbws)
	fprintf(fid, ['static float fHilLPProtAMDemod' int2str(filterbws(i) / 1000) '[NUM_TAPS_AM_DEMOD_FILTER] =\n']);
	fprintf(fid, '{\n');
	fprintf(fid, '	%.20ff,\n', b(i, 1:end - 1));
	fprintf(fid, '	%.20ff\n', b(i, end));
	fprintf(fid, '};\n\n');
end

fprintf(fid, '\n#endif /* _AMDEMODULATION_H_ */\n');
fclose(fid);
return;


function [b] = DesignFilter(fstart, fstop, ftrans, nhil, fs)
    % Parks-McClellan optimal equiripple FIR filter design
	B = fstop - fstart;

	f = [0  B / 2  B / 2 + ftrans  fs / 2];
	m = [2 2 0 0];

	b = remez(nhil - 1, f * 2 / fs, m, [1 10]);
return;
