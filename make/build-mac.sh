#!/bin/bash


# --- using: LLVM-GCC 4.2 or GCC 4 (for 64-bit) ---


# make an empty directory to build in, and go to it

mkdir -p obj
rm -f obj/*
cd obj


# choose compiler and set options

# if llvm-gcc is available:
COMPILER=/Developer/usr/bin/llvm-g++
LINKER=/Developer/usr/bin/llvm-g++
#OPTI="-O4 -ffast-math"   # still won't work
OPTI="-O3 -ffast-math"
# or use gcc:
#COMPILER=g++
#LINKER=g++
#OPTI="-O3 -ffast-math"

LANG="-x c++ -ansi -std=c++98 -pedantic -fno-enforce-eh-specs -fno-rtti"
WARN="-Wall -Wextra -Wabi -Wold-style-cast -Wsign-promo -Woverloaded-virtual -Wstrict-null-sentinel -Wcast-align -Wwrite-strings -Wpointer-arith -Wcast-qual -Wconversion -Wredundant-decls -Wdisabled-optimization"
CPU="-arch x86_64"
ARCH=""

COMPILE_OPTIONS="-c $LANG $OPTI $CPU $ARCH $WARN -Isrc"
LINK_OPTIONS=$CPU


# compile and link

echo
$COMPILER --version

$COMPILER $COMPILE_OPTIONS ../src/*.cpp

$LINKER $LINK_OPTIONS -o minilight-cpp *.o


# move executable and return from build directory

mv minilight-cpp ..
cd ..
rm obj/*


exit
