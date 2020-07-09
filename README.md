# message-switch
Simple MQ message switch using modern C++

## Features

- End-to-end system that simulates a message switching system, with ZeroMQ;
- Support to store messages on MongoDB;
- Support to spdlog;
- Support to build binary and run application on Docker;

## Installation

##### Clone this repository

`$ git clone https://github.com/leozz37/core-messaging.git`

##### Create a build directory and build binary

`$ mkdir build && cd build`

`$ make`

## Server Configs

You can change the default route settings by changing the _routeConfig_ array on the ServerConfiguration.json file.

```ServerConfiguration.json

"routeConfig": [
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

## Running

#### Running local

Run the binary generated on previously step and pass the ServerConfiguration path as a parameter.

`$ ./core-messaging /docker/ServerConfiguration.json`

Choose and run either _pub_loop.py_ or _pub.py_ client to send the messages. Pass the input port as a parameter (5555 is the default one).

`$ cd python`

`$ python pub_loop.py 5555`

#### Running docker

Build the base container.

`$ cd docker`

`$ docker build . -f Dockerfile-base -t core-base`

Build the binary generator container.

`$ docker build . -f Dockerfile-build -t core-messaging-build`

Run the binary generator container.

`$ docker run --name=core-build -tdi -v /home/leo/Documents/codes/core-messaging/docker/artifacts:/root/artifacts core-build`

Build the server container.

`$ docker build . -f Dockerfile-run -t core-messaging`

Run the server container. Pass the port(s) that you are using.

`$ docker run --name=core -tdi -p 5555:5555 -p 3000:3000 -p 3001:3001 core-messaging`

Choose and run either _pub_loop.py_ or _pub.py_ client to send the messages. Pass the input port as a parameter (5555 is the default one).

`$ cd python`

`$ python pub_loop.py 5555 AAAAAAA`
