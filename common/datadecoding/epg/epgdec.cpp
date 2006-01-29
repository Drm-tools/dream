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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "epgdec.h"
#include "mjd.h"

static char token_list[20][255];

static uint32_t default_content_id;

static const char *element_tags[] = {
    "",
    "",
    "epg",
    "serviceInformation",
    "tokenTableElement",
    "defaultcontentIDElement",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "shortName",
    "mediumName",
    "longName",
    "mediaDescription",
    "genre",
    "CA",
    "keywords",
    "memberOf",
    "link",
    "location",
    "shortDescription",
    "longDescription",
    "programme",
    "",
    "",
    "",
    "programmeGroups",
    "schedule",
    "alternateSource",
    "programmeGroup",
    "scope",
    "serviceScope",
    "ensemble",
    "frequency",
    "service",
    "serviceID",
    "epgLanguage",
    "multimedia",
    "time",
    "bearer",
    "programmeEvent",
    "relativeTime",
    "simulcast"
};

static const char *enums0[] = { 0, "DAB", "DRM" };
static const char *enums1[] = { 0, 0, "series",
    "show",
    "programConcept",
    "magazine",
    "programCompilation",
    "otherCollection",
    "otherChoice",
    "topic"
};
static const char *enums2[] = { 0, "URL", "DAB", "DRM" };
static const char *enums3[] = { 0, "identical", "more", "less", "similar" };
static const char *enums4[] = { 0, "primary", "alternative" };
static const char *enums5[] = { 0, "audio", "DLS",
    "MOTSlideshow", "MOTBWS", "TPEG", "DGPS", "proprietary"
};
static const char *enums6[] = { 0, "primary", "secondary" };
static const char *enums7[] = { 0, "none", "unspecified" };
static const char *enums8[] = { 0, "on-air", "off-air" };
static const char *enums9[] = { 0, "no", "yes" };
static const char *enums10[] =
    { 0, 0, "logo_unrestricted", "logo_mono_square",
    "logo_colour_square", "logo_mono_rectangle"
};
static const char *enums11[] = { 0, "main", "secondary", "other" };

typedef void (decodef) (char *out, uint8_t el, uint8_t attr, uint8_t * buf,
			size_t len);
#define NULLF ((decodef*)0)

static void
decode_genre_href (char *out, uint8_t el, uint8_t attr, uint8_t * buf,
		   size_t len)
{
    switch (len)
      {
      case 1:
	  sprintf (out, "%u", buf[0] & 0xf);
	  break;
      case 2:
	  sprintf (out, "%u.%u", buf[0] & 0xf, buf[1]);
	  break;
      case 3:
	  sprintf (out, "%u.%u.%u", buf[0] & 0xf, buf[1], buf[2]);
	  break;
      case 4:
	  sprintf (out, "%u.%u.%u.%u", buf[0] & 0xf, buf[1], buf[2], buf[3]);
	  break;
      }
}

void
puttext (char *out, uint8_t * p, size_t blen)
{
    size_t i;
    char *o = out;
    for (i = 0; i < blen; i++)
      {
	  char c = p[i];
	  if (1 <= c && c <= 19)
	      if (c == 0x9 || c == 0xa || c == 0xd)
		  *o++ = c;
	      else
		{
		    char *q = token_list[p[i]];
		    while (*q)
			*o++ = *q++;
		}
	  else
	      *o++ = c;
      }
    *o++ = 0;
}

static void
decode_string (char *out, uint8_t el, uint8_t attr, uint8_t * buf, size_t len)
{
    puttext (out, buf, len);
}

static void
decode_uint16 (char *out, uint8_t el, uint8_t attr, uint8_t * buf, size_t len)
{
    uint16_t h = buf[0], l = buf[1];
    sprintf (out, "%u", (h << 8) | l);
}

static void
decode_uint24 (char *out, uint8_t el, uint8_t attr, uint8_t * buf, size_t len)
{
    uint32_t h = buf[0], m = buf[1], l = buf[2];
    sprintf (out, "%u", (((h << 8) | m) << 8) | l);
}

static void
decode_sid (char *out, uint8_t el, uint8_t attr, uint8_t * buf, size_t len)
{
    sprintf (out, "%02x.%02x.%02x", buf[0], buf[1], buf[2]);
}

