/******************************************************************************\
 * Technische Universitaet Darmstadt, Institut fuer Nachrichtentechnik
 * Copyright (c) 2004
 *
 * Author(s):
 *	Volker Fischer, Tomi Manninen, Stephane Fillod, Robert Kesterson
 *
 * Description:
 *
 * 10/03/2003 Tomi Manninen / OH2BNS
 *  - Initial (basic) code for command line argument parsing (argv)
 * 04/15/2004 Tomi Manninen, Stephane Fillod
 *  - Hamlib
 * 07/27/4002
 *  - included stlini routines written by Robert Kesterson
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

#include "Settings.h"


/* Implementation *************************************************************/
_BOOLEAN CSettings::Load(int argc, char** argv)
{
	/* First load settings from init-file and then parse command line arguments.
	   The command line arguments overwrite settings in init-file! */
	ReadIniFile();

	return ParseArguments(argc, argv);
}

void CSettings::Save()
{
	/* Just write settings in init-file */
	WriteIniFile();
}


/* Read and write init-file ***************************************************/
void CSettings::ReadIniFile()
{
	string strGetIni;
	int iValue;

	/* Load data from init-file */
	INIFile ini = LoadIni(DREAM_INIT_FILE_NAME);


	/* Flip spectrum flag --------------------------------------------------- */
	strGetIni = GetIniSetting(ini, "Receiver", "flipspectrum");
	if (!strGetIni.empty())
	{
		if (atoi(strGetIni.c_str()))
			DRMReceiver.GetReceiver()->SetFlippedSpectrum(TRUE);
		else
			DRMReceiver.GetReceiver()->SetFlippedSpectrum(FALSE);
	}


	/* Mute audio flag ------------------------------------------------------ */
	strGetIni = GetIniSetting(ini, "Receiver", "muteaudio");
	if (!strGetIni.empty())
	{
		if (atoi(strGetIni.c_str()))
			DRMReceiver.GetWriteData()->MuteAudio(TRUE);
		else
			DRMReceiver.GetWriteData()->MuteAudio(FALSE);
	}


	/* Bandpass filter flag ------------------------------------------------- */
	strGetIni = GetIniSetting(ini, "Receiver", "filter");
	if (!strGetIni.empty())
	{
		if (atoi(strGetIni.c_str()))
			DRMReceiver.GetOFDMDemod()->SetRecFilter(TRUE);
		else
			DRMReceiver.GetOFDMDemod()->SetRecFilter(FALSE);
	}


	/* Sound In device ------------------------------------------------------ */
	strGetIni = GetIniSetting(ini, "Receiver", "snddevin");
	if (!strGetIni.empty())
	{
		iValue = atoi(strGetIni.c_str());

		/* Check range */
		if ((iValue >= 0) && (iValue <= MAX_NUM_SND_DEV))
			DRMReceiver.GetSoundInterface()->SetInDev(iValue);
	}


	/* Sound Out device ----------------------------------------------------- */
	strGetIni = GetIniSetting(ini, "Receiver", "snddevout");
	if (!strGetIni.empty())
	{
		iValue = atoi(strGetIni.c_str());

		/* Check range */
		if ((iValue >= 0) && (iValue <= MAX_NUM_SND_DEV))
			DRMReceiver.GetSoundInterface()->SetOutDev(iValue);
	}


	/* Number of iterations for MLC setting --------------------------------- */
	strGetIni = GetIniSetting(ini, "Receiver", "mlciter");
	if (!strGetIni.empty())
	{
		iValue = atoi(strGetIni.c_str());

		/* Check range */
		if ((iValue >= 0) && (iValue <= MAX_NUM_MLC_IT))
			DRMReceiver.GetMSCMLC()->SetNumIterations(iValue);
	}


#ifdef USE_QT_GUI
	/* Start log file flag -------------------------------------------------- */
	strGetIni = GetIniSetting(ini, "Logfile", "startlog");
	if (!strGetIni.empty())
	{
		iValue = atoi(strGetIni.c_str());

		/* Check range */
		if ((iValue >= 0) && (iValue <= MAX_SEC_LOG_FI_START))
			DRMReceiver.GetParameters()->ReceptLog.SetDelLogStart(iValue);
	}


	/* Frequency for log file ----------------------------------------------- */
	strGetIni = GetIniSetting(ini, "Logfile", "frequency");
	if (!strGetIni.empty())
	{
		iValue = atoi(strGetIni.c_str());

		/* Check range */
		if ((iValue >= 0) && (iValue <= MAX_FREQ_LOG_FILE))
			DRMReceiver.GetParameters()->ReceptLog.SetFrequency(iValue);
	}


	/* Latitude string for log file ----------------------------------------- */
	DRMReceiver.GetParameters()->ReceptLog.SetLatitude(
		GetIniSetting(ini, "Logfile", "latitude"));


	/* Longitude string for log file ---------------------------------------- */
	DRMReceiver.GetParameters()->ReceptLog.SetLongitude(
		GetIniSetting(ini, "Logfile", "longitude"));
#endif


#ifdef HAVE_LIBHAMLIB
	/* Hamlib Model ID ------------------------------------------------------ */
	strGetIni = GetIniSetting(ini, "Hamlib", "hamlib-model");
	if (!strGetIni.empty())
	{
		iValue = atoi(strGetIni.c_str());

		/* Check range */
		if ((iValue >= 0) && (iValue <= MAX_ID_HAMLIB))
			DRMReceiver.SetHamlibModel(iValue);
	}
#endif
}

