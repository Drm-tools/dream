/******************************************************************************\
 * Technische Universitaet Darmstadt, Institut fuer Nachrichtentechnik
 * Copyright (c) 2001
 *
 * Author(s):
 *	Volker Fischer
 *
 * Description:
 *	
 *
 ******************************************************************************
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option) any later 
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT 
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more 
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
\******************************************************************************/

#ifndef __DRMPLOT_H
#define __DRMPLOT_H

#include "../util/Vector.h"
#include "../Parameter.h"
#include "../DrmReceiver.h"
#include <qwt_plot.h>
#include <qtimer.h>
#if QWT_VERSION >= 0x050000
# include <qwt_plot_curve.h>
# include <qwt_plot_grid.h>
# include <qwt_symbol.h>
#endif

/* Definitions ****************************************************************/
#define GUI_CONTROL_UPDATE_WATERFALL			100	/* Milliseconds */


/* Define the plot color profiles */
/* BLUEWHITE */
#define BLUEWHITE_MAIN_PEN_COLOR_PLOT			Qt::blue
#define BLUEWHITE_MAIN_PEN_COLOR_CONSTELLATION		Qt::blue
#define BLUEWHITE_BCKGRD_COLOR_PLOT			Qt::white
#define BLUEWHITE_MAIN_GRID_COLOR_PLOT			Qt::gray
#define BLUEWHITE_SPEC_LINE1_COLOR_PLOT			Qt::red
#define BLUEWHITE_SPEC_LINE2_COLOR_PLOT			Qt::black
#define BLUEWHITE_PASS_BAND_COLOR_PLOT			QColor(192, 192, 255)

/* GREENBLACK */
#define GREENBLACK_MAIN_PEN_COLOR_PLOT			Qt::green
#define GREENBLACK_MAIN_PEN_COLOR_CONSTELLATION	Qt::red
#define GREENBLACK_BCKGRD_COLOR_PLOT			Qt::black
#define GREENBLACK_MAIN_GRID_COLOR_PLOT			QColor(128, 0, 0)
#define GREENBLACK_SPEC_LINE1_COLOR_PLOT		Qt::yellow
#define GREENBLACK_SPEC_LINE2_COLOR_PLOT		Qt::blue
#define GREENBLACK_PASS_BAND_COLOR_PLOT			QColor(0, 96, 0)

/* BLACKGREY */
#define BLACKGREY_MAIN_PEN_COLOR_PLOT			Qt::black
#define BLACKGREY_MAIN_PEN_COLOR_CONSTELLATION	Qt::green
#define BLACKGREY_BCKGRD_COLOR_PLOT				Qt::gray
#define BLACKGREY_MAIN_GRID_COLOR_PLOT			Qt::white
#define BLACKGREY_SPEC_LINE1_COLOR_PLOT			Qt::blue
#define BLACKGREY_SPEC_LINE2_COLOR_PLOT			Qt::yellow
#define BLACKGREY_PASS_BAND_COLOR_PLOT			QColor(128, 128, 128)

/* Maximum and minimum values of x-axis of input spectrum plots */
#define MIN_VAL_INP_SPEC_Y_AXIS_DB				((double) -125.0)
#define MAX_VAL_INP_SPEC_Y_AXIS_DB				((double) -25.0)

/* Maximum and minimum values of x-axis of input PSD (shifted) */
#define MIN_VAL_SHIF_PSD_Y_AXIS_DB				((double) -85.0)
#define MAX_VAL_SHIF_PSD_Y_AXIS_DB				((double) -35.0)

/* Maximum and minimum values of x-axis of SNR spectrum */
#define MIN_VAL_SNR_SPEC_Y_AXIS_DB				((double) 0.0)
#define MAX_VAL_SNR_SPEC_Y_AXIS_DB				((double) 35.0)

