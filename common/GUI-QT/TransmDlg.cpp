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

#include "TransmDlg.h"


TransmDialog::TransmDialog(QWidget* parent, const char* name, bool modal, WFlags f)
	: TransmDlgBase(parent, name, modal, f), bIsStarted(FALSE)
{
	int i;

	/* Init controls with default settings */
	ButtonStartStop->setText("&Start");

	/* Robustness mode */
	switch (TransThread.DRMTransmitter.GetParameters()->GetWaveMode())
	{
	case RM_ROBUSTNESS_MODE_A:
		RadioButtonRMA->setChecked(TRUE);
		break;

	case RM_ROBUSTNESS_MODE_B:
		RadioButtonRMB->setChecked(TRUE);
		break;

	case RM_ROBUSTNESS_MODE_C:
		RadioButtonRMC->setChecked(TRUE);
		break;

	case RM_ROBUSTNESS_MODE_D:
		RadioButtonRMD->setChecked(TRUE);
		break;
	}

	/* Bandwidth */
	switch (TransThread.DRMTransmitter.GetParameters()->GetSpectrumOccup())
	{
	case SO_0:
		RadioButtonBandwidth45->setChecked(TRUE);
		break;

	case SO_1:
		RadioButtonBandwidth5->setChecked(TRUE);
		break;

	case SO_2:
		RadioButtonBandwidth9->setChecked(TRUE);
		break;

	case SO_3:
		RadioButtonBandwidth10->setChecked(TRUE);
		break;

	case SO_4:
		RadioButtonBandwidth18->setChecked(TRUE);
		break;

	case SO_5:
		RadioButtonBandwidth20->setChecked(TRUE);
		break;
	}

	/* MSC interleaver mode */
	ComboBoxMSCInterleaver->insertItem("2 s (Long Interleaving)", 0);
	ComboBoxMSCInterleaver->insertItem("400 ms (Short Interleaving)", 1);

	switch (TransThread.DRMTransmitter.GetParameters()->eSymbolInterlMode)
	{
	case CParameter::SI_LONG:
		ComboBoxMSCInterleaver->setCurrentItem(0);
		break;

	case CParameter::SI_SHORT:
		ComboBoxMSCInterleaver->setCurrentItem(1);
		break;
	}

	/* MSC Constellation Scheme */
	ComboBoxMSCConstellation->insertItem("SM 16-QAM", 0);
	ComboBoxMSCConstellation->insertItem("SM 64-QAM", 1);
	ComboBoxMSCConstellation->insertItem("HMsym 64-QAM", 2);
	ComboBoxMSCConstellation->insertItem("HMmix 64-QAM", 3);

	switch (TransThread.DRMTransmitter.GetParameters()->eMSCCodingScheme)
	{
	case CParameter::CS_2_SM:
		ComboBoxMSCConstellation->setCurrentItem(0);
		break;

	case CParameter::CS_3_SM:
		ComboBoxMSCConstellation->setCurrentItem(1);
		break;

	case CParameter::CS_3_HMSYM:
		ComboBoxMSCConstellation->setCurrentItem(2);
		break;

	case CParameter::CS_3_HMMIX:
		ComboBoxMSCConstellation->setCurrentItem(3);
		break;
	}

	/* SDC Constellation Scheme */
	ComboBoxSDCConstellation->insertItem("4-QAM", 0);
	ComboBoxSDCConstellation->insertItem("16-QAM", 1);

	switch (TransThread.DRMTransmitter.GetParameters()->eSDCCodingScheme)
	{
	case CParameter::CS_1_SM:
		ComboBoxSDCConstellation->setCurrentItem(0);
		break;

	case CParameter::CS_2_SM:
		ComboBoxSDCConstellation->setCurrentItem(1);
		break;
	}

	/* Service parameters --------------------------------------------------- */
	/* Service label */
	LineEditServiceLabel->setText(TransThread.DRMTransmitter.
		GetParameters()->Service[0].strLabel.c_str());

	/* Service ID */
	LineEditServiceID->setText(QString().setNum((int) TransThread.DRMTransmitter.
		GetParameters()->Service[0].iServiceID));

	/* Language */
	for (i = 0; i < LEN_TABLE_LANGUAGE_CODE; i++)
		ComboBoxLanguage->insertItem(strTableLanguageCode[i].c_str(), i);

	ComboBoxLanguage->setCurrentItem(TransThread.DRMTransmitter.
		GetParameters()->Service[0].iLanguage);

	/* Program type */
	for (i = 0; i < LEN_TABLE_PROG_TYPE_CODE; i++)
		ComboBoxProgramType->insertItem(strTableProgTypCod[i].c_str(), i);
	
	ComboBoxProgramType->setCurrentItem(TransThread.DRMTransmitter.
		GetParameters()->Service[0].iServiceDescr);

	/* Sound card IF */
	LineEditSndCrdIF->setText(QString().number(
		TransThread.DRMTransmitter.GetOFDMMod()->GetCarOffset(), 'f', 2));


	/* Disable other three services */
	TabWidgetServices->setTabEnabled(tabService2, FALSE);
	TabWidgetServices->setTabEnabled(tabService3, FALSE);
	TabWidgetServices->setTabEnabled(tabService4, FALSE);
	CheckBoxEnableService->setChecked(TRUE);
	CheckBoxEnableService->setEnabled(FALSE);


	/* Connections ---------------------------------------------------------- */
	connect(ButtonStartStop, SIGNAL(clicked()),
		this, SLOT(OnButtonStartStop()));

	/* Combo boxes */
	connect(ComboBoxMSCInterleaver, SIGNAL(highlighted(int)),
		this, SLOT(OnComboBoxMSCInterleaverHighlighted(int)));
	connect(ComboBoxMSCConstellation, SIGNAL(highlighted(int)),
		this, SLOT(OnComboBoxMSCConstellationHighlighted(int)));
	connect(ComboBoxSDCConstellation, SIGNAL(highlighted(int)),
		this, SLOT(OnComboBoxSDCConstellationHighlighted(int)));
	connect(ComboBoxLanguage, SIGNAL(highlighted(int)),
		this, SLOT(OnComboBoxLanguageHighlighted(int)));
	connect(ComboBoxProgramType, SIGNAL(highlighted(int)),
		this, SLOT(OnComboBoxProgramTypeHighlighted(int)));

	/* Button groups */
	connect(ButtonGroupRobustnessMode, SIGNAL(clicked(int)),
		this, SLOT(OnRadioRobustnessMode(int)));
	connect(ButtonGroupBandwidth, SIGNAL(clicked(int)),
		this, SLOT(OnRadioBandwidth(int)));

	/* Line edits */
	connect(LineEditServiceLabel, SIGNAL(textChanged(const QString&)),
		this, SLOT(OnTextChangedServiceLabel(const QString&)));
	connect(LineEditServiceID, SIGNAL(textChanged(const QString&)),
		this, SLOT(OnTextChangedServiceID(const QString&)));
	connect(LineEditSndCrdIF, SIGNAL(textChanged(const QString&)),
		this, SLOT(OnTextChangedSndCrdIF(const QString&)));
}

