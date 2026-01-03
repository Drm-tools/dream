/******************************************************************************\
 * Technische Universitaet Darmstadt, Institut fuer Nachrichtentechnik
 * Copyright (c) 2004
 *
 * Author(s):
 *	Volker Fischer, Stephane Fillod
 *
 * Description:
 *
 * 11/10/2004 Stephane Fillod
 *	- QT translation
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

#include <csignal>
#include <iostream>
#include <QTranslator>
#include <QThread>
#include <QApplication>
#include <QCoreApplication>
#include <QMessageBox>
#include <string>
#include "../GlobalDefinitions.h"
#include "../DrmReceiver.h"
#include "../DrmTransmitter.h"
#include "../DrmSimulation.h"
#include "../util/Settings.h"
#include "fdrmdialog.h"
#include "TransmDlg.h"
#include "DialogUtil.h"

using namespace std;

#ifdef HAVE_LIBHAMLIB
#include "../util-QT/Rig.h"
#endif
#ifdef USE_OPENSL
#include <SLES/OpenSLES.h>
SLObjectItf engineObject = nullptr;
#endif

#include "../main-Qt/crx.h"
#include "../main-Qt/ctx.h"

void guirx(CSettings &Settings, QApplication &app) {
  CDRMReceiver DRMReceiver(&Settings);

  /* First, initialize the working thread. This should be done in an extra
     routine since we cannot 100% assume that the working thread is
     ready before the GUI thread */

#ifdef HAVE_LIBHAMLIB
  CRig rig(DRMReceiver.GetParameters());
  rig.LoadSettings(Settings); // must be before DRMReceiver for G313
#endif
  CRx rx(DRMReceiver);
  class Worker: public QThread
  {
    public:
    void run() override { rx.run(); }
  };
  Worker worker;
  worker.moveToThread(&rx);
  QObject::connect(&worker, SIGNAL(finished()), &app, SLOT(quit()), Qt::QueuedConnection);

#ifdef HAVE_LIBHAMLIB
  DRMReceiver.SetTuner(&rig);

  if (DRMReceiver.GetDownstreamRSCIOutEnabled()) {
    rig.subscribe();
  }
  FDRMDialog *pMainDlg = new FDRMDialog(&rx, Settings, rig);
#else
  FDRMDialog *pMainDlg = new FDRMDialog(&rx, Settings);
#endif
  (void)pMainDlg;
  rx.LoadSettings(); // load settings after GUI initialised so LoadSettings
                     // signals get captured

  /* Start working thread */
  worker.start();

  /* Set main window */
  app.exec();

#ifdef HAVE_LIBHAMLIB
  if (DRMReceiver.GetDownstreamRSCIOutEnabled()) {
    rig.unsubscribe();
  }
  rig.SaveSettings(Settings);
#endif
  rx.SaveSettings();
}

void consolerx(CSettings &Settings, QCoreApplication &app) {

  CDRMSimulation DRMSimulation;
  DRMSimulation.SimScript();

  CDRMReceiver DRMReceiver(&Settings);
  DRMReceiver.LoadSettings();

  CRx rx(DRMReceiver);
  class Worker: public QThread
  {
    public:
    void run() override { rx.run(); }
  };
  Worker worker;
  worker.moveToThread(&rx);

  QObject::connect(&worker, SIGNAL(finished()), &app, SLOT(quit()), Qt::QueuedConnection);

  worker.start();
  app.exec(); 
  rx.SaveSettings();
}

void tx(CSettings &Settings, QCoreApplication &app, bool gui = true)
{
  CDRMTransmitter DRMTransmitter(&Settings);
  CTx tx(DRMTransmitter);
  class Worker: public QThread
  {
    public:
    void run() override { tx.run(); }
  };
  Worker worker;
  worker.moveToThread(&rx);
  QObject::connect(&worker, SIGNAL(finished()), &app, SLOT(quit()), Qt::QueuedConnection);
  if (gui) {
    TransmDialog *pMainDlg = new TransmDialog(tx);
    tx.LoadSettings(); // load settings after GUI initialised so LoadSettings
                       // signals get captured
    pMainDlg->show();
  } else {
    tx.LoadSettings();
  }
  worker.start();
  app.exec();
  tx.SaveSettings();
}

void platform_init(QCoreApplication &app) {
#ifdef _WIN32
  /* Initialize Winsock */
  WSADATA wsaData;
  (void)WSAStartup(MAKEWORD(2, 2), &wsaData);
#endif
#if defined(__APPLE__)
  /* find plugins on MacOs when deployed in a bundle */
  app.addLibraryPath(app.applicationDirPath() + "../PlugIns");
#endif
#ifdef USE_OPENSL
  (void)slCreateEngine(&engineObject, 0, nullptr, 0, nullptr, nullptr);
  (void)(*engineObject)->Realize(engineObject, SLbool_false);
#endif
#if defined(__unix__) && !defined(__APPLE__)
  /* Prevent signal interaction with popen */
  sigset_t sigset;
  sigemptyset(&sigset);
  sigaddset(&sigset, SIGPIPE);
  sigaddset(&sigset, SIGCHLD);
  pthread_sigmask(SIG_BLOCK, &sigset, nullptr);
#endif
}

int main(int argc, char **argv) {

  /* Load and install multi-language support (if available) */
  QTranslator translator(nullptr);
  CSettings Settings;

  try {

    Settings.Load(argc, argv);
    bool gui = (Settings.Get("command", "gui", string()) == "true");
    string mode = Settings.Get("command", "mode", string());

    if (gui) {
      QApplication app(argc, argv);
      platform_init(app);

      if (translator.load("dreamtr"))
        app.installTranslator(&translator);

      if (mode == "receive") {
        guirx(Settings, app);
      } else if (mode == "transmit") {
        tx(Settings, app);
      } else {
        CHelpUsage HelpUsage(Settings.UsageArguments(), argv[0]);
        app.exec();
        exit(0);
      }
    } else {
      QCoreApplication app(argc, argv);
      platform_init(app);

      if (translator.load("dreamtr"))
        app.installTranslator(&translator);

      if (mode == "receive") {
        consolerx(Settings, app);
      } else if (mode == "transmit") {
        tx(Settings, app);
      } else {
        string usage(Settings.UsageArguments());
        for (;;) {
          size_t pos = usage.find("$EXECNAME");
          if (pos == string::npos)
            break;
          usage.replace(pos, sizeof("$EXECNAME") - 1, argv[0]);
        }
        cerr << usage << endl << endl;
        exit(0);
      }
    }
  }
  catch (CGenErr GenErr) {
    qDebug("%s", GenErr.strError.c_str());
  } catch (string strError) {
    qDebug("%s", strError.c_str());
  } catch (char *Error) {
    qDebug("%s", Error);
  }

  /* Save settings to init-file */
  Settings.Save();

  return 0;
}
