// Decoder side of the symbol isolation test: only the system (user's tree) fdk-aac headers are used here
#include <fdk-aac/aacdecoder_lib.h>
#include <cstdio>
#include <cmath>
#include <vector>

int iso_decode(const char* file, int sbr, int mode, int rate, double sr, double* a440, double* a1250)
{
    HANDLE_AACDECODER h = aacDecoder_Open(TT_DRM, 3);
    unsigned v = (0u << 14) | (unsigned(sbr) << 13) | (unsigned(mode) << 11) | (unsigned(rate) << 8);
    UCHAR cfg[2] = {(UCHAR)(v >> 8), (UCHAR)(v & 0xff)};
    UCHAR* pc = cfg;
    UINT sz = 2;
    if (aacDecoder_ConfigRaw(h, &pc, &sz) != AAC_DEC_OK) return -1;
    FILE* f = fopen(file, "rb");
    unsigned short l;
    static UCHAR fr[8192];
    static INT_PCM pcm[8192 * 2];
    int ok = 0, fi = 0;
    std::vector<double> L;
    while (fread(&l, 2, 1, f) == 1) {
        if (fread(fr, 1, l, f) != l) break;
        UCHAR* p = fr;
        UINT bs = l, valid = l;
        aacDecoder_Fill(h, &p, &bs, &valid);
        AAC_DECODER_ERROR e = aacDecoder_DecodeFrame(h, pcm, 8192 * 2, 0);
        CStreamInfo* si = aacDecoder_GetStreamInfo(h);
        if (e == AAC_DEC_OK && fi >= 8) {
            ok++;
            for (int i = 0; i < si->frameSize; i++) L.push_back(pcm[i * si->numChannels]);
        }
        fi++;
    }
    fclose(f);
    aacDecoder_Close(h);
    auto g = [&](double fq) {
        size_t from = L.size() / 3, n = L.size() - from;
        double re = 0, im = 0;
        for (size_t i = 0; i < n; i++) {
            double w = 2 * M_PI * fq * double(i + from) / sr;
            re += L[i + from] * cos(w);
            im += L[i + from] * sin(w);
        }
        return n ? 2 * sqrt(re * re + im * im) / double(n) : 0.0;
    };
    *a440 = g(440);
    *a1250 = g(1250);
    return ok;
}