class CDRMPlot : public QwtPlot
{
    Q_OBJECT

public:
	enum ECharType
	{
		INPUT_SIG_PSD = 0, /* default */
		TRANSFERFUNCTION = 1,
		FAC_CONSTELLATION = 2,
		SDC_CONSTELLATION = 3,
		MSC_CONSTELLATION = 4,
		POWER_SPEC_DENSITY = 5,
		INPUTSPECTRUM_NO_AV = 6,
		AUDIO_SPECTRUM = 7,
		FREQ_SAM_OFFS_HIST = 8,
		DOPPLER_DELAY_HIST = 9,
		ALL_CONSTELLATION = 10,
		SNR_AUDIO_HIST = 11,
		AVERAGED_IR = 12,
		SNR_SPECTRUM = 13,
		INPUT_SIG_PSD_ANALOG = 14,
		INP_SPEC_WATERF = 15,
		NONE_OLD = 16 /* None must always be the last element! (see settings) */
	};

	CDRMPlot(QWidget *p = 0, const char *name = 0);
	virtual ~CDRMPlot() {}

	/* This function has to be called before chart can be used! */
	void SetRecObj(CDRMReceiver* pNDRMRec);

	void SetupChart(const ECharType eNewType);
	ECharType GetChartType() const;
	void Update();

	void SetAvIR(CVector<_REAL>& vecrData, CVector<_REAL>& vecrScale, 
				 _REAL rLowerB, _REAL rHigherB,
				 const _REAL rStartGuard, const _REAL rEndGuard, 
				 const _REAL rBeginIR, const _REAL rEndIR);
	void SetTranFct(CVector<_REAL>& vecrData, CVector<_REAL>& vecrData2,
					CVector<_REAL>& vecrScale);
	void SetAudioSpec(CVector<_REAL>& vecrData, CVector<_REAL>& vecrScale);
	void SetPSD(CVector<_REAL>& vecrData, CVector<_REAL>& vecrScale);
	void SetSNRSpectrum(CVector<_REAL>& vecrData, CVector<_REAL>& vecrScale);
	void SetInpSpec(CVector<_REAL>& vecrData, CVector<_REAL>& vecrScale,
					const _REAL rDCFreq);
	void SetInpPSD(CVector<_REAL>& vecrData, CVector<_REAL>& vecrScale,
				   const _REAL rDCFreq, const _REAL rBWCenter = (_REAL) 0.0,
				   const _REAL rBWWidth = (_REAL) 0.0);
	void SetInpSpecWaterf(CVector<_REAL>& vecrData, CVector<_REAL>& vecrScale);
	void SetFreqSamOffsHist(CVector<_REAL>& vecrData, CVector<_REAL>& vecrData2,
							CVector<_REAL>& vecrScale,
							const _REAL rFreqOffAcquVal);
	void SetDopplerDelayHist(CVector<_REAL>& vecrData,
							 CVector<_REAL>& vecrData2,
							 CVector<_REAL>& vecrScale);
	void SetSNRAudHist(CVector<_REAL>& vecrData,
					   CVector<_REAL>& vecrData2,
					   CVector<_REAL>& vecrScale);
	void SetFACConst(CVector<_COMPLEX>& veccData);
	void SetSDCConst(CVector<_COMPLEX>& veccData, ECodScheme eNewCoSc);
	void SetMSCConst(CVector<_COMPLEX>& veccData, ECodScheme eNewCoSc);
	void SetAllConst(CVector<_COMPLEX>& veccMSC,
					 CVector<_COMPLEX>& veccSDC,
					 CVector<_COMPLEX>& veccFAC);
	void SetPlotStyle(const int iNewStyleID);


#if QT_VERSION < 0x040000
# include "DRMPlot-qwt4.h"
#else
# include "DRMPlot-qwt5.h"
#endif

public slots:
	void OnClicked(const QMouseEvent& e);
	void OnTimerChart();

signals:
	void xAxisValSet(double);
};

#endif
