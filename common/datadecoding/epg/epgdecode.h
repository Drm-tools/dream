/******************************************************************************\
 * British Broadcasting Corporation
 * Copyright (c) 2006
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
#include "epgdec.h"
#include <qdom.h>
#include <vector>

using namespace std;

class CEPGDecoder
{
  public:
    CEPGDecoder ()
    {
    }
    void decode (const vector < _BYTE > &vecData);

    QDomDocument doc;

  protected:

    size_t attributes (QDomElement & e, uint8_t el, uint8_t * buf,
		       uint8_t * stop);
    size_t elements (QDomElement & parent, uint8_t * buf, uint8_t * stop);
    void element (QDomElement & e, uint8_t tag, uint8_t * buf, size_t len);
    size_t cdata (QDomElement & e, uint8_t * buf, uint8_t * stop);

};