static void
decode_dateandtime (char *out, uint8_t el, uint8_t attr, uint8_t * buf,
		    size_t len)
{
    uint32_t mjd;
    uint32_t h = buf[0], m = buf[1], l = buf[2];
    uint16_t n, year;
    uint8_t month, day, hours, minutes, seconds = 0;
    int utc_flag, lto_flag, sign = 0, lto = 0;
    mjd = (((((h << 8) | m) << 8) | l) >> 6) & 0x1ffff;
    lto_flag = buf[2] & 0x10;
    utc_flag = buf[2] & 0x08;
    n = (buf[2] << 8) | buf[3];
    hours = (n >> 6) & 0x1f;
    minutes = n & 0x3f;
    n = 4;
    if (utc_flag)
      {
	  seconds = buf[n] >> 2;
	  n += 2;
      }
    if (lto_flag)
      {
	  sign = buf[n] & 0x20;
	  lto = buf[n] & 0x3f;
      }
    MJDtoYMD (&year, &month, &day, mjd);
    sprintf (out, "%04u-%02u-%02uT%02u:%02u:%02u%c%02u:%02u",
	     year, month, day, hours, minutes, seconds,
	     sign ? '-' : '+', lto / 2, (30 * lto) % 30);
}

static void
decode_duration (char *out, uint8_t el, uint8_t attr, uint8_t * buf,
		 size_t len)
{
    uint16_t h = buf[0], l = buf[1], hours, minutes, seconds;
    seconds = (h << 8) | l;
    minutes = seconds / 60;
    seconds = seconds % 60;
    hours = minutes / 60;
    minutes = minutes % 60;
    sprintf (out, "PT%uH%uM%uS", hours, minutes, seconds);
}

static void
decode_bitrate (char *out, uint8_t el, uint8_t attr, uint8_t * buf,
		size_t len)
{
    uint16_t h = buf[0], l = buf[1];
    sprintf (out, "%f", ((float) ((h << 8) | l)) / 0.1f);
}

static void decode_enum (char *out, uint8_t el, uint8_t attr, uint8_t * buf,
			 size_t len);

typedef struct
{
    const char *name;
    const char **vals;
    decodef *decode;
} dectab;

static dectab attribute_tags0[] = {
    {"system", enums0, decode_enum},
    {"id", 0, decode_string}
};

static dectab attribute_tags1[] = {
    {"version", 0, decode_uint16},
    {"creationTime", 0, decode_dateandtime},
    {"originator", 0, decode_string},
    {"serviceProvider", 0, decode_string},
    {"system", enums0, decode_enum}
};
static dectab attribute_tags2[] = {
    {"shortId", 0, decode_uint24},
    {"version", 0, decode_uint16},
    {"type", enums1, decode_enum},
    {"numOfItems", 0, decode_uint16},
};
static dectab attribute_tags3[] = {
    {"startTime", 0, decode_dateandtime},
    {"stopTime", 0, decode_dateandtime}
};
static dectab attribute_tags4[] = {
    {"protocol", enums2, decode_enum},
    {"type", enums3, decode_enum},
    {"url", 0, decode_string},
};
static dectab attribute_tags5[] = {
    {"id", 0, decode_string},
    {"version", 0, decode_uint16}
};
static dectab attribute_tags6[] = {
    {"type", enums4, decode_enum},
    {"kHz", 0, decode_uint24}
};
static dectab attribute_tags7[] = {
    {"version", 0, decode_uint16},
    {"format", enums5, decode_enum},
    {"Not used", 0, NULLF},
    {"bitrate", 0, decode_bitrate}
};
static dectab attribute_tags8[] = {
    {"id", 0, decode_string},
    {"type", enums6, decode_enum}
};
static dectab attribute_tags9[] = {
    {"xml:lang", 0, decode_string}
};
static dectab attribute_tags10[] = {
    {"mimeValue", 0, decode_string},
    {"xml:lang", 0, decode_string},
    {"url", 0, decode_string},
    {"type", enums10, decode_enum},
    {"width", 0, decode_uint16},
    {"height", 0, decode_uint16}
};
static dectab attribute_tags11[] = {
    {"time", 0, decode_dateandtime},
    {"duration", 0, decode_duration},
    {"actualTime", 0, decode_dateandtime},
    {"actualDuration", 0, decode_duration}
};
static dectab attribute_tags12[] = {
    {"id", 0, decode_sid},
    {"trigger", 0, decode_uint16}
};
static dectab attribute_tags13[] = {
    {"id", 0, decode_string},
    {"shortId", 0, decode_uint24},
    {"index", 0, decode_uint16}
};
static dectab attribute_tags14[] = {
    {"url", 0, decode_string},
    {"mimeValue", 0, decode_string},
    {"xml:lang", 0, decode_string},
    {"description", 0, decode_string},
    {"expiryTime", 0, decode_dateandtime}
};
static dectab attribute_tags15[] = {
    {"id", 0, decode_string},
    {"shortId", 0, decode_uint24},
    {"version", 0, decode_uint16},
    {"recommendation", enums9, decode_enum},
    {"broadcast", enums8, decode_enum},
    {"Not used", 0, NULLF},
    {"xml:lang", 0, decode_string},
    {"bitrate", 0, decode_string}
};
static dectab attribute_tags16[] = {
    {"href", 0, decode_genre_href},
    {"type", enums11, decode_enum}
};
static dectab attribute_tags17[] = {
    {"time", 0, decode_duration},
    {"duration", 0, decode_duration},
    {"actualTime", 0, decode_duration},
    {"actualDuration", 0, decode_duration}
};
static dectab attribute_tags18[] = {
    {"type", enums7, decode_enum}
};