void CSettings::WriteIniFile()
{
	INIFile ini;
	char cString[256];

	/* Flip spectrum flag --------------------------------------------------- */
	if (DRMReceiver.GetReceiver()->GetFlippedSpectrum() == TRUE)
		PutIniSetting(ini, "Receiver", "flipspectrum", "1");
	else
		PutIniSetting(ini, "Receiver", "flipspectrum", "0");


	/* Mute audio flag ------------------------------------------------------ */
	if (DRMReceiver.GetWriteData()->GetMuteAudio() == TRUE)
		PutIniSetting(ini, "Receiver", "muteaudio", "1");
	else
		PutIniSetting(ini, "Receiver", "muteaudio", "0");


	/* Bandpass filter flag ------------------------------------------------- */
	if (DRMReceiver.GetOFDMDemod()->GetRecFilter() == TRUE)
		PutIniSetting(ini, "Receiver", "filter", "1");
	else
		PutIniSetting(ini, "Receiver", "filter", "0");


	/* Sound In device ------------------------------------------------------ */
	sprintf(cString, "%d", DRMReceiver.GetSoundInterface()->GetInDev());
	PutIniSetting(ini, "Receiver", "snddevin", cString);


	/* Sound Out device ----------------------------------------------------- */
	sprintf(cString, "%d", DRMReceiver.GetSoundInterface()->GetOutDev());
	PutIniSetting(ini, "Receiver", "snddevout", cString);


	/* Number of iterations for MLC setting --------------------------------- */
	sprintf(cString, "%d", DRMReceiver.GetMSCMLC()->GetInitNumIterations());
	PutIniSetting(ini, "Receiver", "mlciter", cString);


#ifdef USE_QT_GUI
	/* Start log file flag -------------------------------------------------- */
	sprintf(cString, "%d",
		DRMReceiver.GetParameters()->ReceptLog.GetDelLogStart());

	PutIniSetting(ini, "Logfile", "startlog", cString);


	/* Frequency for log file ----------------------------------------------- */
	sprintf(cString, "%d",
		DRMReceiver.GetParameters()->ReceptLog.GetFrequency());

	PutIniSetting(ini, "Logfile", "frequency", cString);


	/* Latitude string for log file ----------------------------------------- */
	PutIniSetting(ini, "Logfile", "latitude",
		DRMReceiver.GetParameters()->ReceptLog.GetLatitude().c_str());


	/* Longitude string for log file ---------------------------------------- */
	PutIniSetting(ini, "Logfile", "longitude",
		DRMReceiver.GetParameters()->ReceptLog.GetLongitude().c_str());
#endif


#ifdef HAVE_LIBHAMLIB
	/* Hamlib Model ID ------------------------------------------------------ */
	sprintf(cString, "%d", DRMReceiver.GetHamlibModel());
	PutIniSetting(ini, "Hamlib", "hamlib-model", cString);
#endif


	/* Save settings in init-file */
	SaveIni(ini, DREAM_INIT_FILE_NAME);
}


