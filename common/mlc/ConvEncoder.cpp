/******************************************************************************\
 * Technische Universitaet Darmstadt, Institut fuer Nachrichtentechnik
 * Copyright (c) 2001
 *
 * Author(s):
 *	Volker Fischer
 *
 * Description:
 *	
 *	Note: We always shift the bits towards the MSB 
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

#include "ConvEncoder.h"


/* Implementation *************************************************************/
int CConvEncoder::Encode(CVector<_BINARY>& vecInputData, 
						 CVector<_BINARY>& vecOutputData)
{
	int		iOutputCounter;
	int		iPunctCounter;
	int		iCurPunctPattern;
	_BYTE	byStateShiftReg;

	/* Set output size to zero, increment it each time a new bit is encoded */
	iOutputCounter = 0;

	/* Reset counter for puncturing and state-register */
	iPunctCounter = 0;
	byStateShiftReg = 0;


	for (int i = 0; i < iNumInBitsWithMemory; i++)
	{
		/* Prepare puncturing pattern --------------------------------------- */
		if (i < iNumInBitsPartA)
		{
			/* Puncturing patterns part A */
			/* Get current pattern */
			iCurPunctPattern = veciPuncPatPartA[iPunctCounter];

			/* Increment index and take care of wrap around */
			iPunctCounter++;
			if (iPunctCounter == iPartAPatLen)
				iPunctCounter = 0;
		}
		else
		{
			/* In case of FAC do not use special tailbit-pattern! */
			if ((i < iNumInBits) || (eChannelType == CParameter::CT_FAC))
			{
				/* Puncturing patterns part B */
				/* Reset counter when beginning of part B is reached */
				if (i == iNumInBitsPartA)
					iPunctCounter = 0;

				/* Get current pattern */
				iCurPunctPattern = veciPuncPatPartB[iPunctCounter];

				/* Increment index and take care of wrap around */
				iPunctCounter++;
				if (iPunctCounter == iPartBPatLen)
					iPunctCounter = 0;
			}
			else
			{
				/* Tailbits */
				/* Check when tailbit pattern starts */
				if (i == iNumInBits)
					iPunctCounter = 0;

				/* Set tailbit pattern */
				iCurPunctPattern = veciTailBitPat[iPunctCounter];

				/* No test for wrap around needed, since there ist only one
				   cycle of this pattern */
				iPunctCounter++;
			}
		}


		/* Update shift-register (state information) ------------------------ */
		/* Shift bits in state-shift-register */
		byStateShiftReg <<= 1;

		/* Tailbits are calculated in this loop. Check when end of vector is
		   reached and no more bits must be added */
		if (i < iNumInBits)
		{
			/* Add new bit at the beginning */
			if (vecInputData[i] == TRUE)
				byStateShiftReg |= 1;
		}


		/* Puncturing ------------------------------------------------------- */
		/* Depending on the current puncturing pattern, different numbers of
		   output bits are generated. The state shift register "byStateShiftReg"
		   is convoluted with the respective patterns for this bit (is done
		   inside the convolution function) */
		switch (iCurPunctPattern)
		{
		case PP_TYPE_0001:
			/* Pattern 0001 */
			vecOutputData[iOutputCounter++] =
				Convolution(byStateShiftReg, 0);
			break;

		case PP_TYPE_0101:
			/* Pattern 0101 */
			vecOutputData[iOutputCounter++] =
				Convolution(byStateShiftReg, 0);
	
			vecOutputData[iOutputCounter++] =
				Convolution(byStateShiftReg, 2);
			break;

		case PP_TYPE_0011:
			/* Pattern 0011 */
			vecOutputData[iOutputCounter++] =
				Convolution(byStateShiftReg, 0);
	
			vecOutputData[iOutputCounter++] =
				Convolution(byStateShiftReg, 1);
			break;

		case PP_TYPE_0111:
			/* Pattern 0111 */
			vecOutputData[iOutputCounter++] =
				Convolution(byStateShiftReg, 0);
	
			vecOutputData[iOutputCounter++] =
				Convolution(byStateShiftReg, 1);

			vecOutputData[iOutputCounter++] =
				Convolution(byStateShiftReg, 2);
			break;

		case PP_TYPE_1111:
			/* Pattern 1111 */
			vecOutputData[iOutputCounter++] =
				Convolution(byStateShiftReg, 0);
	
			vecOutputData[iOutputCounter++] =
				Convolution(byStateShiftReg, 1);

			vecOutputData[iOutputCounter++] =
				Convolution(byStateShiftReg, 2);

			vecOutputData[iOutputCounter++] =
				Convolution(byStateShiftReg, 3);
			break;
		}
	}

	/* Return number of encoded bits */
	return iOutputCounter;
}

