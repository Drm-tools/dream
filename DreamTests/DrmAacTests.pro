# Tests for the DRM AAC / HE-AAC encoder (vendored fdk-aac, libs/fdk-aac-odr).
# Needs the system fdk-aac (3.x, for decoding with the DRM transport) found by
# pkg-config.
QT += testlib
QT -= gui
CONFIG += qt warn_on depend_includepath testcase console link_pkgconfig fdk-aac-odr
CONFIG -= app_bundle
TEMPLATE = app
TARGET = tst_drmaac
OBJECTS_DIR = obj
INCLUDEPATH += $$PWD/..
unix:LIBS += -ldl
PKGCONFIG += fdk-aac
DEFINES += HAVE_LIBFDK_AAC HAVE_USAC
packagesExist(opus) {
    PKGCONFIG += opus
    DEFINES += HAVE_LIBOPUS USE_OPUS_LIBRARY
}
include(../libs/fdk-aac-odr/fdk-aac-odr.pri)
SOURCES += tst_drmaac.cpp \
    ../src/sourcedecoders/fdk_aac_codec.cpp \
    ../src/sourcedecoders/AudioCodec.cpp \
    ../src/sourcedecoders/aac_codec.cpp \
    ../src/sourcedecoders/null_codec.cpp \
    ../src/sourcedecoders/opus_codec.cpp \
    ../src/MSC/audiosuperframe.cpp \
    ../src/SDC/audioparam.cpp \
    ../src/util/CRC.cpp
HEADERS += ../src/sourcedecoders/fdk_aac_codec.h
