# Tests for the DRM AAC / HE-AAC encoder (DRM object types of the fork of fdk-aac).
# Uses the vendored fdk-aac (libs/fdk-aac) by default; qmake CONFIG+=system-fdk uses
# the one found by pkg-config, which must have the DRM encoder.
QT += testlib
QT -= gui
CONFIG += qt warn_on depend_includepath testcase console link_pkgconfig
CONFIG -= app_bundle
TEMPLATE = app
TARGET = tst_drmaac
OBJECTS_DIR = obj
INCLUDEPATH += $$PWD/..
unix:LIBS += -ldl
DEFINES += HAVE_LIBFDK_AAC HAVE_USAC
system-fdk {
    PKGCONFIG += fdk-aac
} else {
    include(../libs/fdk-aac/fdk-aac.pri)
}
packagesExist(opus) {
    PKGCONFIG += opus
    DEFINES += HAVE_LIBOPUS USE_OPUS_LIBRARY
}
SOURCES += tst_drmaac.cpp \
    ../src/sourcedecoders/fdk_aac_codec.cpp \
    ../src/sourcedecoders/fdk_aac_enc_codec.cpp \
    ../src/sourcedecoders/AudioCodec.cpp \
    ../src/sourcedecoders/aac_codec.cpp \
    ../src/sourcedecoders/null_codec.cpp \
    ../src/sourcedecoders/opus_codec.cpp \
    ../src/MSC/audiosuperframe.cpp \
    ../src/SDC/audioparam.cpp \
    ../src/util/CRC.cpp
HEADERS += ../src/sourcedecoders/fdk_aac_codec.h ../src/sourcedecoders/fdk_aac_enc_codec.h
