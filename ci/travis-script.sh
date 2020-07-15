#!/usr/bin/env bash

if [ "$COVERITY_SCAN_BRANCH" == 1 ]; then
  cat /home/travis/build/leokolln/cppaikit/cov-int/scm_log.txt
  exit
fi

if [ "$IS_COVERAGE_BUILD" == 1 ]; then
  flags="-g -O0 --coverage"
  cmake -DCMAKE_CXX_COMPILER=$COMPILER -DCMAKE_CXX_FLAGS="$flags" -DCMAKE_BUILD_TYPE=Debug .
else
  mkdir build && cd build
  CXX=/usr/bin/g++-9 CC=/usr/bin/gcc-9 cmake ..
fi

cmake --build . -- -j2
ctest -V --output-on-failure