/* Command line argument parser ***********************************************/
_BOOLEAN CSettings::ParseArguments(int argc, char** argv)
{
	_BOOLEAN	bIsReceiver = TRUE;
	_REAL		rArgument;
	string		strArgument;
	_REAL		rFreqAcSeWinSize = (_REAL) 0.0;
	_REAL		rFreqAcSeWinCenter = (_REAL) 0.0;

	/* QT docu: argv()[0] is the program name, argv()[1] is the first
	   argument and argv()[argc()-1] is the last argument.
	   Start with first argument, therefore "i = 1" */
	for (int i = 1; i < argc; i++)
	{
		/* DRM transmitter mode flag ---------------------------------------- */
		if (GetFlagArgument(argc, argv, i, "-t", "--transmitter") == TRUE)
		{
			bIsReceiver = FALSE;
			continue;
		}

		
		/* Flip spectrum flag ----------------------------------------------- */
		if (GetFlagArgument(argc, argv, i, "-p", "--flipspectrum") == TRUE)
		{
			DRMReceiver.GetReceiver()->SetFlippedSpectrum(TRUE);
			continue;
		}


		/* Mute audio flag -------------------------------------------------- */
		if (GetFlagArgument(argc, argv, i, "-m", "--muteaudio") == TRUE)
		{
			DRMReceiver.GetWriteData()->MuteAudio(TRUE);
			continue;
		}


		/* Bandpass filter flag --------------------------------------------- */
		if (GetFlagArgument(argc, argv, i, "-F", "--filter") == TRUE)
		{
			DRMReceiver.GetOFDMDemod()->SetRecFilter(TRUE);
			continue;
		}


		/* Sound In device -------------------------------------------------- */
		if (GetNumericArgument(argc, argv, i, "-I", "--snddevin", 0,
			MAX_NUM_SND_DEV, rArgument) == TRUE)
		{
			DRMReceiver.GetSoundInterface()->SetInDev((int) rArgument);
			continue;
		}


		/* Sound Out device ------------------------------------------------- */
		if (GetNumericArgument(argc, argv, i, "-O", "--snddevout", 0,
			MAX_NUM_SND_DEV, rArgument) == TRUE)
		{
			DRMReceiver.GetSoundInterface()->SetOutDev((int) rArgument);
			continue;
		}


		/* Do not use sound card, read from file ---------------------------- */
		if (GetStringArgument(argc, argv, i, "-f", "--fileio",
			strArgument) == TRUE)
		{
			DRMReceiver.SetReadDRMFromFile(strArgument);
			continue;
		}


		/* Write output data to file as WAV --------------------------------- */
		if (GetStringArgument(argc, argv, i, "-w", "--writewav",
			strArgument) == TRUE)
		{
			DRMReceiver.GetWriteData()-> StartWriteWaveFile(strArgument);
			continue;
		}

		
		/* Number of iterations for MLC setting ----------------------------- */
		if (GetNumericArgument(argc, argv, i, "-i", "--mlciter", 0,
			MAX_NUM_MLC_IT,	rArgument) == TRUE)
		{
			DRMReceiver.GetMSCMLC()->SetNumIterations((int) rArgument);
			continue;
		}


		/* Sample rate offset start value ----------------------------------- */
		if (GetNumericArgument(argc, argv, i, "-s", "--sampleoff",
			MIN_SAM_OFFS_INI, MAX_SAM_OFFS_INI,	rArgument) == TRUE)
		{
			DRMReceiver.SetInitResOff(rArgument);
			continue;
		}


		/* Frequency acquisition search window size ------------------------- */
		if (GetNumericArgument(argc, argv, i, "-S", "--fracwinsize", 0,
			MAX_FREQ_AQC_SE_WIN_SI, rArgument) == TRUE)
		{
			rFreqAcSeWinSize = rArgument;
			continue;
		}

		/* Frequency acquisition search window center ----------------------- */
		if (GetNumericArgument(argc, argv, i, "-E", "--fracwincent", 0,
			MAX_FREQ_AQC_SE_WIN_CEN, rArgument) == TRUE)
		{
			rFreqAcSeWinCenter = rArgument;
			continue;
		}


#ifdef USE_QT_GUI /* QThread needed for log file timing */
		/* Start log file flag ---------------------------------------------- */
		if (GetNumericArgument(argc, argv, i, "-l", "--startlog", 1,
			MAX_SEC_LOG_FI_START, rArgument) == TRUE)
		{
			DRMReceiver.GetParameters()->ReceptLog.
				SetDelLogStart((int) rArgument);
			continue;
		}


		/* Frequency for log file ------------------------------------------- */
		if (GetNumericArgument(argc, argv, i, "-r", "--frequency", 0,
			MAX_FREQ_LOG_FILE, rArgument) == TRUE)
		{
			DRMReceiver.GetParameters()->ReceptLog.
				SetFrequency((int) rArgument);
			continue;
		}


		/* Latitude string for log file ------------------------------------- */
		if (GetStringArgument(argc, argv, i, "-a", "--latitude",
			strArgument) == TRUE)
		{
			DRMReceiver.GetParameters()->ReceptLog.SetLatitude(strArgument);
			continue;
		}


		/* Longitude string for log file ------------------------------------ */
		if (GetStringArgument(argc, argv, i, "-o", "--longitude",
			strArgument) == TRUE)
		{
			DRMReceiver.GetParameters()->ReceptLog.SetLongitude(strArgument);
			continue;
		}
#endif

#ifdef HAVE_LIBHAMLIB
		/* Hamlib Model ID -------------------------------------------------- */
		if (GetStringArgument(argc, argv, i, "-C", "--hamlib-config",
			strArgument) == TRUE)
		{
			DRMReceiver.SetHamlibConf(strArgument);
			continue;
		}


		/* Hamlib config string --------------------------------------------- */
		if (GetNumericArgument(argc, argv, i, "-M", "--hamlib-model", 0,
			MAX_ID_HAMLIB, rArgument) == TRUE)
		{
			DRMReceiver.SetHamlibModel((int) rArgument);
			continue;
		}
#endif


		/* Help (usage) flag ------------------------------------------------ */
		if ((!strcmp(argv[i], "--help")) ||
			(!strcmp(argv[i], "-h")) ||
			(!strcmp(argv[i], "-?")))
		{
			UsageArguments(argv);
			exit(1);
		}


		/* Unknown option --------------------------------------------------- */
		cerr << argv[0] << ": ";
		cerr << "Unknown option '" << argv[i] << "' -- use '--help' for help"
			<< endl;

		exit(1);
	}

	/* Set parameters for frequency acquisition search window if needed */
	if (rFreqAcSeWinSize != (_REAL) 0.0)
	{
		if (rFreqAcSeWinCenter == (_REAL) 0.0)
		{
			/* If no center was specified, set default parameter (in the
			   middle of the available spectrum) */
			rFreqAcSeWinCenter = (_REAL) SOUNDCRD_SAMPLE_RATE / 4;
		}

		/* Set new parameters */
		DRMReceiver.GetFreqSyncAcq()->SetSearchWindow(rFreqAcSeWinCenter,
			rFreqAcSeWinSize);
	}

	return bIsReceiver;
}

