# AAC, HE-AAC and xHE-AAC transmit

Dream can transmit DRM AAC, HE-AAC, HE-AAC v2 and xHE-AAC (ETSI ES 201 980 V4.3.1)
through the vendored, forked fdk-aac in `libs/fdk-aac`.

## Build

    qmake6 CONFIG+=console CONFIG+=vendored-fdk dream.pro && make

`vendored-fdk` builds `libs/fdk-aac` with cmake at qmake time (cmake required)
and links `libfdk-aac` and `libfdk-xhe-aac` statically. The codecs appear in
the GUI (Transmit dialog) and the console transmitter when the library
provides them.

The fork (github.com/rafael2k/fdk-aac, `master`) adds the DRM AAC / HE-AAC
encoder (AOT 143/144/145, 960-sample transform, HCR) and lower xHE-AAC bit
rates. See `libs/fdk-aac/README.dream.md` and `README.DRM.md`.

Licence: the Fraunhofer fdk-aac licence is not GPL compatible, so this
build is optional.

## Console transmitter

Service keys: `codec` (AAC, xHE-AAC), `audiomode` (mono | stereo | pstereo),
`sbr` (0|1), `audiosamplerate` (12000|24000|48000 where allowed). Input and
output may be "-" (stdin/stdout, stereo) or "-mono". The transmitter stops
at end of input. For IQ output use an IF of 5000 Hz or more (default 6000);
at 0 Hz the signal does not decode.

## Tested

Loopback through Dream's own receiver and the fdk decoder, 10 kHz (mode B,
SO_3, protection level 1, CS_3_SM): xHE-AAC mono, AAC mono, HE-AAC mono and
stereo, HE-AAC v2. Unit tests: `DreamTests/XheAacTests.pro` (12),
`DrmAacTests.pro` (11).

## Limits

- Nothing tested over the air or with a third-party receiver.
- xHE-AAC: independent frames about 0.85 s apart; at most 15 frames per audio
  super frame; ASF limited to 4096 bytes; minimum about 8 kbit/s mono.
- HE-AAC uses long blocks only.
- AAC / HE-AAC frame size: the encoder is capped at the payload rate (AACENC_PEAK_BITRATE). If the
  encoder still cannot fit the payload (plain AAC below about 3 kbit/s, HE-AAC below the SBR table
  minimum, 4 kbit/s mono at 12 kHz core in the vendored fdk), whole frames are dropped and a warning
  is printed. Tested down to 4.8 kbit/s mono HE-AAC (mode B, 4.5 kHz, 16-QAM, protection 0); quality
  at the lowest rates has not been assessed.
- Narrow bandwidths (4.5 / 5 kHz): the SDC with 4-QAM (`sdc=CS_1_SM`, the default) is too small for
  the xHE-AAC audio entity (type 9) and for the service label, which are then dropped (a warning is
  printed): set `sdc=CS_2_SM`. With it xHE-AAC mono decodes at mode B, 5 kHz, 16-QAM, protection 1
  (6 kbit/s). The 4.5 kHz modes have less than 6 kbit/s for audio, which the open xHE-AAC encoder
  cannot do (it rejects 4 kbit/s); use HE-AAC there.
