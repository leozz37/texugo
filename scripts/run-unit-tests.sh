#!/bin/bash

cd $PWD/build/tests/
make -j8
ctest -V