void CSettings::UsageArguments(char** argv)
{
// TODO: Use macro definitions for help text, too (instead of hard-coded numbers)!

	cerr << "Usage: " << argv[0] << " [option] [argument]" << endl;
	cerr << endl;
	cerr << "Recognized options:" << endl;
	cerr << endl;
	cerr << "  -t, --transmitter          DRM transmitter mode" << endl;
	cerr << "  -p, --flipspectrum         flip input spectrum" << endl;
	cerr << "  -i <n>, --mlciter <n>      number of MLC iterations" << endl;
	cerr << "                             allowed range: 0...4" << endl;
	cerr << "                             default: 1" << endl;
	cerr << "  -s <r>, --sampleoff <r>    sample rate offset initial value [Hz]"
		<< endl;
	cerr << "                             allowed range: -200.0...200.0"
		<< endl;
	cerr << "  -m, --muteaudio            mute audio output" << endl;
	cerr << "  -f <s>, --fileio <s>       disable sound card," << endl;
	cerr << "                             use file <s> instead" << endl;
	cerr << "  -w <s>, --writewav <s>     write output to wave file" << endl;

	cerr << "  -S <r>, --fracwinsize <r>  freq. acqu. search window size [Hz]"
		<< endl;
	cerr << "  -E <r>, --fracwincent <r>  freq. acqu. search window center [Hz]"
		<< endl;
	cerr << "  -F, --filter               apply bandpass filter" << endl;

#ifdef USE_QT_GUI
	cerr << "  -r <n>, --frequency <n>    set frequency [kHz] for log file"
		<< endl;
	cerr << "  -a <s>, --latitude <s>     set latitude string for log file"
		<< endl;
	cerr << "  -o <s>, --longitude <s>    set longitude string for log file"
		<< endl;
	cerr << "  -l <n>, --startlog <n>     start log file (delayed by" << endl;
	cerr << "                             <n> seconds)" << endl;
	cerr << "                             allowed range: 1...3600" << endl;
#endif

	cerr << "  -I <n>, --snddevin <n>     set sound in device" << endl;
	cerr << "  -O <n>, --snddevout <n>    set sound out device"	<< endl;

#ifdef HAVE_LIBHAMLIB
	cerr << "  -M <n>, --hamlib-model <n> set Hamlib radio model ID" << endl;
	cerr << "  -C, --hamlib-config <s>    set Hamlib config parameter" << endl;
#endif

	cerr << endl;
	cerr << "  -h, -?, --help             this help text" << endl;
	cerr << endl;
	cerr << "Example: " << argv[0] <<
		" -p --sampleoff -0.23 -i 2 "
#ifdef USE_QT_GUI
		"-r 6140 -a 50°13\\'N -o 8°34\\'E"
#endif
		<< endl;
	cerr << endl;
}

