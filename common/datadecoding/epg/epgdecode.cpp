/******************************************************************************\
 * British Broadcasting Corporation
 * Copyright (c) 2005
 *
 * Author(s):
 *	Julian Cable
 *
 * Description:
 *	ETSI DAB/DRM Electronic Programme Guide XML Decoder for Dream
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

#include "epgdecode.h"
#include <qtextstream.h>
#include <iostream>

void
CEPGDecoder::decode (const vector < _BYTE > &vecData)
{
    /* clear the doc, allowing re-use */
    doc.setContent (QString (""));
    QDomElement root = doc.createElement ("root");
    size_t n = vecData.size ();
    uint8_t *buf = const_cast < uint8_t * >(&vecData.front ());
    elements (root, buf, buf + n);
    doc.appendChild (root.firstChild ());
}

size_t
CEPGDecoder::attributes (QDomElement & e, uint8_t el, uint8_t * buf,
			 uint8_t * stop)
{
    uint8_t tag;
    size_t hlen, blen, len = 0;
    uint8_t *p, *q = buf;
    while (q < stop)
      {
	  q = &buf[len];
	  hlen = tlv (&tag, &blen, &p, q);
	  if (tag & 0x80)
	    {
		uint8_t attr = tag & 0x0f;
		char name[256], value[16384];
		attr_decode (name, value, el, attr, p, blen);
		e.setAttribute (name, QString ().fromUtf8 (value));
		len += hlen + blen;
	    }
	  else
	    {
		break;
	    }
      }
    return len;
}

size_t
CEPGDecoder::cdata (QDomElement & e, uint8_t * buf, uint8_t * stop)
{
    uint8_t *p;
    uint8_t tag;
    size_t hlen, blen;
    hlen = tlv (&tag, &blen, &p, buf);
    if (tag == 1)
      {
	  char value[16384];
	  puttext (value, p, blen);
	  QDomText t = doc.createTextNode (QString ().fromUtf8 (value));
	  e.appendChild (t);
	  return hlen + blen;
      }
    else
	return 0;
}

void
CEPGDecoder::element (QDomElement & e, uint8_t tag, uint8_t * buf, size_t len)
{
    uint8_t *p = buf, *q = buf + len;
    size_t a;
    switch (tag)
      {
      case 4:
      case 5:
	  break;
      default:
	  a = attributes (e, tag, p, q);
	  p += a;
	  if (p >= q)
	      return;
	  if (tag == 2 || tag == 3)
	    {
		p += tokens (p, q);
		p += defaultcontent (p);
	    }
	  if (p >= q)
	      return;
	  p += elements (e, p, q);
	  if (p >= q)
	      return;
	  p += cdata (e, p, q);
      }
}

size_t
CEPGDecoder::elements (QDomElement & parent, uint8_t * buf, uint8_t * stop)
{
    uint8_t tag;
    size_t hlen, blen, len = 0;
    uint8_t *p, *q = buf;
    while (q < stop)
      {
	  hlen = tlv (&tag, &blen, &p, q);
	  switch (tag)
	    {
	    case 0:
	    case 1:
	    case 4:
	    case 5:
		return len;
		break;
	    default:
		QString name (element_name (tag));
		QDomElement elem = doc.createElement (name);
		element (elem, tag, p, blen);
		parent.appendChild (elem);
		len += hlen + blen;
	    }
	  q = &buf[len];
      }
    return len;
}
