#!/usr/bin/env bash

mkdir build && cd build
flags="-g -O0 --coverage"
cmake -DCMAKE_CXX_COMPILER=g++-9 -DCMAKE_CXX_FLAGS="$flags" -DCMAKE_BUILD_TYPE=Debug ..
cmake --build . -- -j2
ctest -V --output-on-failure