_BOOLEAN CSettings::GetFlagArgument(int argc, char** argv, int& i,
									string strShortOpt, string strLongOpt)
{
	if ((!strShortOpt.compare(argv[i])) || (!strLongOpt.compare(argv[i])))
		return TRUE;
	else
		return FALSE;
}

_BOOLEAN CSettings::GetStringArgument(int argc, char** argv, int& i,
									  string strShortOpt, string strLongOpt,
									  string& strArg)
{
	if ((!strShortOpt.compare(argv[i])) || (!strLongOpt.compare(argv[i])))
	{
		if (++i >= argc)
		{
			cerr << argv[0] << ": ";
			cerr << "'" << strLongOpt << "' needs a string argument" << endl;
			exit(1);
		}

		strArg = argv[i];

		return TRUE;
	}
	else
		return FALSE;
}

_BOOLEAN CSettings::GetNumericArgument(int argc, char** argv, int& i,
									   string strShortOpt, string strLongOpt,
									   _REAL rRangeStart, _REAL rRangeStop,
									   _REAL& rValue)
{
	if ((!strShortOpt.compare(argv[i])) || (!strLongOpt.compare(argv[i])))
	{
		if (++i >= argc)
		{
			cerr << argv[0] << ": ";
			cerr << "'" << strLongOpt << "' needs a numeric argument between "
				<< rRangeStart << " and " << rRangeStop << endl;
			exit(1);
		}

		char *p;
		rValue = strtod(argv[i], &p);
		if (*p || rValue < rRangeStart || rValue > rRangeStop)
		{
			cerr << argv[0] << ": ";
			cerr << "'" << strLongOpt << "' needs a numeric argument between "
				<< rRangeStart << " and " << rRangeStop << endl;
			exit(1);
		}

		return TRUE;
	}
	else
		return FALSE;
}


/* INI File routines using the STL ********************************************/
/* The following code was taken from "INI File Tools (STLINI)" written by
   Robert Kesterson in 1999. The original files are stlini.cpp and stlini.h.
   The homepage is http://robertk.com/source

   Copyright August 18, 1999 by Robert Kesterson */

#ifdef _MSC_VER
/* These pragmas are to quiet VC++ about the expanded template identifiers
   exceeding 255 chars. You won't be able to see those variables in a debug
   session, but the code will run normally */
#pragma warning (push)
#pragma warning (disable : 4786 4503)
#endif

string CSettings::GetIniSetting(CSettings::INIFile& theINI, const char* section,
								const char* key, const char* defaultval)
{
	string result(defaultval);
	INIFile::iterator iSection = theINI.find(string(section));

	if (iSection != theINI.end())
	{
		INISection::iterator apair = iSection->second.find(string(key));

		if (apair != iSection->second.end())
			result = apair->second;
	}

	return result;
}

