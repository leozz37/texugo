# Texugo

![logo](images/logo.png)

[![Codacy Badge](https://app.codacy.com/project/badge/Grade/555c8f8825504a81804f4c41b75228cf)](https://www.codacy.com/manual/leozz37/texugo?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=leozz37/texugo&amp;utm_campaign=Badge_Grade)
[![CodeFactor](https://www.codefactor.io/repository/github/leozz37/texugo/badge)](https://www.codefactor.io/repository/github/leozz37/texugo)
[![Build Status](https://travis-ci.com/leozz37/texugo.svg?branch=master)](https://travis-ci.com/leozz37/texugo)
[![Build status](https://ci.appveyor.com/api/projects/status/qqp2al1e827jx70m?svg=true)](https://ci.appveyor.com/project/leozz37/texugo)
[![codecov](https://codecov.io/gh/leozz37/texugo/branch/master/graph/badge.svg)](https://codecov.io/gh/leozz37/texugo)
[![Documentation](https://codedocs.xyz/leozz37/texugo.svg)](https://codedocs.xyz/leozz37/texugo/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

[Texugo](https://leozz37.github.io/texugo/) is a fast flexible multiplatform message gateway based on sockets, library free, made with Modern C++.

## Features

-   End-to-end system that process messages, using [Boost.ASIO](https://www.boost.org/doc/libs/1_66_0/doc/html/boost_asio.html);
-   Flexible port binding;
-   Reliably serve devices across multiple networks;
-   Logging support with [spdlog](https://github.com/gabime/spdlog);
-   Dependency managed by [CPM.cmake](https://github.com/TheLartians/CPM.cmake);
-   Unit tests using [Catch2](https://github.com/catchorg/Catch20);
-   Support to build and run the binary on [Docker](https://www.docker.com/);
-   Support to docker-compose to run all the services dependencies;
-   TODO: Storing messages and logs on [MongoDB](https://www.mongodb.com/);
-   TODO: Metrics monitoring with [Prometheus](https://prometheus.io/);
-   TODO: Data visualization with [Grafana](https://grafana.com/);

## Installation

Follow these steps:

### Clone this repository

```bash
$ git clone https://github.com/leozz37/texugo.git
```

### Create a build directory and build binary

```bash
$ mkdir build && cd build

$ cmake ..

$ make -j4
```


## Docker

Building the image:

```bash
$ docker build . -t texugo
```

Running the image:

```bash
$ docker run --net host texugo
```

Running docker compose

```bash
$ docker-compose up
```

### DockerHub Image

You can find the latest image version [here](https://hub.docker.com/repository/docker/leozz37/texugo);

## Server Configs

The routing addresses are setted up at the _settings.json_ file. You can choose the receiver addresses, and the sender addresses:

Receiver addresses is going to binded by Texugo, and it will listen to them:

```JSON
"receiverAddresses": [
    {
      "ARDUINO": "3000"
    },
    {
      "NODE-SERVICE": "3001"
    },
    {
      "METRICS": "3002"
    }
  ]
```

Sender Addresses are the ports listening. Make sure to have a service binded to that port:

```JSON
"senderAddresses": [
    {
      "RASPBERRY": "3003"
    },
    {
      "GO-SERVICE": "3004"
    },
    {
      "GRAFANA": "3005"
    }
  ]
```

### Using examples

There's two files example, to use them do the follow commands:

| File name              | Run command                                        |
| ---------------------- | -------------------------------------------------- |
| `injector-single.py`   | `$ python injector-single.py 3000 ENDPOINT Hello`  |
| `injector-multiple.py` | `$ python injector-multiple.py 3000 BBBBBBB Hello` |
| `listener-port.py`     | `$ python listener-port.py 3005`                   |

### Running Tests

```bash
$ cd build/tests

$ ctest -V
```
