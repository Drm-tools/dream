# Encoder part of the Fraunhofer FDK AAC library as patched by OpenDigitalRadio
# (ODR-AudioEnc, fdk-aac/, 960 transform), with Dream's DRM additions.
#
# Built as a static library with a single exported API, renamed by odr_symbols.h
# (odr_aacEnc*, listed in odr_api.txt): all the objects are partially linked into one
# and every other global symbol is made local, so this library can be linked into the
# same executable as another copy of fdk-aac (also a static one) without symbol clashes.
#
# Licence: see NOTICE (Fraunhofer FDK AAC Codec licence, not GPL compatible for
# binary distribution, patent licences are not included).
cmake_minimum_required(VERSION 3.10)
project(dream-fdkenc C CXX)

file(GLOB SRC
  libAACenc/src/*.cpp libSBRenc/src/*.cpp libMpegTPEnc/src/*.cpp libSACenc/src/*.cpp
  libFDK/src/*.cpp libSYS/src/*.cpp libPCMutils/src/*.cpp)

add_library(dreamfdkenc_objs OBJECT ${SRC})
target_include_directories(dreamfdkenc_objs PRIVATE
  libAACenc/include libSYS/include
  libAACdec/include libMpegTPDec/include libSBRdec/include libSACdec/include
  libArithCoding/include libDRCdec/include
  libSBRenc/include libMpegTPEnc/include libSACenc/include libFDK/include libPCMutils/include)
target_compile_options(dreamfdkenc_objs PRIVATE -fno-exceptions -fno-rtti -fvisibility=hidden -fPIC
  -include ${CMAKE_CURRENT_SOURCE_DIR}/odr_symbols.h)

set(ODR_RAW ${CMAKE_CURRENT_BINARY_DIR}/odr_raw.o)
set(ODR_ISOLATED ${CMAKE_CURRENT_BINARY_DIR}/odr_isolated.o)
find_program(ODR_OBJCOPY NAMES ${CMAKE_OBJCOPY} objcopy REQUIRED)
find_program(ODR_NM NAMES ${CMAKE_NM} nm REQUIRED)
# Making the symbols local is not enough: the inline functions (fft_16, ...) are
# emitted as COMDAT groups and the linker merges groups with the same signature
# across libraries, local or not, which leaves one of the libraries with a discarded
# function. So every defined symbol except the API gets a private prefix as well.
set(ODR_MAP ${CMAKE_CURRENT_BINARY_DIR}/odr_rename.map)
add_custom_command(OUTPUT ${ODR_ISOLATED}
  COMMAND ${CMAKE_CXX_COMPILER} -nostdlib -r -o ${ODR_RAW} $<TARGET_OBJECTS:dreamfdkenc_objs>
  COMMAND ${CMAKE_COMMAND} -DNM=${ODR_NM} -DRAW=${ODR_RAW} -DAPI=${CMAKE_CURRENT_SOURCE_DIR}/odr_api.txt
          -DMAP=${ODR_MAP} -P ${CMAKE_CURRENT_SOURCE_DIR}/odr_rename_map.cmake
  COMMAND ${ODR_OBJCOPY} --redefine-syms=${ODR_MAP} --keep-global-symbols=${CMAKE_CURRENT_SOURCE_DIR}/odr_api.txt
          ${ODR_RAW} ${ODR_ISOLATED}
  DEPENDS dreamfdkenc_objs ${CMAKE_CURRENT_SOURCE_DIR}/odr_api.txt ${CMAKE_CURRENT_SOURCE_DIR}/odr_rename_map.cmake
  COMMENT "Isolating the symbols of the fdk-aac encoder"
  COMMAND_EXPAND_LISTS
  VERBATIM)
set_source_files_properties(${ODR_ISOLATED} PROPERTIES EXTERNAL_OBJECT TRUE GENERATED TRUE)

add_library(dreamfdkenc STATIC ${ODR_ISOLATED})
set_target_properties(dreamfdkenc PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(dreamfdkenc INTERFACE
  ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/libAACenc/include ${CMAKE_CURRENT_SOURCE_DIR}/libSYS/include)
