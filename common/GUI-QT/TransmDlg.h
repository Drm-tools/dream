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


#include <qpushbutton.h>

#ifdef _WIN32
# include "../../Windows/moc/TransmDlgbase.h"
#else
# include "moc/TransmDlgbase.h"
#endif
#include "../DrmTransmitter.h"


/* Classes ********************************************************************/
/* Thread class for the transmitter */
class CTransmitterThread : public QThread 
{
public:
	void Stop()
	{
		/* Stop working thread and wait until it is ready for terminating. We
		   set a time-out of 5 seconds */
		DRMTransmitter.Stop();

		if (wait(5000) == FALSE)
			ErrorMessage("Termination of sound interface thread failed.");
	}

	virtual void run()
	{
		/* Set thread priority (The working thread should have a higher priority
		   than the GUI) */
#ifdef _WIN32
		SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_ABOVE_NORMAL);
#endif

		try
		{
			/* Call receiver main routine */
			DRMTransmitter.Start();
		}

		catch (CGenErr GenErr)
		{
			ErrorMessage(GenErr.strError);
		}
	}

protected:
	CDRMTransmitter	DRMTransmitter;
};

class TransmDialog : public TransmDlgBase
{
	Q_OBJECT

public:
	TransmDialog(QWidget* parent = 0, const char* name = 0, bool modal = FALSE,
		WFlags f = 0);
	virtual ~TransmDialog();

protected:
	CTransmitterThread	TransThread; /* Working thread object */
	_BOOLEAN			bIsStarted;

public slots:
	void OnButtonStartStop();
};