TransmDialog::~TransmDialog()
{
	/* Stop transmitter */
	if (bIsStarted == TRUE)
		TransThread.Stop();
}

void TransmDialog::OnButtonStartStop()
{
	if (bIsStarted == TRUE)
	{
		/* Stop transmitter */
		TransThread.Stop();

		ButtonStartStop->setText("&Start");

		EnableAllControls();

		bIsStarted = FALSE;
	}
	else
	{
		/* Start transmitter */
		TransThread.start();

		ButtonStartStop->setText("&Stop");

		DisableAllControls();

		bIsStarted = TRUE;
	}
}

void TransmDialog::OnTextChangedSndCrdIF(const QString& strIF)
{
	/* Convert string to floating point value "toFloat()" */
	TransThread.DRMTransmitter.GetOFDMMod()->SetCarOffset(strIF.toFloat());
}

void TransmDialog::OnTextChangedServiceID(const QString& strID)
{
	/* Convert string to unsigned integer "toUInt()" */
	TransThread.DRMTransmitter.GetParameters()->Service[0].iServiceID =
		strID.toUInt();
}

void TransmDialog::OnTextChangedServiceLabel(const QString& strLabel)
{
	/* Set additional text for log file. Conversion from QString to STL
	   string is needed (done with .latin1() function of QT string) */
	TransThread.DRMTransmitter.GetParameters()->Service[0].strLabel =
		strLabel.latin1();
}

