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

#include "AnalogDemDlg.h"


AnalogDemDlg::AnalogDemDlg(CDRMReceiver* pNDRMR, QWidget* parent,
	const char* name, bool modal, WFlags f) : pDRMRec(pNDRMR),
	AnalogDemDlgBase(parent, name, modal, f)
{
	/* Set help text for the controls */
	AddWhatsThisHelp();

#ifdef _WIN32 /* This works only reliable under Windows :-( */
	/* Get window geometry data from DRMReceiver module and apply it */
	const QRect WinGeom(pDRMRec->GeomAnalogDemDlg.iXPos,
		pDRMRec->GeomAnalogDemDlg.iYPos,
		pDRMRec->GeomAnalogDemDlg.iWSize,
		pDRMRec->GeomAnalogDemDlg.iHSize);

	if (WinGeom.isValid() && !WinGeom.isEmpty() && !WinGeom.isNull())
		setGeometry(WinGeom);
#endif

	/* Init main plot */
	MainPlot->SetRecObj(pDRMRec);
	MainPlot->SetPlotStyle(pDRMRec->iMainPlotColorStyle);
	MainPlot->setMargin(1);
	MainPlot->SetupChart(CDRMPlot::INPUT_SIG_PSD_ANALOG);

	/* Add tool tip to show the user the possibility of choosing the AM IF */
	QToolTip::add(MainPlot,
		tr("Click on the plot to set the demod. frequency"));

	/* Set default settings -> AM: 10 kHz; SSB: 5 kHz; medium AGC */
	iBwLSB = 5000; /* Hz */
	iBwUSB = 5000; /* Hz */
	iBwFM = 6000; /* Hz */
	iBwAM = 10000; /* Hz */
	pDRMRec->GetAMDemod()->SetDemodType(CAMDemodulation::DT_AM);
	pDRMRec->GetAMDemod()->SetFilterBW(iBwAM);
	pDRMRec->GetAMDemod()->SetAGCType(CAMDemodulation::AT_MEDIUM);

	/* Init slider control for bandwidth setting */
	SliderBandwidth->setRange(0, SOUNDCRD_SAMPLE_RATE / 2);
	SliderBandwidth->setTickmarks(QSlider::Both);
	SliderBandwidth->setTickInterval(1000); /* Each kHz a tick */
	SliderBandwidth->setPageStep(1000); /* Hz */

	/* Update controls */
	UpdateControls();


	/* Connect controls ----------------------------------------------------- */
	connect(buttonOk, SIGNAL(clicked()), this, SLOT(accept()));
	connect(MainPlot, SIGNAL(xAxisValSet(double)),
		this, SLOT(OnChartxAxisValSet(double)));
	
	/* Button groups */
	connect(ButtonGroupDemodulation, SIGNAL(clicked(int)),
		this, SLOT(OnRadioDemodulation(int)));
	connect(ButtonGroupAGC, SIGNAL(clicked(int)),
		this, SLOT(OnRadioAGC(int)));
	connect(ButtonGroupNoiseReduction, SIGNAL(clicked(int)),
		this, SLOT(OnRadioNoiRed(int)));

	/* Slider */
	connect(SliderBandwidth, SIGNAL(valueChanged(int)),
		this, SLOT(OnSliderBWChange(int)));

	/* Check boxes */
	connect(CheckBoxMuteAudio, SIGNAL(clicked()),
		this, SLOT(OnCheckBoxMuteAudio()));
	connect(CheckBoxSaveAudioWave, SIGNAL(clicked()),
		this, SLOT(OnCheckSaveAudioWAV()));

	/* Timers */
	connect(&Timer, SIGNAL(timeout()),
		this, SLOT(OnTimer()));

	/* Activte real-time timer */
	Timer.start(GUI_CONTROL_UPDATE_TIME);
}

AnalogDemDlg::~AnalogDemDlg()
{
	/* Set window geometry data in DRMReceiver module */
	QRect WinGeom = geometry();

	pDRMRec->GeomAnalogDemDlg.iXPos = WinGeom.x();
	pDRMRec->GeomAnalogDemDlg.iYPos = WinGeom.y();
	pDRMRec->GeomAnalogDemDlg.iHSize = WinGeom.height();
	pDRMRec->GeomAnalogDemDlg.iWSize = WinGeom.width();
}

