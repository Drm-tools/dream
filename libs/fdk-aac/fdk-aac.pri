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

win32 {
    FDKV_LIB1 = $$FDKV_PREFIX/lib/fdk-aac.lib
    FDKV_LIB2 = $$FDKV_PREFIX/lib/fdk-xhe-aac.lib
    FDKV_NULL = NUL
    FDKV_CONFIG = --config Release
} else {
    FDKV_LIB1 = $$FDKV_PREFIX/lib/libfdk-aac.a
    FDKV_LIB2 = $$FDKV_PREFIX/lib/libfdk-xhe-aac.a
    FDKV_NULL = /dev/null
    FDKV_CONFIG =
}

!exists($$FDKV_LIB1)|!exists($$FDKV_LIB2) {
    message("building the vendored fdk-aac with cmake")
    !system(cmake -S $$shell_quote($$FDKV_DIR) -B $$shell_quote($$FDKV_BUILD) -DBUILD_SHARED_LIBS=OFF -DCMAKE_BUILD_TYPE=Release -DCMAKE_POSITION_INDEPENDENT_CODE=ON -DFDK_AAC_INSTALL_CMAKE_CONFIG_MODULE=OFF -DCMAKE_INSTALL_PREFIX=$$shell_quote($$FDKV_PREFIX) > $$FDKV_NULL) {
        error("cmake could not configure libs/fdk-aac")
    }
    !system(cmake --build $$shell_quote($$FDKV_BUILD) $$FDKV_CONFIG -j4 > $$FDKV_NULL && cmake --install $$shell_quote($$FDKV_BUILD) $$FDKV_CONFIG > $$FDKV_NULL) {
        error("cmake could not build libs/fdk-aac")
    }
}

INCLUDEPATH += $$FDKV_PREFIX/include
LIBS += -L$$FDKV_PREFIX/lib -lfdk-xhe-aac -lfdk-aac
unix:LIBS += -lm
message("with the vendored fdk-aac (libs/fdk-aac)")
