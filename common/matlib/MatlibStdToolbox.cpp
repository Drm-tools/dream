/******************************************************************************\
 * Copyright (c) 2001
 *
 * Author(s):
 *	Volker Fischer
 *
 * Description:
 *	c++ Mathamatic Library (Matlib)
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

#include "MatlibStdToolbox.h"


/* Implementation *************************************************************/
CMatlibVector<CReal> Sort(const CMatlibVector<CReal>& rvI)
{
	CMatlibVector<CReal>	fvRet(rvI.GetSize(), VTY_TEMP);
	CReal					rSwap;

	/* Copy input vector in output vector */
	fvRet = rvI;

	/* Loop through the array one less than its total cell count */
	for(int i = 0; i < rvI.GetSize() - 1; i++)
	{
		/* Loop through every cell (value) in array */
		for(int ii = 0; ii < rvI.GetSize() - 1; ii++) 
		{
			/* Compare the values and switch if necessary */
			if (fvRet[ii] > fvRet[ii + 1]) 
			{ 
				rSwap = fvRet[ii]; 
				fvRet[ii] = fvRet[ii + 1]; 
				fvRet[ii + 1] = rSwap; 
			} 
		}
	}

	return fvRet;
}

CMatlibVector<CComplex> Fft(CMatlibVector<CComplex>& cvI, const CFftPlans& FftPlans)
{
	int						i;
	const int				n = cvI.GetSize();
	CMatlibVector<CComplex>	cvReturn(n, VTY_TEMP);
	fftw_complex*			pFftwComplexIn = new fftw_complex[n];
	fftw_complex*			pFftwComplexOut = new fftw_complex[n];

	/* fftw (Homepage: http://www.fftw.org/) */
	for (i = 0; i < n; i++)
	{
		pFftwComplexIn[i].re = cvI[i].real();
		pFftwComplexIn[i].im = cvI[i].imag();
	}

	/* Check, if plans are already created, else: create it */
	if (!FftPlans.bInitialized)
	{
		CFftPlans NewFftPlan;
		NewFftPlan.FFTPlForw = 
			fftw_create_plan(cvI.GetSize(), FFTW_FORWARD, FFTW_ESTIMATE);
	
		fftw_one(NewFftPlan.FFTPlForw, pFftwComplexIn, pFftwComplexOut);
	}
	else
		fftw_one(FftPlans.FFTPlForw, pFftwComplexIn, pFftwComplexOut);

	for (i = 0; i < n; i++)
		cvReturn[i] = CComplex(pFftwComplexOut[i].re, pFftwComplexOut[i].im);

	delete[] pFftwComplexIn;
	delete[] pFftwComplexOut;

	return cvReturn;
}

CMatlibVector<CComplex> Ifft(CMatlibVector<CComplex>& cvI, const CFftPlans& FftPlans)
{
	int						i;
	CReal					scale;

	const int				n = cvI.GetSize();
	CMatlibVector<CComplex>	cvReturn(n, VTY_TEMP);
	fftw_complex*			pFftwComplexIn = new fftw_complex[n];
	fftw_complex*			pFftwComplexOut = new fftw_complex[n];

	/* fftw (Homepage: http://www.fftw.org/) */
	for (i = 0; i < n; i++)
	{
		pFftwComplexIn[i].re = cvI[i].real();
		pFftwComplexIn[i].im = cvI[i].imag();
	}

	/* Check, if plans are already created, else: create it */
	if (!FftPlans.bInitialized)
	{
		CFftPlans NewFftPlan;
		NewFftPlan.FFTPlBackw = fftw_create_plan(n, FFTW_BACKWARD, FFTW_ESTIMATE);
	
		fftw_one(NewFftPlan.FFTPlBackw, pFftwComplexIn, pFftwComplexOut);
	}
	else
		fftw_one(FftPlans.FFTPlBackw, pFftwComplexIn, pFftwComplexOut);
	
	scale = (CReal) 1.0 / n;
	for (i = 0; i < n; i++)
		cvReturn[i] = CComplex(pFftwComplexOut[i].re * scale, 
			pFftwComplexOut[i].im * scale);

	delete[] pFftwComplexIn;
	delete[] pFftwComplexOut;

	return cvReturn;
}

