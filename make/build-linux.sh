#!/bin/bash


# --- using: Clang or GCC 4 ---


# make an empty directory to build in and go to it

mkdir -p obj
rm -f obj/*
cd obj


# choose compiler and set options

# Clang produces a significantly faster executable
# (the -L link-option might need changing, if llvm-ld cannot find stdc++)
if which clang++
then
   COMPILER=clang++
   LINKER=llvm-ld
   
   OPTI="-O4 -ffast-math -emit-llvm"
   LINK_OPTIONS="-L=/usr/lib/gcc/x86_64-linux-gnu/4.7.2 -l=stdc++ -native"

# default to GCC
else
   COMPILER=g++
   LINKER=g++
   
   OPTI="-O3 -ffast-math"
   LINK_OPTIONS=
fi

LANG="-x c++ -ansi -std=c++98 -pedantic -fno-enforce-eh-specs -fno-rtti"
WARN="-Wall -Wextra -Wabi -Wold-style-cast -Wsign-promo -Woverloaded-virtual -Wcast-align -Wwrite-strings -Wpointer-arith -Wcast-qual -Wconversion -Wredundant-decls -Wdisabled-optimization"
ARCH="-mfpmath=sse -msse"

COMPILE_OPTIONS="-c $LANG $OPTI $ARCH $WARN -Isrc"


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
