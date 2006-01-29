/******************************************************************************\
 * ?
 * Copyright (c) 2006
 *
 * Author(s):
 *	?
 *
 * Description:
 *	MJD Routines
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


#include "mjd.h"


void
MJDtoYMD (uint16_t * oyear, uint8_t * omonth, uint8_t * oday, uint32_t mjd_in)
{
    float jd, jdf, hour;
    int jdi, l, n;
    uint16_t year, month, day;

    jd = mjd_in + 2400000.5;

    jdi = (int) jd;

    jdf = jd - jdi + 0.5;

    if (jdf >= 1.0)
      {
	  jdf = jdf - 1.0;
	  jdi = jdi + 1;
      }

    hour = jdf * 24.0;
    l = jdi + 68569;
    n = 4 * l / 146097;

    l = l - ((146097 * n + 3) / 4);
    year = (uint16_t) (4000 * (l + 1) / 1461001);

    l = l - ((1461 * year / 4)) + 31;
    month = (uint8_t) (80 * l / 2447);

    day = (uint8_t) (l - (2447 * month / 80));

    l = (month / 11);

    month = (month + 2 - 12 * l);
    year = (100 * (n - 49) + year + l);

    *oyear = year;
    *omonth = month;
    *oday = day;
}
