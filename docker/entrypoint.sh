#!/bin/bash

mkdir -p /dev/texugo/build
cd /dev/texugo/build
cmake ..
make -j4