void AnalogDemDlg::UpdateControls()
{
	/* Set demodulation type */
	switch (pDRMRec->GetAMDemod()->GetDemodType())
	{
	case CAMDemodulation::DT_AM:
		if (!RadioButtonDemAM->isChecked())
			RadioButtonDemAM->setChecked(TRUE);
		break;

	case CAMDemodulation::DT_LSB:
		if (!RadioButtonDemLSB->isChecked())
			RadioButtonDemLSB->setChecked(TRUE);
		break;

	case CAMDemodulation::DT_USB:
		if (!RadioButtonDemUSB->isChecked())
			RadioButtonDemUSB->setChecked(TRUE);
		break;

	case CAMDemodulation::DT_FM:
		if (!RadioButtonDemFM->isChecked())
			RadioButtonDemFM->setChecked(TRUE);
		break;
	}

	/* Set AGC type */
	switch (pDRMRec->GetAMDemod()->GetAGCType())
	{
	case CAMDemodulation::AT_NO_AGC:
		if (!RadioButtonAGCOff->isChecked())
			RadioButtonAGCOff->setChecked(TRUE);
		break;

	case CAMDemodulation::AT_SLOW:
		if (!RadioButtonAGCSlow->isChecked())
			RadioButtonAGCSlow->setChecked(TRUE);
		break;

	case CAMDemodulation::AT_MEDIUM:
		if (!RadioButtonAGCMed->isChecked())
			RadioButtonAGCMed->setChecked(TRUE);
		break;

	case CAMDemodulation::AT_FAST:
		if (!RadioButtonAGCFast->isChecked())
			RadioButtonAGCFast->setChecked(TRUE);
		break;
	}

	/* Set noise reduction type */
	switch (pDRMRec->GetAMDemod()->GetNoiRedType())
	{
	case CAMDemodulation::NR_OFF:
		if (!RadioButtonNoiRedOff->isChecked())
			RadioButtonNoiRedOff->setChecked(TRUE);
		break;

	case CAMDemodulation::NR_LOW:
		if (!RadioButtonNoiRedLow->isChecked())
			RadioButtonNoiRedLow->setChecked(TRUE);
		break;

	case CAMDemodulation::NR_MEDIUM:
		if (!RadioButtonNoiRedMed->isChecked())
			RadioButtonNoiRedMed->setChecked(TRUE);
		break;

	case CAMDemodulation::NR_HIGH:
		if (!RadioButtonNoiRedHigh->isChecked())
			RadioButtonNoiRedHigh->setChecked(TRUE);
		break;
	}

	/* Set filter bandwidth */
	SliderBandwidth->setValue(pDRMRec->GetAMDemod()->GetFilterBW());
	TextLabelBandWidth->setText(QString().setNum(
		pDRMRec->GetAMDemod()->GetFilterBW()) +	tr(" Hz"));

	/* Update check boxes */
	CheckBoxMuteAudio->setChecked(pDRMRec->GetWriteData()->GetMuteAudio());
	CheckBoxSaveAudioWave->
		setChecked(pDRMRec->GetWriteData()->GetIsWriteWaveFile());
}

void AnalogDemDlg::showEvent(QShowEvent* pEvent)
{
	/* Update controls */
	UpdateControls();
}

void AnalogDemDlg::OnTimer()
{
	/* Carrier frequency of AM signal */
	TextFreqOffset->setText(tr("Carrier Frequency: ") + QString().setNum(
		pDRMRec->GetParameters()->GetDCFrequency(), 'f', 2) + " Hz");
}

void AnalogDemDlg::OnRadioDemodulation(int iID)
{
	switch (iID)
	{
	case 0:
		pDRMRec->GetAMDemod()->SetDemodType(CAMDemodulation::DT_AM);
		pDRMRec->GetAMDemod()->SetFilterBW(iBwAM);
		break;

	case 1:
		pDRMRec->GetAMDemod()->SetDemodType(CAMDemodulation::DT_LSB);
		pDRMRec->GetAMDemod()->SetFilterBW(iBwLSB);
		break;

	case 2:
		pDRMRec->GetAMDemod()->SetDemodType(CAMDemodulation::DT_USB);
		pDRMRec->GetAMDemod()->SetFilterBW(iBwUSB);
		break;

	case 3:
		pDRMRec->GetAMDemod()->SetDemodType(CAMDemodulation::DT_FM);
		pDRMRec->GetAMDemod()->SetFilterBW(iBwFM);
		break;
	}

	/* Update controls */
	UpdateControls();
}