void TransmDialog::OnComboBoxMSCInterleaverHighlighted(int iID)
{
	switch (iID)
	{
	case 0:
		TransThread.DRMTransmitter.GetParameters()->eSymbolInterlMode =
			CParameter::SI_LONG;
		break;

	case 1:
		TransThread.DRMTransmitter.GetParameters()->eSymbolInterlMode =
			CParameter::SI_SHORT;
		break;
	}
}

void TransmDialog::OnComboBoxMSCConstellationHighlighted(int iID)
{
	switch (iID)
	{
	case 0:
		TransThread.DRMTransmitter.GetParameters()->eMSCCodingScheme =
			CParameter::CS_2_SM;
		break;

	case 1:
		TransThread.DRMTransmitter.GetParameters()->eMSCCodingScheme =
			CParameter::CS_3_SM;
		break;

	case 2:
		TransThread.DRMTransmitter.GetParameters()->eMSCCodingScheme =
			CParameter::CS_3_HMSYM;
		break;

	case 3:
		TransThread.DRMTransmitter.GetParameters()->eMSCCodingScheme =
			CParameter::CS_3_HMMIX;
		break;
	}
}

void TransmDialog::OnComboBoxSDCConstellationHighlighted(int iID)
{
	switch (iID)
	{
	case 0:
		TransThread.DRMTransmitter.GetParameters()->eSDCCodingScheme =
			CParameter::CS_1_SM;
		break;

	case 1:
		TransThread.DRMTransmitter.GetParameters()->eSDCCodingScheme =
			CParameter::CS_2_SM;
		break;
	}
}

void TransmDialog::OnComboBoxLanguageHighlighted(int iID)
{
	TransThread.DRMTransmitter.GetParameters()->Service[0].iLanguage = iID;
}

void TransmDialog::OnComboBoxProgramTypeHighlighted(int iID)
{
	TransThread.DRMTransmitter.GetParameters()->Service[0].iServiceDescr = iID;
}

