# Tests for the xHE-AAC transmit path. The encoder/decoder round trip is only run
# with the vendored fdk-aac, or with the system one (CONFIG+=system-fdk).
QT += testlib
QT -= gui
CONFIG += qt warn_on depend_includepath testcase console link_pkgconfig
CONFIG -= app_bundle
TEMPLATE = app
TARGET = tst_xheaac
INCLUDEPATH += $$PWD/..
unix:LIBS += -ldl
# vendored libs/fdk-aac by default, CONFIG+=system-fdk for the pkg-config one
system-fdk {
    packagesExist(fdk-aac) {
        PKGCONFIG += fdk-aac
        DEFINES += HAVE_LIBFDK_AAC HAVE_USAC
    }
    packagesExist(fdk-xhe-aac) {
        PKGCONFIG += fdk-xhe-aac
        DEFINES += HAVE_LIBFDK_XHE_AAC
    }
} else {
    include(../libs/fdk-aac/fdk-aac.pri)
    DEFINES += HAVE_LIBFDK_AAC HAVE_USAC HAVE_LIBFDK_XHE_AAC
}
contains(DEFINES, HAVE_LIBFDK_AAC) {
    SOURCES += ../src/sourcedecoders/fdk_aac_codec.cpp ../src/sourcedecoders/fdk_aac_enc_codec.cpp
    HEADERS += ../src/sourcedecoders/fdk_aac_codec.h ../src/sourcedecoders/fdk_aac_enc_codec.h
}
packagesExist(opus) {
    PKGCONFIG += opus
    DEFINES += HAVE_LIBOPUS USE_OPUS_LIBRARY
}
SOURCES += tst_xheaac.cpp \
    ../src/sourcedecoders/xhe_aac_codec.cpp \
    ../src/sourcedecoders/AudioCodec.cpp \
    ../src/sourcedecoders/aac_codec.cpp \
    ../src/sourcedecoders/null_codec.cpp \
    ../src/sourcedecoders/opus_codec.cpp \
    ../src/MSC/xheaacsuperframe.cpp \
    ../src/MSC/xheaacsuperframeenc.cpp \
    ../src/MSC/audiosuperframe.cpp \
    ../src/SDC/audioparam.cpp \
    ../src/util/CRC.cpp