void CConvEncoder::Init(CParameter::ECodScheme eNewCodingScheme,
						CParameter::EChanType eNewChannelType, int iN1, 
						int iN2, int iNewNumInBitsPartA,
						int iNewNumInBitsPartB, int iPunctPatPartA,
						int iPunctPatPartB, int iLevel)
{
	int i;
	int	iTailbitPattern;
	int	iTailbitParamL0;
	int	iTailbitParamL1;

	/* Set number of out bits and save channel type */
	iNumInBitsPartA = iNewNumInBitsPartA;
	eChannelType = eNewChannelType;

	/* Number of bits out is the sum of all protection levels */
	iNumInBits = iNumInBitsPartA + iNewNumInBitsPartB;

	/* Number of out bits including the state memory */
	iNumInBitsWithMemory = iNumInBits + MC_CONSTRAINT_LENGTH - 1;


	/* Set tail-bit pattern ------------------------------------------------- */
	/* We have to consider two cases because in HSYM "N1 + N2" is used
	   instead of only "N2" to calculate the tailbit pattern */
	switch (eNewCodingScheme)
	{
	case CParameter::CS_3_HMMIX:
		iTailbitParamL0 = iN1 + iN2;
		iTailbitParamL1 = iN2;
		break;

	case CParameter::CS_3_HMSYM:
		iTailbitParamL0 = 2 * (iN1 + iN2);
		iTailbitParamL1 = 2 * iN2;
		break;

	default:
		iTailbitParamL0 = 2 * iN2;
		iTailbitParamL1 = 2 * iN2;
	}

	/* Tailbit pattern calculated according DRM-standard. We have to consider
	   two cases because in HSYM "N1 + N2" is used instead of only "N2" */
	if (iLevel == 0)
		iTailbitPattern =
			iTailbitParamL0 - 12 - iPuncturingPatterns[iPunctPatPartB][1] *
			(int) ((iTailbitParamL0 - 12) /
			iPuncturingPatterns[iPunctPatPartB][1]);
	else
		iTailbitPattern =
			iTailbitParamL1 - 12 - iPuncturingPatterns[iPunctPatPartB][1] *
			(int) ((iTailbitParamL1 - 12) /
			iPuncturingPatterns[iPunctPatPartB][1]);


	/* Set puncturing bit patterns and lengths ------------------------------ */
	/* Lengths */
	iPartAPatLen = iPuncturingPatterns[iPunctPatPartA][0];
	iPartBPatLen = iPuncturingPatterns[iPunctPatPartB][0];

	/* Vector, storing patterns for part A. Patterns begin at [][2 + x] */
	veciPuncPatPartA.Init(iPartAPatLen);
	for (i = 0; i < iPartAPatLen; i++)
		veciPuncPatPartA[i] = iPuncturingPatterns[iPunctPatPartA][2 + i];

	/* Vector, storing patterns for part B. Patterns begin at [][2 + x] */
	veciPuncPatPartB.Init(iPartBPatLen);
	for (i = 0; i < iPartBPatLen; i++)
		veciPuncPatPartB[i] = iPuncturingPatterns[iPunctPatPartB][2 + i];

	/* Vector, storing patterns for tailbit pattern */
	veciTailBitPat.Init(LENGTH_TAIL_BIT_PAT);
	for (i = 0; i < LENGTH_TAIL_BIT_PAT; i++)
		veciTailBitPat[i] = iPunctPatTailbits[iTailbitPattern][i];
}

CConvEncoder::CConvEncoder()
{
#if 0
	/* Create convolution table ***********************************************/
	/* Activate this code to generate the table for convolution */
	int			i, j;
	const int	iTableSize = 1 << SIZEOF__BYTE;
	const int	iRowLen = 1 << 4;
	_BINARY		vecbiConvTable[iTableSize];

	/* Actual convolution operation */
	for (j = 0; j < iTableSize; j++)
	{
		/* XOR all bits in byResult.
		   We observe always the LSB by masking using operator "& 1". To get
		   access to all bits in "byResult" we shift the current bit so long
		   until it reaches the mask (at zero) by using operator ">> i". The
		   actual XOR operation is done by "^=" */
		vecbiConvTable[j] = FALSE;
		for (i = 0; i < MC_CONSTRAINT_LENGTH; i++)
			vecbiConvTable[j] ^= (j >> i) & 1;
	}

	/* Save table in file */
	static FILE* pFile = fopen("test/convtable.dat", "w");
	fprintf(pFile, "_BINARY vecbiConvTable[%d] = {\n", iTableSize);
	
	for (j = 0; j < iTableSize / iRowLen; j++)
	{
		fprintf(pFile, "	");

		for (i = 0; i < iRowLen; i++)
		{
			const int iCurTabIndex = j * iRowLen + i;

			fprintf(pFile, "%d", vecbiConvTable[iCurTabIndex]);

			/* No comma after last value */
			if (iCurTabIndex < iTableSize - 1)
				fprintf(pFile, ", ");
		}

		fprintf(pFile, "\n");
	}

	fprintf(pFile, "};");
	fflush(pFile);
	exit(1);
#endif
}

