/******************************************************************************\
 * British Broadcasting Corporation * Copyright (c) 2007
 *
 * Author(s):
 *	Julian Cable, Andrea Russo
 *
 * Description:
 * Settings for the receiver
 * Perhaps this should be Receiver Controls rather than Settings
 * since selections take effect immediately and there is no apply/cancel
 * feature. This makes sense, since one wants enable/disable GPS, Rig, Smeter
 * to be instant and mute/savetofile etc.
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

#include "RigDlg.h"
#include "Rig.h"

/* Implementation *************************************************************/

RigDlg::RigDlg(
    CSettings& NSettings,
    QWidget* parent, Qt::WFlags f) :
    QDialog(parent, f), Ui_RigDlg(),
    Settings(NSettings), loading(true),
    TimerRig(),iWantedrigModel(0)
{
    setupUi(this);

    checkBoxModified->setEnabled(false);

}

RigDlg::~RigDlg()
{
}

void RigDlg::showEvent(QShowEvent*)
{
    loading = true; // prevent executive actions during reading state


}

void RigDlg::hideEvent(QHideEvent*)
{
}

void
RigDlg::on_rigList_itemSelectionChanged()
{
}

void RigDlg::OnButtonTestRig()
{
}

void RigDlg::OnTimerRig()
{
}

void RigDlg::OnCheckEnableSMeterToggled(bool)
{
}
