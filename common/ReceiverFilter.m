%******************************************************************************\
%* Technische Universitaet Darmstadt, Institut fuer Nachrichtentechnik
%* Copyright (c) 2004
%*
%* Author:
%*	Volker Fischer, Alexander Kurpiers
%*
%* Description:
%* 	Receiver filter for iterferer attenuation
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

function [] = ReceiverFilter()
PLOT = 1;

nTaps4_5 = 250;
nTaps5 = 250;
nTaps9 = 230;
nTaps10 = 230;
nTaps18 = 210;
nTaps20 = 210;
ftrans5 = 300; % Size of transition region
ftrans10 = 400; % Size of transition region
ftrans20 = 500; % Size of transition region
fs = 48000; % Constant for all cases

% Actual filter design for all DRM modes
Offset = -500;
h4_5 = DesignFilter(0, 4500 + Offset, ftrans5, nTaps4_5, fs); % 4.5 kHz
h5 = DesignFilter(0, 5000 + Offset, ftrans5, nTaps5, fs); % 5 kHz
h9 = DesignFilter(0, 9000 + Offset, ftrans10, nTaps9, fs); % 9 kHz
h10 = DesignFilter(0, 10000 + Offset, ftrans10, nTaps10, fs); % 10 kHz
h18 = DesignFilter(0, 18000 + Offset, ftrans20, nTaps18, fs); % 18 kHz
h20 = DesignFilter(0, 20000 + Offset, ftrans20, nTaps20, fs); % 20 kHz

if (PLOT == 1)
    close all;
    freqz(h4_5);
    figure;
    freqz(h5);
    figure;
    freqz(h9);
    figure;
    freqz(h10);
    figure;
    freqz(h18);
    figure;
    freqz(h20);
end


% Export coefficiants to file ****************************************
fid = fopen('ReceiverFilter.h', 'w');

fprintf(fid, '/* Automatically generated file with MATLAB */\n');
fprintf(fid, '/* File name: "ReceiverFilter.m" */\n');
fprintf(fid, '/* Filter taps in time-domain */\n\n');

fprintf(fid, '#ifndef _RECEIVERFILTER_H_\n');
fprintf(fid, '#define _RECEIVERFILTER_H_\n\n');

fprintf(fid, '#define HALF_MAX_NUM_TAPS_RECFILTER     ');
fprintf(fid, int2str(max([nTaps4_5 nTaps5 nTaps9 nTaps10 nTaps18 nTaps20]) / 2));
fprintf(fid, '\n');
fprintf(fid, '#define NUM_TAPS_RECFILTER_4_5          ');
fprintf(fid, int2str(nTaps4_5));
fprintf(fid, '\n');
fprintf(fid, '#define NUM_TAPS_RECFILTER_5            ');
fprintf(fid, int2str(nTaps5));
fprintf(fid, '\n');
fprintf(fid, '#define NUM_TAPS_RECFILTER_9            ');
fprintf(fid, int2str(nTaps9));
fprintf(fid, '\n');
fprintf(fid, '#define NUM_TAPS_RECFILTER_10           ');
fprintf(fid, int2str(nTaps10));
fprintf(fid, '\n');
fprintf(fid, '#define NUM_TAPS_RECFILTER_18           ');
fprintf(fid, int2str(nTaps18));
fprintf(fid, '\n');
fprintf(fid, '#define NUM_TAPS_RECFILTER_20           ');
fprintf(fid, int2str(nTaps20));
fprintf(fid, '\n\n\n');


% Write filter taps
fprintf(fid, '/* 4.5 kHz bandwidth */\n');
fprintf(fid, 'static float fRecFilt4_5[NUM_TAPS_RECFILTER_4_5] =\n');
fprintf(fid, '{\n');
fprintf(fid, '	%.20ff,\n', h4_5(1:end - 1));
fprintf(fid, '	%.20ff\n', h4_5(end));
fprintf(fid, '};\n\n');

fprintf(fid, '/* 5 kHz bandwidth */\n');
fprintf(fid, 'static float fRecFilt5[NUM_TAPS_RECFILTER_5] =\n');
fprintf(fid, '{\n');
fprintf(fid, '	%.20ff,\n', h5(1:end - 1));
fprintf(fid, '	%.20ff\n', h5(end));
fprintf(fid, '};\n\n');

fprintf(fid, '/* 9 kHz bandwidth */\n');
fprintf(fid, 'static float fRecFilt9[NUM_TAPS_RECFILTER_9] =\n');
fprintf(fid, '{\n');
fprintf(fid, '	%.20ff,\n', h9(1:end - 1));
fprintf(fid, '	%.20ff\n', h9(end));
fprintf(fid, '};\n\n');

fprintf(fid, '/* 10 kHz bandwidth */\n');
fprintf(fid, 'static float fRecFilt10[NUM_TAPS_RECFILTER_10] =\n');
fprintf(fid, '{\n');
fprintf(fid, '	%.20ff,\n', h10(1:end - 1));
fprintf(fid, '	%.20ff\n', h10(end));
fprintf(fid, '};\n\n');

fprintf(fid, '/* 18 kHz bandwidth */\n');
fprintf(fid, 'static float fRecFilt18[NUM_TAPS_RECFILTER_18] =\n');
fprintf(fid, '{\n');
fprintf(fid, '	%.20ff,\n', h18(1:end - 1));
fprintf(fid, '	%.20ff\n', h18(end));
fprintf(fid, '};\n\n');

fprintf(fid, '/* 20 kHz bandwidth */\n');
fprintf(fid, 'static float fRecFilt20[NUM_TAPS_RECFILTER_20] =\n');
fprintf(fid, '{\n');
fprintf(fid, '	%.20ff,\n', h20(1:end - 1));
fprintf(fid, '	%.20ff\n', h20(end));
fprintf(fid, '};\n\n\n');

fprintf(fid, '#endif	/* _RECEIVERFILTER_H_ */\n');
fclose(fid);
return;


function [b] = DesignFilter(fstart, fstop, ftrans, nhil, fs)
	B = fstop - fstart;
	f = [0  B / 2  B / 2 + ftrans  fs / 2];

if 0    
    % Parks-McClellan optimal equiripple FIR filter design
	m = [2 2 0 0];
	b = remez(nhil - 1, f * 2 / fs, m, [1 0.3]);
else
    % FIR least squares design
    beta = 3;
    b = firls(nhil - 1, f * 2 / fs, [1 1 0 0]) .* kaiser(nhil, beta)' .* 2;
end
return;
