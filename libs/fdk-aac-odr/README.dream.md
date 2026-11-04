# fdk-aac-odr: encoder for DRM HE-AAC (work in progress)

Encoder half of the Fraunhofer FDK AAC library (AOSP fdk-aac 2.0.3) as patched by
OpenDigitalRadio for the 960 transform (ODR-AudioEnc, commit 20d3b59, directory
`fdk-aac/`). Only the encoder and the code it needs is vendored here; decoding stays
with the system fdk-aac (the DRM xHE-AAC decoder lives in a newer fdk-aac).

Licence: `NOTICE` (Fraunhofer FDK AAC Codec licence). It is not GPL compatible for
binary distribution and does not include patent licences, so a Dream binary built with
this library must not be redistributed without sorting that out. Keep it optional.

## Build / symbol isolation

`CMakeLists.txt` builds `libdreamfdkenc.a` with hidden symbols and the API renamed with
`odr_symbols.h` (`aacEncOpen` -> `odr_aacEncOpen`, ...). Include `odr_symbols.h` first
(or `-include`) in any code that uses these headers, and never mix these headers with the
system `<fdk-aac/...>` headers in one translation unit.

## State

What the encoder does today (checked with a probe program):
- AOT 2 / 5 / 29 (AAC-LC, HE-AAC, HE-AAC v2) with `AACENC_GRANULE_LENGTH=960` at
  12 kHz and 24 kHz works, with SBR and PS.
- AOT 143 / 144 / 145 (`AOT_DRM_AAC`, `AOT_DRM_SBR`, `AOT_DRM_MPEG_PS`) are rejected by
  `aacenc_lib.cpp` (`AACENC_INVALID_CONFIG`).

What is already in the tree for DRM:
- `libFDK/src/FDK_tools_rom.cpp`: element lists `node_drm_sce` / `node_drm_cpe` (the DRM
  syntax with the CRC region markers and `esc1_hcr`), shared with the decoder.
- `libAACenc/src/bitenc.cpp`: handles `drmcrc_start_reg` / `drmcrc_end_reg`.
- `libSBRenc`: `SBR_SYNTAX_DRM_CRC` (CRC byte in front of the SBR payload).

## Missing for DRM AAC (ETSI ES 201 980 5.4)

1. `aacenc_lib.cpp`: accept the DRM AOTs: ER syntax flags (`AC_ER | AC_DRM |
   AC_SCALABLE`, VCB11, HCR, no PNS), `epConfig = 1`, frame length 960, SBR with
   `SBR_SYNTAX_DRM_CRC`.
2. HCR (Huffman codeword reordering) in the encoder: `bitenc.cpp` currently returns an
   error for `esc1_hcr` with HCR on and writes the spectral data in normal order. Needs
   `length_of_reordered_spectral_data` (14 bit), `length_of_longest_codeword` (6 bit) and
   the reordered spectral data; the inverse of `libAACdec/src/aacdec_hcr*.cpp`.
3. Frame layout: CRC byte (G8, over the `drmcrc_*` region) kept apart from the frame,
   which is what Dream's `AudioSourceEncoder` expects (`crc, frame bytes`).
4. SBR payload appended at the end of the frame in reverse bit order (clause 5.4.2),
   currently skipped for `AC_DRM` in `bitenc.cpp`.
5. Dream side: split the encoder out of `FdkAacCodec` into a translation unit that uses
   these headers, add the build option, tests (encode, parse as AAC super frame, decode
   with the fdk decoder using TT_DRM).
