/* Dream: the encoder API is renamed so that this copy of the library can be linked
   statically next to a system fdk-aac (used for decoding) without any clash.
   Included with -include when building the library and the code that uses it. */
#ifndef ODR_SYMBOLS_H
#define ODR_SYMBOLS_H
#define aacEncOpen odr_aacEncOpen
#define aacEncClose odr_aacEncClose
#define aacEncEncode odr_aacEncEncode
#define aacEncInfo odr_aacEncInfo
#define aacEncGetLibInfo odr_aacEncGetLibInfo
#define aacEncoder_SetParam odr_aacEncoder_SetParam
#define aacEncoder_GetParam odr_aacEncoder_GetParam
#endif
