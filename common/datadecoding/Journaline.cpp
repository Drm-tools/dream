/******************************************************************************\
 * Technische Universitaet Darmstadt, Institut fuer Nachrichtentechnik
 * Copyright (c) 2001
 *
 * Author(s):
 *	Volker Fischer
 *
 * Description:
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

#include "Journaline.h"


#ifdef _WIN32
/* Implementation *************************************************************/
/* Global variables. TODO: nicer solution... */
DAB_DATAGROUP_DECODER_t	dgdec;
NEWS_SVC_DEC_decoder_t	newsdec;

/* set these to 1 for more debug information */
#ifdef WIN32
extern "C" int showDdNewsSvcDecErr = 0;
extern "C" int showDdNewsSvcDecInfo = 0;
extern "C" int showDdDabDgDecErr = 0;
extern "C" int showDdDabDgDecInfo = 0;
#else
int showDdNewsSvcDecErr = 0;
int showDdNewsSvcDecInfo = 0;
int showDdDabDgDecErr = 0;
int showDdDabDgDecInfo = 0;
#endif

/* Callback functions for journaline decoder internal tasks */
void obj_avail_cb(unsigned long, NEWS_SVC_DEC_obj_availability_t*, void*) {}
void dg_cb(const DAB_DATAGROUP_DECODER_msc_datagroup_header_t*,
	const unsigned long len, const unsigned char* buf, void*)
	{NEWS_SVC_DEC_putData(newsdec, len, buf);}

CJournaline::CJournaline()
{
	/* 1 MB memory for news decoder */
	unsigned long max_memory = 1024 * 1024;

	/* No limit for number of NML objects (except max_memory limitation) */
	unsigned long max_objects = 0;

	/* No extended header will be used */
	unsigned long extended_header_len = 0;

	/* Create decoder instance */
	dgdec = DAB_DATAGROUP_DECODER_createDec(dg_cb, NULL);
	newsdec = NEWS_SVC_DEC_createDec(obj_avail_cb, max_memory, &max_objects,
		extended_header_len, NULL);
}

CJournaline::~CJournaline()
{
// TODO: delete decoder does not work...
/*
	if (newsdec != NULL)
		NEWS_SVC_DEC_deleteDec(newsdec);

	if (dgdec != NULL)
		DAB_DATAGROUP_DECODER_deleteDec(dgdec);
*/
}

void CJournaline::AddDataUnit(CVector<_BINARY>& vecbiNewData)
{
	const int iSizeBytes = vecbiNewData.Size() / SIZEOF__BYTE;

	/* Bits to byte conversion */
	CVector<_BYTE> vecbyData(iSizeBytes);
	vecbiNewData.ResetBitAccess();

	for (int i = 0; i < iSizeBytes; i++)
		vecbyData[i] = vecbiNewData.Separate(SIZEOF__BYTE);

	/* Add new data unit to Journaline decoder library */
	DAB_DATAGROUP_DECODER_putData(dgdec, iSizeBytes, &vecbyData[0]);
}

void CJournaline::GetNews(const int iObjID, CNews& News)
{
	/* Init News object in case no object is available */
	News.sTitle = "";
	News.vecItem.Init(0);

	NML::RawNewsObject_t rno;
	unsigned long elen = 0;
	unsigned long len = 0;
	if (NEWS_SVC_DEC_get_news_object(newsdec, iObjID, &elen, &len, rno.nml))
	{
		rno.nml_len = static_cast<unsigned short>(len);
		rno.extended_header_len = static_cast<unsigned short>(elen);
		RemoveNMLEscapeSequences handler;
		NML *nml = NMLFactory::Instance()->CreateNML(rno, &handler);

		/* Title */
		News.sTitle = nml->GetTitle();

		/* Items */
		const int iNumItems = nml->GetNrOfItems();
		News.vecItem.Init(iNumItems);

		for (int i = 0; i < iNumItems; i++)
		{
			/* Text */
			News.vecItem[i].sText = nml->GetItemText(i);

			/* Link */
			if (nml->isMenu())
			{
				elen = len = 0;

				/* Check availability of linked object */
				if (NEWS_SVC_DEC_get_news_object(newsdec, nml->GetLinkId(i),
					&elen, &len, rno.nml))
				{
					News.vecItem[i].iLink = nml->GetLinkId(i);
				}
				else
					News.vecItem[i].iLink = -1; /* Not yet received */
			}
			else
				News.vecItem[i].iLink = -2; /* Not valid */
		}

		delete nml;
	}
}
#endif
