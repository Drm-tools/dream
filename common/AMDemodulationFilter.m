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
nhil = 181;

% Other filter parameters
ftrans = 700; % Size of transition region

fs = 48000; % Constant for all cases

filterbws = [1000:500:15000];


% Generate filter coefficients
for i = 1:length(filterbws)
    b(i, :) = DesignFilter(filterbws(i), ftrans, nhil, fs);
end

if (PLOT == 1)
    close all;
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


fprintf(fid, '#define NUM_AM_DEMOD_FILTER             ');
fprintf(fid, int2str(length(filterbws)));
fprintf(fid, '\n');
fprintf(fid, '#define NUM_TAPS_AM_DEMOD_FILTER        ');
fprintf(fid, int2str(nhil));
fprintf(fid, '\n\n\n');


% Write bandwidths
fprintf(fid, '/* Bandwidths */\n');
fprintf(fid, ['static int iHilLPProtAMDemodBW[NUM_AM_DEMOD_FILTER] =\n']);
fprintf(fid, '{\n');
fprintf(fid, '	%d,\n', filterbws(1:end - 1));
fprintf(fid, '	%d\n', filterbws(end));
fprintf(fid, '};\n\n');        

% Write filter taps
fprintf(fid, '/* Low pass prototypes for Hilbert-filter */\n');
fprintf(fid, ['static float fHilLPProtAMDemod[NUM_AM_DEMOD_FILTER][NUM_TAPS_AM_DEMOD_FILTER] = {\n']);
for i = 1:length(filterbws)
	fprintf(fid, '{\n');
	fprintf(fid, '	%.20ff,\n', b(i, 1:end - 1));
	fprintf(fid, '	%.20ff\n', b(i, end));
    if (i < length(filterbws))
        fprintf(fid, '},\n');
    else
        fprintf(fid, '}\n');        
    end
end
fprintf(fid, '};\n\n\n');

fprintf(fid, '\n#endif /* _AMDEMODULATION_H_ */\n');
fclose(fid);
return;


function [b] = DesignFilter(B, ftrans, nhil, fs)
	f = [0  B / 2 - ftrans / 2  B / 2  fs / 2];
	m = [2 2 0 0];

    % Different types of filter prototype generation
%	b = remez(nhil - 1, f * 2 / fs, m, [1 150]);
%   b = fir1(nhil - 1, B / fs, 'low', blackmanharris(nhil));
%   b = fir1(nhil - 1, B / fs, 'low', blackman(nhil));
%   b = fir1(nhil - 1, B / fs, 'low', bartlett(nhil));
    b = firls(nhil - 1, f * 2 / fs, m, [1 5000]);
return;