void CSettings::PutIniSetting(CSettings::INIFile &theINI, const char *section,
							  const char *key, const char *value)
{
	INIFile::iterator		iniSection;
	INISection::iterator	apair;
	
	if ((iniSection = theINI.find(string(section))) == theINI.end())
	{
		/* No such section? Then add one */
		INISection newsection;
		if (key)
		{
			newsection.insert(
				std::pair<std::string, string>(string(key), string(value)));
		}

		theINI.insert(
			std::pair<string, INISection>(string(section), newsection));
	}
	else if (key)
	{	
		/* Found section, make sure key isn't in there already, 
		   if it is, just drop and re-add */
		apair = iniSection->second.find(string(key));
		if (apair != iniSection->second.end())
			iniSection->second.erase(apair);

		iniSection->second.insert(
			std::pair<string, string>(string(key), string(value)));
	}
}

CSettings::INIFile CSettings::LoadIni(const char* filename)
{
	INIFile			theINI;
	char			*value, *temp;
	string			section;
	char			buffer[MAX_INI_LINE];
	std::fstream	file(filename, std::ios::in);
	
	while (file.good())
	{
		memset(buffer, 0, sizeof(buffer));
		file.getline(buffer, sizeof(buffer));

		if ((temp = strchr(buffer, '\n')))
			*temp = '\0'; /* Cut off at newline */

		if ((temp = strchr(buffer, '\r')))
			*temp = '\0'; /* Cut off at linefeeds */

		if ((buffer[0] == '[') && (temp = strrchr(buffer, ']')))
		{   /* if line is like -->   [section name] */
			*temp = '\0'; /* Chop off the trailing ']' */
			section = &buffer[1];
			PutIniSetting(theINI, &buffer[1]); /* Start new section */
		}
		else if (buffer[0] && (value = strchr(buffer, '=')))
		{
			/* Assign whatever follows = sign to value, chop at "=" */
			*value++ = '\0';

			/* And add both sides to INISection */
			PutIniSetting(theINI, section.c_str(), buffer, value);
		}
		else if (buffer[0])
		{
			/* Must be a comment or something */
			PutIniSetting(theINI, section.c_str(), buffer, "");
		}
	}
	return theINI;
}

void CSettings::SaveIni(CSettings::INIFile &theINI, const char* filename)
{
	_BOOLEAN bFirstSection = TRUE; /* Init flag */

	std::fstream file(filename, std::ios::out);
	if(!file.good())
		return;
	
	/* Just iterate the hashes and values and dump them to a file */
	INIFile::iterator section = theINI.begin();
	while (section != theINI.end())
	{
		if (section->first > "")
		{
			if (bFirstSection == TRUE)
			{
				/* Don't put a newline at the beginning of the first section */
				file << "[" << section->first << "]" << std::endl;

				/* Reset flag */
				bFirstSection = FALSE;
			}
			else
				file << std::endl << "[" << section->first << "]" << std::endl;
		}

		INISection::iterator pair = section->second.begin();
	
		while (pair != section->second.end())
		{
			if (pair->second > "")
				file << pair->first << "=" << pair->second << std::endl;
			else
				file << pair->first << "=" << std::endl;
			pair++;
		}
		section++;
	}
	file.close();
}

/* Return true or false depending on whether the first string is less than the
   second */
bool CSettings::StlIniCompareStringNoCase::operator()(const string& x,
													  const string& y) const
{
#ifdef WIN32
	return (stricmp(x.c_str(), y.c_str()) < 0) ? true : false;
#else
#ifdef strcasecmp
	return (strcasecmp(x.c_str(), y.c_str()) < 0) ? true : false;
#else
	unsigned	nCount = 0;
	int			nResult = 0;
	const char	*p1 = x.c_str();
	const char	*p2 = y.c_str();

	while (*p1 && *p2)
	{
		nResult = toupper(*p1) - toupper(*p2);
		if (nResult != 0)
			break;
		p1++;
		p2++;
		nCount++;
	}
	if (nResult == 0)
	{
		if (*p1 && !*p2)
			nResult = -1;
		if (!*p1 && *p2)
			nResult = 1;
	}
	if (nResult < 0)
		return true;
	return false;
#endif /* strcasecmp */
#endif
}

#ifdef _MSC_VER
#pragma warning(pop)
#endif
