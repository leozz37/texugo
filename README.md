# Texugo

[![CodeFactor](https://www.codefactor.io/repository/github/leozz37/texugo/badge)](https://www.codefactor.io/repository/github/leozz37/texugo)
[![Codacy Badge](https://app.codacy.com/project/badge/Grade/c15c07a6a5b24b248ffe066e89d98b77)](https://www.codacy.com/manual/leozz37/texugo?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=leozz37/texugo&amp;utm_campaign=Badge_Grade)
[![Build Status](https://travis-ci.com/leozz37/texugo.svg?branch=master)](https://travis-ci.com/leozz37/texugo)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

Texugo is a simple message switch based on ZMQ and modern C++

## Features

-   End-to-end system that simulates a message switching system, with ZeroMQ;
-   TODO: Support to store messages on MongoDB;
-   Logging support with spdlog;
-   TODO: Support to build binary and run application on Docker;

## Installation

Follow these steps:

### Clone this repository

`$ git clone https://github.com/leozz37/message-switch.git`

### Create a build directory and build binary

`$ mkdir build && cd build`

`$ cmake .. && make`
