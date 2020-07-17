# Texugo

[![CodeFactor](https://www.codefactor.io/repository/github/leozz37/texugo/badge)](https://www.codefactor.io/repository/github/leozz37/texugo)
[![Codacy Badge](https://app.codacy.com/project/badge/Grade/c15c07a6a5b24b248ffe066e89d98b77)](https://www.codacy.com/manual/leozz37/texugo?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=leozz37/texugo&amp;utm_campaign=Badge_Grade)
[![Build Status](https://travis-ci.com/leozz37/texugo.svg?branch=master)](https://travis-ci.com/leozz37/texugo)
[![Coverage Status](https://coveralls.io/repos/github/leozz37/texugo/badge.svg?branch=master)](https://coveralls.io/github/leozz37/texugo?branch=master)
[![Documentation](https://codedocs.xyz/leozz37/texugo.svg)](https://codedocs.xyz/leozz37/texugo/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

Texugo is a flexible multiplatform server message switch and gateway using Modern C++ based on TCP/IP and MQ.

## Features

-   End-to-end system that process messages, supporting [RabbitMQ](https://www.rabbitmq.com/) and [Boost.ASIO](https://www.boost.org/doc/libs/1_66_0/doc/html/boost_asio.html);
-   Flexible port binding;
-   Reliably serve devices across multiple networks;
-   Storing messages and logs on [MongoDB](https://www.mongodb.com/) (or [MongoDB Atlas](https://www.mongodb.com/cloud/atlas));
-   Logging support with [spdlog](https://github.com/gabime/spdlog);
-   Metrics monitoring with [Prometheus](https://prometheus.io/);
-   Data visualization with [Grafana](https://grafana.com/);
-   TODO: Support to build and run the binary on [Docker](https://www.docker.com/);
-   TODO: Support to docker-compose to run all the services dependencies;

## Installation

Follow these steps:

### Clone this repository

`$ git clone https://github.com/leozz37/texugo.git`

### Create a build directory and build binary

`$ mkdir build && cd build`

`$ cmake .. && make`

## Server Configs

You can change the default route settings by changing the _routingAddresses_ array on the resources/settings.json file.

```settings.json

"routingAddresses": [
    {
      "AAAAAAA": "3000"
    },
    {
      "BBBBBBB": "3001"
    },
    {
      "CCCCCCC": "3002"
    },
    {
      "DDDDDDD": "3003"
    },
    {
      "EEEEEEE": "3004"
    }
  ]
```

## Python files

There're two pub files and one sub file. They work on the following way:

| File name     | Run command                    |
| ------------- | ------------------------------ |
| `pub.py`      | `$ python pub.py 'Hello world'`|
| `pub_loop.py` | `$ python pub_loop.py 5555`    |
| `sub.py`      | `$ python sub.py 3000`         |