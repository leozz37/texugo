# Texugo
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/6f05bed435d94bf4ac63c0adb7675f82)](https://app.codacy.com/manual/leozz37/texugo?utm_source=github.com&utm_medium=referral&utm_content=leozz37/texugo&utm_campaign=Badge_Grade_Dashboard)
[![Build Status](https://travis-ci.com/leozz37/texugo.svg?branch=master)](https://travis-ci.com/leozz37/texugo) [![CodeFactor](https://www.codefactor.io/repository/github/leozz37/texugo/badge)](https://www.codefactor.io/repository/github/leozz37/texugo) [![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

Texugo is a simple message switch based on ZMQ and modern C++


## Features

- End-to-end system that simulates a message switching system, with ZeroMQ;
- Support to store messages on MongoDB;
- Support to spdlog;
- Support to build binary and run application on Docker;

## Installation

##### Clone this repository

`$ git clone https://github.com/leozz37/message-switch.git`

##### Create a build directory and build binary

`$ mkdir build && cd build`

`$ cmake .. && make`
