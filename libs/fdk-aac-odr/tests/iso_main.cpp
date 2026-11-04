// One executable with the isolated ODR encoder, the user's static fdk-aac decoder and the static xHE encoder
#include <cstdio>
#if __has_include(<fdk-xhe-aac/xHEAACEnc.h>)
#include <fdk-xhe-aac/xHEAACEnc.h>
#define HAVE_XHE 1
#endif

int iso_encode(int aot, int sr, int ch, int br, const char* out, int nfr);
int iso_decode(const char* file, int sbr, int mode, int rate, double sr, double* a440, double* a1250);

int main()
{
    struct { int aot, sr, ch, br, sbr, mode, rate; } t[] = {
        {143, 24000, 1, 24000, 0, 0, 3},
        {144, 24000, 1, 12000, 1, 0, 1},
        {144, 48000, 2, 32000, 1, 2, 3},
        {145, 24000, 2, 12000, 1, 1, 1},
    };
    int bad = 0;
    for (auto& c : t) {
        int n = iso_encode(c.aot, c.sr, c.ch, c.br, "/tmp/iso_test.bin", 100);
        double a440 = 0, a1250 = 0;
        int ok = iso_decode("/tmp/iso_test.bin", c.sbr, c.mode, c.rate, c.sr, &a440, &a1250);
        printf("aot %d %d Hz %d ch %d bit/s: %d frames encoded, %d decoded, 440 Hz %.0f 1250 Hz %.0f\n",
               c.aot, c.sr, c.ch, c.br, n, ok, a440, a1250);
        if (n < 100 || ok < 90 || a440 < 5000 || a1250 < 3000) bad++;
    }
#ifdef HAVE_XHE
    printf("xHE encoder (static, same executable): %s\n", IIS_xHEAACEnc_GetVersionInfoStr());
#endif
    printf(bad ? "FAILED\n" : "all ok\n");
    return bad;
}