void TransmDialog::OnRadioRobustnessMode(int iID)
{
	/* Check, which bandwith's are possible with this robustness mode */
	switch (iID)
	{
	case 0:
		/* All bandwidth modes are possible */
		RadioButtonBandwidth45->setEnabled(TRUE);
		RadioButtonBandwidth5->setEnabled(TRUE);
		RadioButtonBandwidth9->setEnabled(TRUE);
		RadioButtonBandwidth10->setEnabled(TRUE);
		RadioButtonBandwidth18->setEnabled(TRUE);
		RadioButtonBandwidth20->setEnabled(TRUE);
		break;

	case 1:
		/* All bandwidth modes are possible */
		RadioButtonBandwidth45->setEnabled(TRUE);
		RadioButtonBandwidth5->setEnabled(TRUE);
		RadioButtonBandwidth9->setEnabled(TRUE);
		RadioButtonBandwidth10->setEnabled(TRUE);
		RadioButtonBandwidth18->setEnabled(TRUE);
		RadioButtonBandwidth20->setEnabled(TRUE);
		break;

	case 2:
		/* Only 10 and 20 kHz possible in robustness mode C */
		RadioButtonBandwidth45->setEnabled(FALSE);
		RadioButtonBandwidth5->setEnabled(FALSE);
		RadioButtonBandwidth9->setEnabled(FALSE);
		RadioButtonBandwidth10->setEnabled(TRUE);
		RadioButtonBandwidth18->setEnabled(FALSE);
		RadioButtonBandwidth20->setEnabled(TRUE);

		/* Set check on a default value to be sure we are "in range" */
		RadioButtonBandwidth10->setChecked(TRUE);
		OnRadioBandwidth(3); /* TODO better solution for that */
		break;

	case 3:
		/* Only 10 and 20 kHz possible in robustness mode D */
		RadioButtonBandwidth45->setEnabled(FALSE);
		RadioButtonBandwidth5->setEnabled(FALSE);
		RadioButtonBandwidth9->setEnabled(FALSE);
		RadioButtonBandwidth10->setEnabled(TRUE);
		RadioButtonBandwidth18->setEnabled(FALSE);
		RadioButtonBandwidth20->setEnabled(TRUE);

		/* Set check on a default value to be sure we are "in range" */
		RadioButtonBandwidth10->setChecked(TRUE);
		OnRadioBandwidth(3); /* TODO better solution for that */
		break;
	}


	/* Set new parameters */
	ERobMode eNewRobMode;

	switch (iID)
	{
	case 0:
		eNewRobMode = RM_ROBUSTNESS_MODE_A;
		break;

	case 1:
		eNewRobMode = RM_ROBUSTNESS_MODE_B;
		break;

	case 2:
		eNewRobMode = RM_ROBUSTNESS_MODE_C;
		break;

	case 3:
		eNewRobMode = RM_ROBUSTNESS_MODE_D;
		break;
	}

	/* Set new robustness mode. Spectrum occupancy is the same as before */
	TransThread.DRMTransmitter.GetParameters()->InitCellMapTable(eNewRobMode,
		TransThread.DRMTransmitter.GetParameters()->GetSpectrumOccup());
}

void TransmDialog::OnRadioBandwidth(int iID)
{
	ESpecOcc eNewSpecOcc;

	switch (iID)
	{
	case 0:
		eNewSpecOcc = SO_0;
		break;

	case 1:
		eNewSpecOcc = SO_1;
		break;

	case 2:
		eNewSpecOcc = SO_2;
		break;

	case 3:
		eNewSpecOcc = SO_3;
		break;

	case 4:
		eNewSpecOcc = SO_4;
		break;

	case 5:
		eNewSpecOcc = SO_5;
		break;
	}

	/* Set new spectrum occupancy. Robustness mode is the same as before */
	TransThread.DRMTransmitter.GetParameters()->InitCellMapTable(
		TransThread.DRMTransmitter.GetParameters()->GetWaveMode(), eNewSpecOcc);
}

void TransmDialog::DisableAllControls()
{
	ButtonGroupRobustnessMode->setEnabled(FALSE);
	ButtonGroupBandwidth->setEnabled(FALSE);
	ComboBoxMSCInterleaver->setEnabled(FALSE);
	ComboBoxMSCConstellation->setEnabled(FALSE);
	ComboBoxSDCConstellation->setEnabled(FALSE);
	LineEditServiceLabel->setEnabled(FALSE);
	LineEditServiceID->setEnabled(FALSE);
	ComboBoxLanguage->setEnabled(FALSE);
	ComboBoxProgramType->setEnabled(FALSE);
	LineEditSndCrdIF->setEnabled(FALSE);
}

void TransmDialog::EnableAllControls()
{
	ButtonGroupRobustnessMode->setEnabled(TRUE);
	ButtonGroupBandwidth->setEnabled(TRUE);
	ComboBoxMSCInterleaver->setEnabled(TRUE);
	ComboBoxMSCConstellation->setEnabled(TRUE);
	ComboBoxSDCConstellation->setEnabled(TRUE);
	LineEditServiceLabel->setEnabled(TRUE);
	LineEditServiceID->setEnabled(TRUE);
	ComboBoxLanguage->setEnabled(TRUE);
	ComboBoxProgramType->setEnabled(TRUE);
	LineEditSndCrdIF->setEnabled(TRUE);
}