CMatlibVector<CComplex> rfft(CMatlibVector<CReal>& fvI, const CFftPlans& FftPlans)
{
	int						i;
	const int				iLongLength = fvI.GetSize();
	const int				iShortLength = iLongLength / 2;
	
	CMatlibVector<CComplex>	cvReturn(iShortLength 
		/* Include nyquist frequency (+ 1) */ + 1, VTY_TEMP);

	fftw_real*				pFftwRealIn = new fftw_real[iLongLength];
	fftw_real*				pFftwRealOut = new fftw_real[iLongLength];

	/* fftw (Homepage: http://www.fftw.org/) */
	for (i = 0; i < fvI.GetSize(); i++)
		pFftwRealIn[i] = fvI[i];

	/* Check, if plans are already created, else: create it */
	if (!FftPlans.bInitialized)
	{
		CFftPlans NewFftPlan;
		NewFftPlan.RFFTPlForw = 
			rfftw_create_plan(iLongLength, FFTW_REAL_TO_COMPLEX, FFTW_ESTIMATE);
	
		rfftw_one(NewFftPlan.RFFTPlForw, pFftwRealIn, pFftwRealOut);
	}
	else
		rfftw_one(FftPlans.RFFTPlForw, pFftwRealIn, pFftwRealOut);

	/* Now build complex output-vector */
	/* Zero frequency */
	cvReturn[0] = pFftwRealOut[0];
	for (i = 1; i < iShortLength; i++)
		cvReturn[i] = CComplex(pFftwRealOut[i], pFftwRealOut[iLongLength - i]);
	/* Nyquist frequency */
	cvReturn[iShortLength] = pFftwRealOut[iShortLength];

	delete[] pFftwRealIn;
	delete[] pFftwRealOut;

	return cvReturn;
}

CMatlibVector<CReal> rifft(CMatlibVector<CComplex>& cvI, const CFftPlans& FftPlans)
{
	int			i;
	CReal		scale;

	const int	iShortLength = cvI.GetSize() - 1; /* Nyquist frequency! */
	const int	iLongLength = iShortLength * 2;

	CMatlibVector<CReal>	fvReturn(iLongLength, VTY_TEMP);
	fftw_real*				pFftwRealIn = new fftw_real[iLongLength];
	fftw_real*				pFftwRealOut = new fftw_real[iLongLength];

	/* Now build half-complex-vector */
	pFftwRealIn[0] = cvI[0].real();
	for (i = 1; i < iShortLength; i++)
	{
		pFftwRealIn[i] = cvI[i].real();
		pFftwRealIn[iLongLength - i] = cvI[i].imag();
	}
	/* Nyquist-frequency */
	pFftwRealIn[iShortLength] = cvI[iShortLength].real(); 

	/* Check, if plans are already created, else: create it */
	if (!FftPlans.bInitialized)
	{
		CFftPlans NewFftPlan;
		NewFftPlan.RFFTPlBackw = 
			rfftw_create_plan(iLongLength, FFTW_COMPLEX_TO_REAL, FFTW_ESTIMATE);
	
		rfftw_one(NewFftPlan.RFFTPlBackw, pFftwRealIn, pFftwRealOut);
	}
	else
		rfftw_one(FftPlans.RFFTPlBackw, pFftwRealIn, pFftwRealOut);

	scale = (CReal) 1.0 / iLongLength;
	for (i = 0; i < iLongLength; i++) 
		fvReturn[i] = pFftwRealOut[i] * scale;

	delete[] pFftwRealIn;
	delete[] pFftwRealOut;

	return fvReturn;
}