const static dectab *attribute_tables[] = {
    0,
    0,
    attribute_tags0,
    attribute_tags1,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    attribute_tags6,
    attribute_tags6,
    attribute_tags6,
    0,
    attribute_tags16,
    attribute_tags18,
    attribute_tags9,
    attribute_tags13,
    attribute_tags14,
    0,
    attribute_tags6,
    attribute_tags6,
    attribute_tags15,
    0,
    0,
    0,
    attribute_tags1,
    attribute_tags1,
    attribute_tags4,
    attribute_tags2,
    attribute_tags3,
    attribute_tags12,
    attribute_tags5,
    attribute_tags6,
    attribute_tags7,
    attribute_tags8,
    attribute_tags9,
    attribute_tags10,
    attribute_tags11,
    attribute_tags12,
    attribute_tags15,
    attribute_tags17,
    attribute_tags0,
};

static const size_t attribute_table_sizes[] = {
    0,
    0,
    sizeof (attribute_tags0) / sizeof (dectab),
    sizeof (attribute_tags1) / sizeof (dectab),
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    sizeof (attribute_tags6) / sizeof (dectab),
    sizeof (attribute_tags6) / sizeof (dectab),
    sizeof (attribute_tags6) / sizeof (dectab),
    0,
    sizeof (attribute_tags16) / sizeof (dectab),
    sizeof (attribute_tags18) / sizeof (dectab),
    sizeof (attribute_tags9) / sizeof (dectab),
    sizeof (attribute_tags13) / sizeof (dectab),
    sizeof (attribute_tags14) / sizeof (dectab),
    0,
    sizeof (attribute_tags6) / sizeof (dectab),
    sizeof (attribute_tags6) / sizeof (dectab),
    sizeof (attribute_tags15) / sizeof (dectab),
    0,
    0,
    0,
    sizeof (attribute_tags1) / sizeof (dectab),
    sizeof (attribute_tags1) / sizeof (dectab),
    sizeof (attribute_tags4) / sizeof (dectab),
    sizeof (attribute_tags2) / sizeof (dectab),
    sizeof (attribute_tags3) / sizeof (dectab),
    sizeof (attribute_tags12) / sizeof (dectab),
    sizeof (attribute_tags5) / sizeof (dectab),
    sizeof (attribute_tags6) / sizeof (dectab),
    sizeof (attribute_tags7) / sizeof (dectab),
    sizeof (attribute_tags8) / sizeof (dectab),
    sizeof (attribute_tags9) / sizeof (dectab),
    sizeof (attribute_tags10) / sizeof (dectab),
    sizeof (attribute_tags11) / sizeof (dectab),
    sizeof (attribute_tags12) / sizeof (dectab),
    sizeof (attribute_tags15) / sizeof (dectab),
    sizeof (attribute_tags17) / sizeof (dectab),
    sizeof (attribute_tags0) / sizeof (dectab)
};


