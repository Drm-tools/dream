# Encoder part of the Fraunhofer FDK AAC library as patched by OpenDigitalRadio
# (ODR-AudioEnc, fdk-aac/, 960 transform), with Dream's DRM additions.
# Built as a static library with hidden symbols and a renamed API (odr_symbols.h).
# Licence: see NOTICE (Fraunhofer FDK AAC Codec licence, not GPL compatible for
# binary distribution, patent licences are not included).
cmake_minimum_required(VERSION 3.10)
project(dream-fdkenc C CXX)

file(GLOB SRC
  libAACenc/src/*.cpp libSBRenc/src/*.cpp libMpegTPEnc/src/*.cpp libSACenc/src/*.cpp
  libFDK/src/*.cpp libSYS/src/*.cpp libPCMutils/src/*.cpp)

add_library(dreamfdkenc STATIC ${SRC})
target_include_directories(dreamfdkenc PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/libAACenc/include
  ${CMAKE_CURRENT_SOURCE_DIR}/libSYS/include
  PRIVATE
  libAACdec/include libMpegTPDec/include libSBRdec/include libSACdec/include
  libArithCoding/include libDRCdec/include
  libSBRenc/include libMpegTPEnc/include libSACenc/include libFDK/include libPCMutils/include)
target_compile_options(dreamfdkenc PRIVATE -fno-exceptions -fno-rtti -fvisibility=hidden -fPIC
  -include ${CMAKE_CURRENT_SOURCE_DIR}/odr_symbols.h)
