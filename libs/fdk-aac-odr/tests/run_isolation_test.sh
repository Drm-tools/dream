#!/bin/sh
# Links the isolated encoder (libdreamfdkenc.a) into one executable together with a
# static build of the other fdk-aac (decoder and the xHE-AAC encoder) and checks that
# both work: DRM AAC / HE-AAC / HE-AAC v2 are encoded with this library, the frames are
# decoded with the other one.
#
# usage: run_isolation_test.sh <libdreamfdkenc.a> <other include dir> <libfdk-aac.a> [libfdk-xhe-aac.a]
#   <other include dir> has fdk-aac/aacdecoder_lib.h (and fdk-xhe-aac/xHEAACEnc.h).
#   The static libraries have to be position independent for a PIE link, otherwise the
#   test is linked with -no-pie.
set -e
here=$(cd "$(dirname "$0")" && pwd)
odr=$here/..
lib=$1
inc=$2
fdk=$3
xhe=$4
out=${TMPDIR:-/tmp}/odr_isolation_test
mkdir -p "$out"
g++ -c -I"$odr" -I"$odr/libAACenc/include" -I"$odr/libSYS/include" "$here/iso_enc.cpp" -o "$out/iso_enc.o"
g++ -c -I"$inc" "$here/iso_dec.cpp" -o "$out/iso_dec.o"
g++ -c -I"$inc" "$here/iso_main.cpp" -o "$out/iso_main.o"
for order in 1 2; do
  if [ $order = 1 ]; then libs="$lib $fdk $xhe"; else libs="$xhe $fdk $lib"; fi
  g++ -no-pie "$out/iso_main.o" "$out/iso_enc.o" "$out/iso_dec.o" $libs -lm -o "$out/iso_test_$order"
  echo "link order $order:"
  "$out/iso_test_$order"
done