static void
decode_enum (char *out, uint8_t el, uint8_t attr, uint8_t * buf, size_t len)
{
    int index = buf[0];
    const char **tab = attribute_tables[el][attr].vals;
    if (tab)
      {
	  const char *s = tab[index];
	  if (s)
	      sprintf (out, "%s", s);
      }
}

size_t
tlv (uint8_t * t, size_t * l, uint8_t ** v, uint8_t * buf)
{
    size_t i = 0;
    *t = buf[i++];
    uint8_t len = buf[i++];
    uint32_t n = 0;
    switch (len)
      {
      case 0xFE:
	  n = (n << 8) | buf[i++];
	  n = (n << 8) | buf[i++];
	  *l = n;
	  break;
      case 0xFF:
	  n = (n << 8) | buf[i++];
	  n = (n << 8) | buf[i++];
	  n = (n << 8) | buf[i++];
	  *l = n;
	  break;
      default:
	  *l = len;
      }
    *v = &buf[i];
    return i;
}

size_t
tokens (uint8_t * buf, uint8_t * stop)
{
    uint8_t *p;
    uint8_t tag;
    size_t hlen, blen;
    hlen = tlv (&tag, &blen, &p, buf);
    if (tag == 4)
      {
	  size_t i = 0;
	  for (i = 0; i < 20; i++)
	      token_list[i][0] = 0;
	  for (i = 0; i < blen;)
	    {
		uint8_t tok = p[i++];
		size_t tlen = p[i++];
		memcpy (token_list[tok], &p[i], tlen);
		token_list[tok][tlen] = 0;
		i += tlen;
	    }
	  return hlen + blen;
      }
    else
	return 0;
}

size_t
defaultcontent (uint8_t * buf)
{
    uint8_t *p;
    uint8_t tag;
    size_t hlen, blen;
    hlen = tlv (&tag, &blen, &p, buf);
    if (tag == 5)
      {
	  uint32_t n = 0;
	  n = (n << 8) | p[0];
	  n = (n << 8) | p[1];
	  n = (n << 8) | p[2];
	  default_content_id = n;
	  return hlen + blen;
      }
    else
	return 0;
}

void
attr_decode (char *name, char *value, uint8_t element, uint8_t attr,
	     uint8_t * buf, size_t len)
{
    size_t e = sizeof (attribute_tables) / sizeof (dectab *);
    if (element >= e)
      {
	  fprintf (stderr, "illegal element id %u\n", element);
	  fflush (stderr);
	  strcpy (name, "unknown");
	  strcpy (value, "unknown");
	  return;
      }
    {
	const dectab *a = attribute_tables[element];
	size_t n = attribute_table_sizes[element];
	if (attr >= n)
	  {
	      fprintf (stderr, "e:%u out of range attribute id %u\n", element,
		       attr);
	      fflush (stderr);
	      strcpy (name, "unknown");
	      strcpy (value, "unknown");
	      return;
	  }
	if (a == NULL)
	  {
	      fprintf (stderr, "e:%u has no attribute id %u\n", element,
		       attr);
	      fflush (stderr);
	      strcpy (name, "unknown");
	      strcpy (value, "unknown");
	      return;
	  }
	const char *aname = a[attr].name;
	if (aname == NULL)
	  {
	      fprintf (stderr, "unknown attribute name for id %u\n", attr);
	      fflush (stderr);
	      strcpy (name, "unknown");
	      strcpy (value, "unknown");
	      return;
	  }
	if (strlen (aname) > 64)
	  {			/* some reasonably big number */
	      fprintf (stderr, "attribute name %s too long\n", aname);
	      fflush (stderr);
	      strcpy (name, "unknown");
	      strcpy (value, "unknown");
	      return;
	  }
	strcpy (name, aname);
	if (a[attr].decode)
	    a[attr].decode (value, element, attr, buf, len);
	else
	    strcpy (value, "unknown");
    }
}

const char *
element_name (uint8_t tag)
{
    return element_tags[tag];
}
