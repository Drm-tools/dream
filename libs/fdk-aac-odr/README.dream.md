# fdk-aac-odr: DRM AAC / HE-AAC / HE-AAC v2 encoder

Encoder half of the Fraunhofer FDK AAC library (AOSP fdk-aac 2.0.3) as patched by
OpenDigitalRadio for the 960 transform (ODR-AudioEnc, commit 20d3b59, directory
`fdk-aac/`), with Dream's additions for DRM (ETSI ES 201 980 clause 5.4). Only the
encoder and the code it needs is vendored here; decoding stays with the system
fdk-aac (the DRM xHE-AAC decoder lives in a newer fdk-aac than this copy).

Licence: `NOTICE` (Fraunhofer FDK AAC Codec licence). It is not GPL compatible for
binary distribution and does not include patent licences, so a Dream binary built with
this library must not be redistributed without sorting that out. It is optional.

## Using it

    qmake CONFIG+=fdk-aac-odr dream.pro     # adds the encoder and HAVE_FDK_AAC_ODR
    # transmitter settings (Dream.ini), per service:
    #   codec=AAC  audiomode=mono|stereo|pstereo  sbr=0|1  audiosamplerate=12000|24000

`audiosamplerate` is the AAC rate of the SDC; with SBR the signal is twice that.
Stereo needs 24 kHz (spec), `pstereo` (HE-AAC v2) implies SBR. The bit rate is
whatever the multiplex leaves for the audio, as for any DRM AAC encoder.

`fdk-aac-odr.pri` does the qmake side (also used by `DreamTests/DrmAacTests.pro`).
`CMakeLists.txt` builds the same sources as a static library for experiments.

## Symbol isolation

The library is compiled with hidden symbols and its API renamed by `odr_symbols.h`
(`aacEncOpen` -> `odr_aacEncOpen`, ...), so it can sit in the same executable as the
system fdk-aac. Include `odr_symbols.h` first (or `-include`) in code that uses these
headers and never mix them with the system `<fdk-aac/...>` headers in one translation
unit (Dream's `fdk_aac_enc_codec.cpp` is the only user).

## What was added to the stock encoder

- `aacenc_lib.cpp`: AOT 143 / 144 / 145 (`AOT_DRM_AAC`, `AOT_DRM_SBR`,
  `AOT_DRM_MPEG_PS`) run on the logic of AOT 2 / 5 / 29 with the DRM syntax flags
  (ER scalable, VCB11, HCR, no PNS, epConfig 1), 960 transform and raw frames.
- `aacenc_hcr.cpp`: Huffman codeword reordering, the inverse of the decoder's
  (`libAACdec/src/aacdec_hcr*.cpp`). Long blocks only: block switching is switched off
  for DRM (`psy_main.cpp`). Codewords longer than 49 bits, or more than 14 sets, make
  the frame fail (does not happen at normal levels).
- `bitenc.cpp` / `dyn_bits.cpp`: 8 bit CRC in front of the protected region (patched
  after it), VCB11 section data (5 bit codebooks, one section per sfb for the escape
  codebook), reordered spectral data, zero stuffing, and the SBR payload at the end of
  the frame in reverse bit order with its own 8 bit CRC.
- `libSBRenc`: scalable syntax (the mono `bs_coupling` bit) and DRM CRC flags.

Frames come out as `[crc byte][frame bytes]`, which is what Dream's audio super frame
code takes. Verified against the fdk decoder with the DRM transport and through the
whole Dream transmitter / receiver chain.

## Limits

- No short blocks (transients are coded with long blocks).
- The SBR CRC is computed in `bitenc.cpp` from the final payload (the SBR encoder's
  own DRM CRC did not match the decoder's).
- Not checked against receivers other than the fdk decoder.
