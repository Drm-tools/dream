# qmake include: builds the vendored fdk-aac encoder (libs/fdk-aac-odr) into the
# project and adds the Dream codec that uses it (HAVE_FDK_AAC_ODR).
#
# The library is kept apart from the system fdk-aac (used for decoding): its API
# is renamed (odr_symbols.h) and its symbols are hidden, so both can live in one
# executable. Licence: NOTICE in this directory, not GPL compatible for binary
# distribution. See README.dream.md.

ODR_DIR = $$PWD
ODR_ROOT = $$PWD/../..
DEFINES += HAVE_FDK_AAC_ODR
INCLUDEPATH += $$ODR_DIR $$ODR_DIR/libAACenc/include $$ODR_DIR/libSYS/include
HEADERS += $$ODR_ROOT/src/sourcedecoders/fdk_aac_enc_codec.h
SOURCES += $$ODR_ROOT/src/sourcedecoders/fdk_aac_enc_codec.cpp

ODR_SOURCES = $$files($$ODR_DIR/libAACenc/src/*.cpp) $$files($$ODR_DIR/libSBRenc/src/*.cpp) \
              $$files($$ODR_DIR/libMpegTPEnc/src/*.cpp) $$files($$ODR_DIR/libSACenc/src/*.cpp) \
              $$files($$ODR_DIR/libFDK/src/*.cpp) $$files($$ODR_DIR/libSYS/src/*.cpp) \
              $$files($$ODR_DIR/libPCMutils/src/*.cpp)
ODR_INCLUDES = -I$$ODR_DIR/libAACenc/include -I$$ODR_DIR/libAACdec/include -I$$ODR_DIR/libMpegTPDec/include \
               -I$$ODR_DIR/libSBRdec/include -I$$ODR_DIR/libSACdec/include -I$$ODR_DIR/libArithCoding/include \
               -I$$ODR_DIR/libDRCdec/include -I$$ODR_DIR/libSBRenc/include -I$$ODR_DIR/libMpegTPEnc/include \
               -I$$ODR_DIR/libSACenc/include -I$$ODR_DIR/libFDK/include -I$$ODR_DIR/libPCMutils/include \
               -I$$ODR_DIR/libSYS/include
ODR_OBJDIR = $$OBJECTS_DIR
isEmpty(ODR_OBJDIR): ODR_OBJDIR = .

odr.input = ODR_SOURCES
# not named .o, so that qmake does not link the single objects: only the isolated one is
odr.output = $${ODR_OBJDIR}/${QMAKE_FILE_BASE}.odrobj
odr.commands = $$QMAKE_CXX -c $(CXXFLAGS) $(INCPATH) $$ODR_INCLUDES -fno-exceptions -fno-rtti -fvisibility=hidden -include $$ODR_DIR/odr_symbols.h -o ${QMAKE_FILE_OUT} ${QMAKE_FILE_NAME}
odr.dependency_type = TYPE_C
odr.variable_out = ODR_UNLINKED
odr.name = fdk-aac-odr ${QMAKE_FILE_IN}
QMAKE_EXTRA_COMPILERS += odr

# partial link + symbol isolation of all those objects into one (odr_isolate.sh)
for(src, ODR_SOURCES) {
    obj = $$basename(src)
    obj ~= s/\.cpp$/.odrobj/
    ODR_OBJS += $${ODR_OBJDIR}/$$obj
}
ODR_ISOLATED_OBJ = $${ODR_OBJDIR}/odr_isolated.o
odriso.target = $$ODR_ISOLATED_OBJ
odriso.depends = $$ODR_OBJS
odriso.commands = sh $$ODR_DIR/odr_isolate.sh $$QMAKE_CXX nm objcopy $$ODR_DIR/odr_api.txt $$ODR_ISOLATED_OBJ $$ODR_OBJS
QMAKE_EXTRA_TARGETS += odriso
OBJECTS += $$ODR_ISOLATED_OBJ
message("with fdk-aac-odr (DRM AAC / HE-AAC encoder)")
