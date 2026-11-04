# fdk-aac (vendored)

Copy of https://github.com/rafael2k/fdk-aac, branch `xhe-low-bitrate` (commit 235baef),
which is Martin Storsjo's fdk-aac 3.0.0 with the xHE-AAC encoder and DRM USAC/AAC decoding
support plus a configuration table change that lowers the minimum xHE-AAC bit rate
(mono 6 kbit/s, stereo 12 kbit/s; the same change is in `../patches/`).
Only the library sources are kept (no documentation, fuzzer, rust, tests, example programs).

Used for: AAC / HE-AAC / xHE-AAC decoding (libfdk-aac) and the xHE-AAC encoder
(libfdk-xhe-aac). The DRM HE-AAC *encoder* is the separate `../fdk-aac-odr`.

Licence: `NOTICE` (Fraunhofer FDK AAC Codec licence, with xHE-AAC encoder parts under the
Apache 2.0 licence, see the file headers). It is not GPL compatible for binary
distribution and gives no patent licence: keep this optional.

Build (what dream.pro does for CONFIG+=vendored-fdk):
    cmake -S libs/fdk-aac -B build/fdk -DBUILD_SHARED_LIBS=OFF \
          -DCMAKE_BUILD_TYPE=Release -DCMAKE_POSITION_INDEPENDENT_CODE=ON \
          -DCMAKE_INSTALL_PREFIX=build/fdk/prefix
    cmake --build build/fdk && cmake --install build/fdk
