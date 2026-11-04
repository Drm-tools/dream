# fdk-aac (vendored)

Copy of the `master` branch of https://github.com/rafael2k/fdk-aac, which is Martin Storsjo's
fdk-aac 3.0.0 plus:
- the xHE-AAC encoder and DRM USAC/AAC decoding support that come with that fork,
- lower minimum xHE-AAC bit rates (mono 6 kbit/s, stereo 12 kbit/s, branch
  `upstream/xhe-low-bitrate`; the same change is in `../patches/`),
- the DRM AAC / HE-AAC / HE-AAC v2 encoder (object types 143, 144, 145, 960 sample frames,
  HCR, VCB11, branch `upstream/drm-encoder`, see `README.DRM.md`).
Only the library sources are kept (no documentation, fuzzer, rust, tests, example programs,
Debian packaging).

Used for: AAC / HE-AAC / xHE-AAC decoding (libfdk-aac), the DRM AAC / HE-AAC encoder
(libfdk-aac too) and the xHE-AAC encoder (libfdk-xhe-aac). `FdkAacEncCodec` asks the linked
library at run time whether it has the DRM object types, so a stock fdk-aac just gives no
AAC encoder.

Licence: `NOTICE` (Fraunhofer FDK AAC Codec licence, with xHE-AAC encoder parts under the
Apache 2.0 licence, see the file headers). It is not GPL compatible for binary
distribution and gives no patent licence: keep this optional.

Build (what dream.pro does for CONFIG+=vendored-fdk):
    cmake -S libs/fdk-aac -B build/fdk -DBUILD_SHARED_LIBS=OFF \
          -DCMAKE_BUILD_TYPE=Release -DCMAKE_POSITION_INDEPENDENT_CODE=ON \
          -DCMAKE_INSTALL_PREFIX=build/fdk/prefix
    cmake --build build/fdk && cmake --install build/fdk
