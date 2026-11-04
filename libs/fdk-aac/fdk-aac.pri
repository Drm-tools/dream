# qmake include: use the vendored fdk-aac (libs/fdk-aac) instead of a system install.
# Enable with: qmake CONFIG+=vendored-fdk
#
# The CMake build of the library is run right here, while qmake runs, so that headers
# and static libraries (libfdk-aac: AAC / HE-AAC / xHE-AAC decoding, libfdk-xhe-aac:
# xHE-AAC encoder) exist before anything is compiled. They end up in
# <build dir>/fdk-aac-build/prefix. Licence: NOTICE, not GPL compatible for binary
# distribution. See README.dream.md.

FDKV_DIR = $$PWD
FDKV_BUILD = $$OUT_PWD/fdk-aac-build
FDKV_PREFIX = $$FDKV_BUILD/prefix

!exists($$FDKV_PREFIX/lib/libfdk-aac.a)|!exists($$FDKV_PREFIX/lib/libfdk-xhe-aac.a) {
    message("building the vendored fdk-aac with cmake")
    !system(cmake -S $$shell_quote($$FDKV_DIR) -B $$shell_quote($$FDKV_BUILD) -DBUILD_SHARED_LIBS=OFF -DCMAKE_BUILD_TYPE=Release -DCMAKE_POSITION_INDEPENDENT_CODE=ON -DFDK_AAC_INSTALL_CMAKE_CONFIG_MODULE=OFF -DCMAKE_INSTALL_PREFIX=$$shell_quote($$FDKV_PREFIX) > /dev/null) {
        error("cmake could not configure libs/fdk-aac")
    }
    !system(cmake --build $$shell_quote($$FDKV_BUILD) -j4 > /dev/null && cmake --install $$shell_quote($$FDKV_BUILD) > /dev/null) {
        error("cmake could not build libs/fdk-aac")
    }
}

INCLUDEPATH += $$FDKV_PREFIX/include
LIBS += -L$$FDKV_PREFIX/lib -lfdk-xhe-aac -lfdk-aac -lm
message("with the vendored fdk-aac (libs/fdk-aac)")
