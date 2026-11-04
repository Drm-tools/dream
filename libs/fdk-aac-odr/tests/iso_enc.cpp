// Encoder side of the symbol isolation test: only the vendored (ODR) headers are used here
#include "odr_symbols.h"
#include "aacenc_lib.h"
#include <cstdio>
#include <cstdlib>
#include <cmath>

int iso_encode(int aot, int sr, int ch, int br, const char* out, int nfr)
{
    HANDLE_AACENCODER h;
    if (aacEncOpen(&h, 0x01 | 0x02 | 0x04 | 0x08, ch)) return -1;
    if (aacEncoder_SetParam(h, AACENC_AOT, aot) || aacEncoder_SetParam(h, AACENC_SAMPLERATE, sr) ||
        aacEncoder_SetParam(h, AACENC_CHANNELMODE, ch == 1 ? MODE_1 : MODE_2) ||
        aacEncoder_SetParam(h, AACENC_BITRATE, br) || aacEncoder_SetParam(h, AACENC_TRANSMUX, 0)) return -2;
    if (aacEncEncode(h, 0, 0, 0, 0)) return -3;
    AACENC_InfoStruct info;
    aacEncInfo(h, &info);
    FILE* f = fopen(out, "wb");
    static INT_PCM in[8192];
    static UCHAR ob[8192];
    int n = 0;
    long t = 0;
    for (int k = 0; k < nfr + 8; k++) {
        for (unsigned i = 0; i < info.frameLength; i++, t++) {
            double v = 0.25 * sin(t * 2 * M_PI * 440.0 / sr) + 0.15 * sin(t * 2 * M_PI * 1250.0 / sr);
            for (int c = 0; c < ch; c++) in[i * ch + c] = (INT_PCM)(v * 26000);
        }
        void* ib[] = {in};
        INT ii[] = {IN_AUDIO_DATA}, is[] = {(INT)sizeof(in)}, ie[] = {2};
        void* obp[] = {ob};
        INT oi[] = {OUT_BITSTREAM_DATA}, os[] = {(INT)sizeof(ob)}, oe[] = {1};
        AACENC_BufDesc ibd = {1, ib, ii, is, ie}, obd = {1, obp, oi, os, oe};
        AACENC_InArgs ia = {(INT)(info.frameLength * info.inputChannels), 0};
        AACENC_OutArgs oa;
        if (aacEncEncode(h, &ibd, &obd, &ia, &oa)) return -4;
        if (oa.numOutBytes > 0) {
            unsigned short l = (unsigned short)oa.numOutBytes;
            fwrite(&l, 2, 1, f);
            fwrite(ob, 1, l, f);
            n++;
        }
    }
    fclose(f);
    aacEncClose(&h);
    return n;
}
