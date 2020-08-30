#!/bin/bash

mkdir -p /dev/texugo/build-docker
cd /dev/texugo/build-docker
cmake ..
make -j4