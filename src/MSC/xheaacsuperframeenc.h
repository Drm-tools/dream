/******************************************************************************\
 * Description:
 *  DRM xHE-AAC audio super frame encoder, the inverse of XHEAACSuperFrame
 *  (ETSI ES 201 980 clause 5.3.1).
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option) any later
 * version.
\******************************************************************************/

#ifndef XHEAACSUPERFRAMEENC_H_
#define XHEAACSUPERFRAMEENC_H_

#include <cstdint>
#include <cstddef>
#include <deque>
#include <vector>

class XHEAACSuperFrameEncoder
{
public:
    XHEAACSuperFrameEncoder() : superFrameSize(0), delayedBorder(-1) {}
    void init(unsigned superFrameBytes);
    /* Queue a USAC access unit (without the audio frame CRC) */
    void push(const std::vector<uint8_t>& accessUnit);
    /* Fill one constant size super frame from the queued audio frames */
    void build(std::vector<uint8_t>& superFrame, unsigned bitReservoirLevel = 15);
    size_t queuedFrames() const { return frames.size(); }
private:
    struct Frame {
        std::vector<uint8_t> au;
        std::vector<uint8_t> out; /* access unit + CRC */
        size_t sent;
    };
    static void finalize(Frame& f);
    unsigned superFrameSize;
    int delayedBorder; /* 0xFFE/0xFFF, or -1 */
    std::deque<Frame> frames;
};

#endif
