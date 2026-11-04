/* Dream: Huffman codeword reordering (HCR) for DRM AAC (ISO/IEC 14496-3 4.5.2.3).
   The encoder side of libAACdec/src/aacdec_hcr*.cpp: the codewords of one channel
   are sorted by priority, placed one per segment (priority codewords) and the
   others in the space left in the segments, set by set, trial by trial. */
#ifndef AACENC_HCR_H
#define AACENC_HCR_H

#include "common_fix.h"
#include "dyn_bits.h"

#define HCR_MAX_CODEWORDS 512
#define HCR_MAX_BITS 16383 /* 14 bit length field */

typedef struct {
  INT lengthReordered;  /* length_of_reordered_spectral_data */
  INT longestCodeword;  /* length_of_longest_codeword */
  UCHAR bits[HCR_MAX_BITS + 1]; /* the reordered spectral data, one bit per entry */
} HCR_ENC_DATA;

/* Returns 0 on success. Long blocks only. */
INT FDKaacEnc_HcrEncode(HCR_ENC_DATA *hcr, const INT *sfbOffset,
                        const SECTION_DATA *sectionData, SHORT *quantSpectrum);

#endif
