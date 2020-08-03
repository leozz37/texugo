#!/bin/bash

# Installing CMake
wget https://github.com/Kitware/CMake/releases/download/v3.17.3/cmake-3.17.3.tar.gz
tar xvfz cmake-$STXSVR_CMAKE_VERSION.tar.gz
cd cmake-$STXSVR_CMAKE_VERSION
./bootstrap -- -DCMAKE_USE_OPENSSL=OFF -DCXXFLAGS=gcc-7
make -j4 && make install
# Installing Nlohmann Json lib
# git clone https://github.com/nlohmann/json.git
# mkdir json/build && cd json/build
# cmake ..
# make -j2
# sudo make install
# cd ../..

# Installing Spdlog lib
# git clone https://github.com/gabime/spdlog.git
# mkdir spdlog/build && cd spdlog/build
# cmake ..
# make -j2
# sudo make install
# cd ../..

# Installing Prometheus lib
# git clone https://github.com/jupp0r/prometheus-cpp.git
# mkdir prometheus-cpp/build && cd prometheus-cpp
# git submodule init
# git submodule update
# cd build
# cmake .. -DBUILD_SHARED_LIBS=OFF
# make -j2
# sudo make install
# cd ../..

## Installing Google Test and Google Mock
# git clone https://github.com/google/googletest.git
# mkdir googletest/build && cd googletest/build
# cmake ..
# make -j2
# sudo make install
# cd ../..