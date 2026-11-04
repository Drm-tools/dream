/******************************************************************************\
 * DRM xHE-AAC audio super frame encoder. See xheaacsuperframeenc.h.
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option) any later
 * version.
\******************************************************************************/

#include "xheaacsuperframeenc.h"
#include "../util/CRC.h"
#include <iostream>

using namespace std;

void XHEAACSuperFrameEncoder::init(unsigned superFrameBytes)
{
    superFrameSize = superFrameBytes;
    delayedBorder = -1;
    frames.clear();
}

void XHEAACSuperFrameEncoder::finalize(Frame& f)
{
    CCRC crc;
    crc.Reset(16);
    for (size_t i = 0; i < f.au.size(); i++)
        crc.AddByte(f.au[i]);
    const uint32_t c = crc.GetCRC();
    f.out = f.au;
    f.out.push_back(uint8_t(c >> 8));
    f.out.push_back(uint8_t(c & 0xff));
}

void XHEAACSuperFrameEncoder::push(const vector<uint8_t>& accessUnit)
{
    if (frames.size() > 64) {
        cerr << "xHE-AAC: encoder output exceeds the super frame capacity, dropping queued audio" << endl;
        frames.clear();
        delayedBorder = -1;
    }
    Frame f;
    f.au = accessUnit;
    f.sent = 0;
    finalize(f);
    frames.push_back(f);
}

void XHEAACSuperFrameEncoder::build(vector<uint8_t>& superFrame, unsigned bitReservoirLevel)
{
    vector<unsigned> borders; /* in order of appearance */
    if (delayedBorder >= 0)
        borders.push_back(unsigned(delayedBorder));
    int space = int(superFrameSize) - 2 - 2 * int(borders.size());
    delayedBorder = -1;

    vector<uint8_t> payload;
    vector<size_t> sentAtStart(frames.size());
    for (size_t i = 0; i < frames.size(); i++)
        sentAtStart[i] = frames[i].sent;

    size_t f = 0;
    while (space > 0) {
        bool exhausted = (f >= frames.size());
        if (!exhausted && frames[f].sent == 0) {
            /* a frame which has not been started yet */
            const bool canStart = borders.size() < 15 && payload.size() <= 0xffd;
            if (!canStart) {
                exhausted = true;
            }
            else if (space >= 3) {
                borders.push_back(unsigned(payload.size()));
                space -= 2;
            }
            else {
                /* 1 or 2 bytes left: the frame starts at the end of this payload, its
                   border is carried in the directory of the next super frame */
                delayedBorder = (space == 1) ? 0xfff : 0xffe;
            }
        }
        if (!exhausted) {
            Frame& fr = frames[f];
            size_t take = fr.out.size() - fr.sent;
            if (take > size_t(space)) take = size_t(space);
            payload.insert(payload.end(), fr.out.begin() + long(fr.sent), fr.out.begin() + long(fr.sent + take));
            fr.sent += take;
            space -= int(take);
            if (fr.sent == fr.out.size())
                f++;
            continue;
        }
        /* Not enough audio queued to fill the super frame: pad the last audio frame (the
           encoder is meant to do this itself with fill elements) */
        if (f > 0 && sentAtStart[f - 1] <= frames[f - 1].au.size() && payload.size() >= 2) {
            Frame& last = frames[f - 1];
            last.au.insert(last.au.end(), size_t(space), uint8_t(0));
            finalize(last);
            payload.resize(payload.size() - 2);
            payload.insert(payload.end(), size_t(space), uint8_t(0));
            payload.push_back(last.out[last.out.size() - 2]);
            payload.push_back(last.out[last.out.size() - 1]);
            last.sent = last.out.size();
        }
        else {
            /* start up, no frame to extend */
            payload.insert(payload.end(), size_t(space), uint8_t(0));
        }
        space = 0;
    }
    /* drop frames which are completely sent */
    while (!frames.empty() && frames.front().sent == frames.front().out.size())
        frames.pop_front();

    /* header */
    const unsigned count = unsigned(borders.size());
    CCRC crc;
    crc.Reset(8);
    const uint8_t h = uint8_t((count << 4) | (bitReservoirLevel & 0xf));
    crc.AddByte(h);
    superFrame.clear();
    superFrame.push_back(h);
    superFrame.push_back(uint8_t(crc.GetCRC()));
    /* payload */
    superFrame.insert(superFrame.end(), payload.begin(), payload.end());
    /* directory, last border first */
    for (size_t i = borders.size(); i-- > 0;) {
        superFrame.push_back(uint8_t(borders[i] >> 4));
        superFrame.push_back(uint8_t(((borders[i] & 0xf) << 4) | count));
    }
    if (superFrame.size() != superFrameSize)
        cerr << "xHE-AAC super frame size error: " << superFrame.size() << " != " << superFrameSize << endl;
}