void AnalogDemDlg::OnRadioAGC(int iID)
{
	switch (iID)
	{
	case 0:
		pDRMRec->GetAMDemod()->SetAGCType(CAMDemodulation::AT_NO_AGC);
		break;

	case 1:
		pDRMRec->GetAMDemod()->SetAGCType(CAMDemodulation::AT_SLOW);
		break;

	case 2:
		pDRMRec->GetAMDemod()->SetAGCType(CAMDemodulation::AT_MEDIUM);
		break;

	case 3:
		pDRMRec->GetAMDemod()->SetAGCType(CAMDemodulation::AT_FAST);
		break;
	}
}

void AnalogDemDlg::OnRadioNoiRed(int iID)
{
	switch (iID)
	{
	case 0:
		pDRMRec->GetAMDemod()->SetNoiRedType(CAMDemodulation::NR_OFF);
		break;

	case 1:
		pDRMRec->GetAMDemod()->SetNoiRedType(CAMDemodulation::NR_LOW);
		break;

	case 2:
		pDRMRec->GetAMDemod()->SetNoiRedType(CAMDemodulation::NR_MEDIUM);
		break;

	case 3:
		pDRMRec->GetAMDemod()->SetNoiRedType(CAMDemodulation::NR_HIGH);
		break;
	}
}

void AnalogDemDlg::OnSliderBWChange(int value)
{
	/* Set new filter in processing module */
	pDRMRec->GetAMDemod()->SetFilterBW(value);
	TextLabelBandWidth->setText(QString().setNum(value) + tr(" Hz"));

	/* Store filter bandwidth for this demodulation type */
	switch (pDRMRec->GetAMDemod()->GetDemodType())
	{
	case CAMDemodulation::DT_AM:
		iBwAM = value;
		break;

	case CAMDemodulation::DT_LSB:
		iBwLSB = value;
		break;

	case CAMDemodulation::DT_USB:
		iBwUSB = value;
		break;

	case CAMDemodulation::DT_FM:
		iBwFM = value;
		break;
	}

	/* Update chart */
	MainPlot->Update();
}

void AnalogDemDlg::OnCheckBoxMuteAudio()
{
	/* Set parameter in working thread module */
	pDRMRec->GetWriteData()->MuteAudio(CheckBoxMuteAudio->isChecked());
}

void AnalogDemDlg::OnCheckSaveAudioWAV()
{
/*
	This code is copied in systemevalDlg.cpp. If you do changes here, you should
	apply the changes in the other file, too
*/
	if (CheckBoxSaveAudioWave->isChecked() == TRUE)
	{
		/* Show "save file" dialog */
		QString strFileName =
			QFileDialog::getSaveFileName("DreamOut.wav", "*.wav", this);

		/* Check if user not hit the cancel button */
		if (!strFileName.isNull())
		{
			pDRMRec->GetWriteData()->
				StartWriteWaveFile(strFileName.latin1());
		}
		else
		{
			/* User hit the cancel button, uncheck the button */
			CheckBoxSaveAudioWave->setChecked(FALSE);
		}
	}
	else
		pDRMRec->GetWriteData()->StopWriteWaveFile();
}

void AnalogDemDlg::OnChartxAxisValSet(double dVal)
{
	/* Set new frequency in receiver module */
	pDRMRec->SetAMDemodAcq(dVal);

	/* Update chart */
	MainPlot->Update();
}

