#!/bin/sh
# Symbol isolation of the vendored encoder for the qmake build (CMakeLists.txt does
# the same with odr_rename_map.cmake): all the objects are partially linked into
# one, every defined symbol except the API (odr_api.txt) is renamed with the prefix
# odrint_ and everything but the API is made local. Renaming is needed on top of
# making symbols local because inline functions are COMDAT groups, and the linker
# merges groups with the same signature across libraries, local or not.
#
# usage: odr_isolate.sh <c++ compiler> <nm> <objcopy> <odr_api.txt> <output.o> <objects...>
set -e
cxx=$1
nm=$2
objcopy=$3
api=$4
out=$5
shift 5
raw=$out.raw.o
map=$out.map
$cxx -nostdlib -r -o "$raw" "$@"
$nm --defined-only "$raw" \
  | awk 'NF==3 && $2 != "a" && $2 != "A" && substr($3, 1, 1) != "." {print $3}' \
  | sort -u | grep -vxFf "$api" \
  | awk '{print $1 " odrint_" $1}' > "$map"
$objcopy --redefine-syms="$map" --keep-global-symbols="$api" "$raw" "$out"
