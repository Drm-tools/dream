/******************************************************************************\
 * BBC and Technische Universitaet Darmstadt, Institut fuer Nachrichtentechnik
 * Copyright (c) 2001-2019
 *
 * Author(s):
 * Volker Fischer, Julian Cable
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

#include "UpDownSample.h"
#include "../UpsampleFilter.h"
//#include "matlib/MatlibSigProToolbox.h"

using namespace std;

CUpDownSample::CUpDownSample(): iUpscaleRatio(1), iDownscaleRatio(1), iOutputBlockSize(0)
{
}

CUpDownSample::~CUpDownSample()
{
}

void CUpDownSample::ProcessData(int iStride, float *x, std::vector<float>& y)
{

    /* Upscale if ratio greater than one */
    if (iUpscaleRatio > 1)
    {
        /* The actual upscaling, currently only 2X is supported */
        InterpFIR_2X(iStride, x, y);
    }
    else if (iDownscaleRatio > 1)
    {
        /* The actual downscaling, currently only 2X is supported */
        DecimFIR_2X(iStride, x, y);
    }
    else
    {
        for (int i = 0; i < iOutputBlockSize; i++)
        {
            y[unsigned(i)] = x[iStride*i];
        }
    }

}

void CUpDownSample::Init(int iNewOutputBlockSize, int iNewUpscaleRatio, int iNewDownscaleRatio)
{
	iOutputBlockSize = iNewOutputBlockSize;
	iUpscaleRatio = iNewUpscaleRatio;
	iDownscaleRatio = iNewDownscaleRatio;
        if (iUpscaleRatio > 1)
        {
            const int taps = (NUM_TAPS_UPSAMPLE_FILT + 3) & ~3;
            vecf_Z.resize(unsigned(iOutputBlockSize + taps) / 2, 0.0f);
        }
        else if (iDownscaleRatio > 1)
        {
            const int taps = (NUM_TAPS_DOWNSAMPLE_FILT + 3) & ~3;
            vecf_B.resize(taps, 0.0f);
            for (unsigned i = 0; i < NUM_TAPS_DOWNSAMPLE_FILT; i++)
                vecf_B[i] = float(dDownsampleFilt[i] / iDownscaleRatio);
            vecf_Z.resize(unsigned(iOutputBlockSize * 2 + taps), 0.0f);
        }
        else
        {
            vecf_B.resize(0);
            vecf_Z.resize(0);
        }
}

void CUpDownSample::InterpFIR_2X(const int channels, float* X, vector<float>& Y)
{
    /*
        2X interpolating filter. When combined with CS_IQ_POS_SPLIT or CS_IQ_NEG_SPLIT
        input data mode, convert I/Q input to full bandwidth, code by David Flamand
    */
    int i, j;
    const int B_len = int(vecf_B.size());
    const int Z_len = int(vecf_Z.size());
    const int Y_len = int(Y.size());
    const int Y_len_2 = Y_len / 2;
    float *B_beg_ptr = &vecf_B[0];
    float *Z_beg_ptr = &vecf_Z[0];
    float *Y_ptr = &Y[0];
    float *B_end_ptr, *B_ptr, *Z_ptr;
    float y0, y1, y2, y3;

    /* Check for size and alignment requirement */
    if ((B_len & 3) || (Z_len != (B_len/2 + Y_len_2)) || (Y_len & 1))
        return;

    /* Copy the old history at the end */
    for (i = B_len/2-1; i >= 0; i--)
        Z_beg_ptr[Y_len_2 + i] = Z_beg_ptr[i];

    /* Copy the new sample at the beginning of the history */
    for (i = 0, j = 0; i < Y_len_2; i++, j+=channels)
        Z_beg_ptr[Y_len_2 - i - 1] = X[j];

    /* The actual lowpass filtering using FIR */
    for (i = Y_len_2-1; i >= 0; i--)
    {
        B_end_ptr  = B_beg_ptr + B_len;
        B_ptr      = B_beg_ptr;
        Z_ptr      = Z_beg_ptr + i;
        y0 = y1 = y2 = y3 = 0.0f;
        while (B_ptr != B_end_ptr)
        {
            y0 = y0 + B_ptr[0] * Z_ptr[0];
            y1 = y1 + B_ptr[1] * Z_ptr[0];
            y2 = y2 + B_ptr[2] * Z_ptr[1];
            y3 = y3 + B_ptr[3] * Z_ptr[1];
            B_ptr += 4;
            Z_ptr += 2;
        }
        *Y_ptr++ = y0 + y2;
        *Y_ptr++ = y1 + y3;
    }
}

void CUpDownSample::DecimFIR_2X(const int channels, float* X, vector<float>& Y)
{
    /*
        2X decimating filter.
    */
    int i, j;
    const int B_len = int(vecf_B.size());
    const int Z_len = int(vecf_Z.size());
    const int Y_len = int(Y.size());
    const int Y_len_2 = Y_len * 2;
    float *B_beg_ptr = &vecf_B[0];
    float *Z_beg_ptr = &vecf_Z[0];
    float *Y_ptr = &Y[0];
    float *B_end_ptr, *B_ptr, *Z_ptr;
    float y0, y1, y2, y3;

    /* Check for size and alignment requirement */
    if ((B_len & 3) || Z_len != (B_len + Y_len_2))
        return;

    /* Copy the old history at the end */
    for (i = B_len-1; i >= 0; i--)
        Z_beg_ptr[Y_len_2 + i] = Z_beg_ptr[i];

    /* Copy the new sample at the beginning of the history */
    for (i = 0, j = 0; i < Y_len_2; i++, j+=channels)
        Z_beg_ptr[Y_len_2 - i - 1] = X[j];

    /* The actual lowpass filtering using FIR */
    for (i = Y_len_2-2; i >= 0; i-=2)
    {
        B_end_ptr  = B_beg_ptr + B_len;
        B_ptr      = B_beg_ptr;
        Z_ptr      = Z_beg_ptr + i;
        y0 = y1 = y2 = y3 = 0.0f;
        while (B_ptr != B_end_ptr)
        {
            y0 = y0 + B_ptr[0] * Z_ptr[0];
            y1 = y1 + B_ptr[1] * Z_ptr[1];
            y2 = y2 + B_ptr[2] * Z_ptr[2];
            y3 = y3 + B_ptr[3] * Z_ptr[3];

            B_ptr += 4;
            Z_ptr += 4;
        }
        *Y_ptr++ = y0 + y1 + y2 + y3;
    }
}