void AnalogDemDlg::AddWhatsThisHelp()
{
	/* Noise Reduction */
	const QString strNoiseReduction =
		tr("<b>Noise Reduction:</b> The noise suppression is a frequency "
		"domain optimal filter design based algorithm. The noise PSD is "
		"estimated utilizing a minimum statistic. A problem of this type of "
		"algorithm is that it produces the so called \"musical tones\". The "
		"noise becomes colored and sounds a bit strange. At the same time, "
		"the useful signal (which might be speech or music) is also "
		"distorted by the algorithm. By selecting the level of noise "
		"reduction, a compromise between distortion of the useful signal "
		"and actual noise reduction can be made.");

	QWhatsThis::add(ButtonGroupNoiseReduction, strNoiseReduction);
	QWhatsThis::add(RadioButtonNoiRedOff, strNoiseReduction);
	QWhatsThis::add(RadioButtonNoiRedLow, strNoiseReduction);
	QWhatsThis::add(RadioButtonNoiRedMed, strNoiseReduction);
	QWhatsThis::add(RadioButtonNoiRedHigh, strNoiseReduction);

	/* Automatic Gain Control */
	const QString strAGC =
		tr("<b>AGC (Automatic Gain Control):</b> Input signals can have a "
		"large variation in power due to channel impairments. To compensate "
		"for that, an automatic gain control can be applied. The AGC has "
		"four settings: Off, Slow, Medium and Fast.");

	QWhatsThis::add(ButtonGroupAGC, strAGC);
	QWhatsThis::add(RadioButtonAGCOff, strAGC);
	QWhatsThis::add(RadioButtonAGCSlow, strAGC);
	QWhatsThis::add(RadioButtonAGCMed, strAGC);
	QWhatsThis::add(RadioButtonAGCFast, strAGC);

	/* Filter Bandwidth */
	const QString strFilterBW =
		tr("<b>Filter Bandwidth:</b> A band-pass filter is applied before "
		"the actual demodulation process. With this filter, adjacent signals "
		"are attenuated. The bandwidth of this filter can be chosen in steps "
		"of 1 Hz by using the slider bar. Clicking on the right or left side "
		"of the slider leveler will increase/decrease the bandwidth by 1 kHz. "
		"<br>The current filter bandwidth is indicated in the spectrum plot "
		"by a selection bar.");

	QWhatsThis::add(ButtonGroupBW, strFilterBW);
	QWhatsThis::add(TextLabelBandWidth, strFilterBW);
	QWhatsThis::add(SliderBandwidth, strFilterBW);

	/* Demodulation type */
	const QString strDemodType =
		tr("<b>Demodulation Type:</b> There are four different analog "
		"demodulation types available:<ul>"
		"<li><b>AM:</b> This analog demodulation type is used in most of "
		"the hardware radios. The envelope of the complex base-band signal "
		"is used followed by a high-pass filter to remove the DC offset.</li>"
		"<li><b>LSB / USB:</b> These are single-side-band (SSB) demodulation "
		"types. Only one side of the spectrum is evaluated, the upper side "
		"band is used in USB and the lower side band with LSB. It is "
		"important for SSB demodulation that the DC frequency of the analog "
		"signal is known to get satisfactory results. The DC frequency is "
		"automatically estimated by starting a new acquisition or by "
		"clicking on the plot.</li>"
		"<li><b>FM:</b> This is a narrow band frequency demodulation.</li>"
		"</ul>");

	QWhatsThis::add(ButtonGroupDemodulation, strDemodType);
	QWhatsThis::add(RadioButtonDemAM, strDemodType);
	QWhatsThis::add(RadioButtonDemLSB, strDemodType);
	QWhatsThis::add(RadioButtonDemUSB, strDemodType);
	QWhatsThis::add(RadioButtonDemFM, strDemodType);

	/* Mute Audio (same as in systemevaldlg.cpp!) */
	QWhatsThis::add(CheckBoxMuteAudio,
		tr("<b>Mute Audio:</b> The audio can be muted by "
		"checking this box. The reaction of checking or unchecking this box "
		"is delayed by approx. 1 second due to the audio buffers."));

	/* Save audio as wave (same as in systemevaldlg.cpp!) */
	QWhatsThis::add(CheckBoxSaveAudioWave,
		tr("<b>Save Audio as WAV:</b> Save the audio signal "
		"as stereo, 16-bit, 48 kHz sample rate PCM wave file. Checking this "
		"box will let the user choose a file name for the recording."));

	/* Carrier Frequency */
	const QString strCarFreq =
		tr("<b>Carrier Frequency:</b> The estimated carrier frequency of the "
		"analog signal is shown. The estimation of this parameter is done by "
		"using the estimated PSD of the input signal and doing a maximum "
		"search.");

	QWhatsThis::add(FrameCarrierFrequency, strCarFreq);
	QWhatsThis::add(TextFreqOffset, strCarFreq);
}
