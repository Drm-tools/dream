/******************************************************************************\
 * British Broadcasting Corporation
 * Copyright (c) 2006
 *
 * Author(s):
 *	Julian Cable
 *
 * Description:
 *	ETSI DAB/DRM Electronic Programme Guide XML Decompressor
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

#ifndef _EPGDEC_H
#define _EPGDEC_H
#include <stdlib.h>
#include "../../GlobalDefinitions.h"

void attr_decode (char *name, char *value,
		  uint8_t element, uint8_t attr, uint8_t * buf, size_t len);
const char *element_name (uint8_t tag);
size_t tlv (uint8_t * t, size_t * l, uint8_t ** v, uint8_t * buf);
size_t tokens (uint8_t * buf, uint8_t * stop);
size_t defaultcontent (uint8_t * buf);
void puttext (char *out, uint8_t * buf, size_t len);
#endif
