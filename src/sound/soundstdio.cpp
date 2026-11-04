/******************************************************************************\
 * Raw sound interface on stdin / stdout. See soundstdio.h.
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option) any later
 * version.
\******************************************************************************/

#include "soundstdio.h"
#include <cstdio>
#include <vector>

using namespace std;

static bool isStdioName(const string& s) { return s == "-" || s == "-mono"; }

/* The names are only offered when asked for, so they do not clutter device lists */
static void enumerateStdio(vector<string>& names, vector<string>& descriptions, string& defaultDevice, const char* what)
{
    names.clear();
    descriptions.clear();
    if (isStdioName(defaultDevice)) {
        names.push_back(defaultDevice);
        descriptions.push_back(string(what) + (defaultDevice == "-" ? " stereo" : " mono"));
    }
}

void CSoundInStdin::Enumerate(vector<string>& names, vector<string>& descriptions, string& defaultDevice)
{
    enumerateStdio(names, descriptions, defaultDevice, "stdin raw s16le");
}

void CSoundInStdin::SetItem(string sNewDev)
{
    strName = sNewDev;
    bMono = (sNewDev == "-mono");
    bEof = false;
}

bool CSoundInStdin::Init(int, int iNewBufferSize, bool)
{
    iBufferSize = iNewBufferSize;
    return true;
}

bool CSoundInStdin::Read(CVector<short>& psData, CParameter&)
{
    const int n = psData.Size() < iBufferSize ? psData.Size() : iBufferSize; /* stereo samples */
    int got = 0;
    if (!bEof) {
        if (bMono) {
            vector<short> tmp(size_t(n / 2));
            const size_t c = fread(tmp.data(), sizeof(short), tmp.size(), stdin);
            for (size_t i = 0; i < c; i++)
                psData[int(2 * i)] = psData[int(2 * i + 1)] = tmp[i];
            got = int(2 * c);
            if (c != tmp.size()) bEof = true;
        }
        else {
            const size_t c = fread(&psData[0], sizeof(short), size_t(n), stdin);
            got = int(c);
            if (c != size_t(n)) bEof = true;
        }
    }
    for (int i = got; i < n; i++)
        psData[i] = 0;
    return false;
}

void CSoundOutStdout::Enumerate(vector<string>& names, vector<string>& descriptions, string& defaultDevice)
{
    enumerateStdio(names, descriptions, defaultDevice, "stdout raw s16le");
}

void CSoundOutStdout::SetItem(string sNewDev)
{
    strName = sNewDev;
    bMono = (sNewDev == "-mono");
}

bool CSoundOutStdout::Init(int, int, bool)
{
    return true;
}

bool CSoundOutStdout::Write(CVector<short>& psData)
{
    if (bMono) {
        vector<short> tmp(size_t(psData.Size() / 2));
        for (size_t i = 0; i < tmp.size(); i++)
            tmp[i] = short((int(psData[int(2 * i)]) + int(psData[int(2 * i + 1)])) / 2); /* downmix, not just the left channel */
        fwrite(tmp.data(), sizeof(short), tmp.size(), stdout);
    }
    else
        fwrite(&psData[0], sizeof(short), size_t(psData.Size()), stdout);
    fflush(stdout);
    return false;
}

void CSoundOutStdout::Close()
{
    fflush(stdout);
}
