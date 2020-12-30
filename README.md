# Texugo

![logo](images/logo.png)

[![Codacy Badge](https://app.codacy.com/project/badge/Grade/555c8f8825504a81804f4c41b75228cf)](https://www.codacy.com/manual/leozz37/texugo?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=leozz37/texugo&amp;utm_campaign=Badge_Grade)
[![CodeFactor](https://www.codefactor.io/repository/github/leozz37/texugo/badge)](https://www.codefactor.io/repository/github/leozz37/texugo)
![CMake](https://github.com/leozz37/texugo/workflows/CMake/badge.svg)
![Docker](https://github.com/leozz37/texugo/workflows/Docker/badge.svg)
[![codecov](https://codecov.io/gh/leozz37/texugo/branch/main/graph/badge.svg)](https://codecov.io/gh/leozz37/texugo)
[![Documentation](https://codedocs.xyz/leozz37/texugo.svg)](https://codedocs.xyz/leozz37/texugo/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

[Texugo](https://leozz37.github.io/texugo/) is a fast, multiplatform, lightweight and, dependency-free message gateway, for custom payload processing, flexible port routing and metrics monitoring.

Since Texugo uses sockets, you don't need an external library to use it. Compatible with any technology with support to sockets.

Under construction, made with Modern C++.

## Contents

- [Features](#features)
- [Installation](#installation)
- [Quick start](#quick-start)
- [Examples](#examples)
- [Testing](#testing)
- [Contributing](#contributing)
- [License](#license)

## Features

- Dependecy-free, works with anything with support to sockets;
- Reliably serve devices across multiple networks;
- Flexible port binding;
- Flexible logging;
- Docker support;
- Metrics monitoring with [Prometheus](https://prometheus.io/) and [Grafana](https://grafana.com);
- Messages and logs stored to [MongoDB](https://www.mongodb.com/);
- Dependency managed by [CPM.cmake](https://github.com/TheLartians/CPM.cmake);

## Installation

Clone this repository:

```bash
$ git clone https://github.com/leozz37/texugo.git
```

Create a build directory and build the binary:

```bash
$ mkdir build && cd build

$ cmake ..

$ make -j4
```

### Docker

To pull Texugo's Docker image, run the following:

```shell
$ docker pull docker.pkg.github.com/leozz37/texugo/texugo:latest
```

## Quick start

To run Texugo with the settings example, simply run:

```shell
$ cd ./bin

$ ./texugo_process
```

You can change your settings in the [`./resources/settings.json`](./resources/settings.json) file. You can set up the routing adresses and, choose the receiver and sender:

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

### Docker image

To run the Docker image, you can bind each port you are use on the run command (**recommended**):

```shell
$ docker run -p 3000:3000 texugo
```

Or simply use the `--network "host"` argument, recommended for testing:

```shell
$ docker run --network host texugo
```

## Running Tests

```bash
$ cd build/tests

$ ctest -R texugo_tests -V -j2
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

Running docker compose:

```bash
$ docker-compose up
```

## DockerHub Image

You can find the latest image version [here](https://hub.docker.com/repository/docker/leozz37/texugo);

```bash
$ docker pull leozz37/texugo
```

## Examples

Run the listener and run one of the injectors:

| File name              | Run command                                        |
| ---------------------- | -------------------------------------------------- |
| `injector-single.py`   | `$ python injector-single.py 3000 ENDPOINT Hello`  |
| `injector-multiple.py` | `$ python injector-multiple.py 3000 BBBBBBB Hello` |
| `listener-port.py`     | `$ python listener-port.py 3005`                   |

## Testing

To run the unit tests:

```shell
$ cd build/tests

$ ctest -R texugo_tests -V -j2
```

To run the functional tests, you must have [Robot Framework](https://pypi.org/project/robotframework/) installed:

```shell
$ cd tests/functional/

$ robot -P libraries -d output tests
```

## Contributing

Fell free to open a Pull Request, you're more then welcome to contribute! A full guideline about contributing to Alacritty can be found in the [CONTRIBUTING.md](https://github.com/leozz37/texugo/blob/main/CONTRIBUTING.md) file.

### Issues

Use the search tool before opening a new issue.

Please provide source code and commit sha if you found a bug.

Review existing issues and provide feedback or react to them.

### Pull requests

Open your pull request against ```develop```.

You should add/modify tests to cover your proposed code changes.

Tests coverage should never go down from 90%.

If your pull request contains a new feature, please document it on the README.

### Branching

The ```main``` is a **regular branch** which always contains the latest
**stable** codebase and must **never** be broken.

The ```develop``` is a **regular branch** which always contains the latest
**development** codebase and **eventually** can be broken. But you'll need to
accept the **sombrero of shame** if you do that.

The ```release``` is a **regular branch** which contains a specific release
version. You must use the following name convention: **release-X.Y.Z**, where
X, Y and Z are: major, minor and patch [version numbers](#versioning).

The ```experimental``` is a **temporary branch** which contains a new feature or
ideia. You must use the following name convention: **experimental-brief-description**.

The ```feature``` is a **temporary branch** which contains a new feature under
development that latter will be merged against the development branch. You must
use the following name convention: **feature-brief-description**.

The ```bugfix``` is a **temporary branch** which contains necessary fix to be
applied **after** a specific release to be merged against the development branch.
You must use the following name convention: **bugfix-brief-description**.

The ```hotfix``` is a **temporary branch** which contains a critical fix to be
applied **immediately** and merged against the main and the development branches.
You must use the following name convention: **hotfix-brief-description**.

Feel free to apply the labels from GitHub to the branches, they are very helpful.

### Versioning

The project uses the [semantic versioning 2.0.0](https://semver.org) in
order to control the version numbers.

### Commiting

The ```main```, ```develop``` and ```release``` branches have protection rules
against **push**.

In order to contribute you must create a new branch following the [branching](#branching)
guideline and once your work is done, open a **pull request** from your branch
to the **develop** branch.

The **pull request** will trigger the test suites automatically
and the code must **pass all the tests** and also be reviewed and approved
before merged in the **develop** branch (or even ``main`` or ``release`` in case
of a ``*fix``).

We use [this](https://chris.beams.io/posts/git-commit/) commit message convention, please follow it.

Feel free to apply the labels from GitHub to the pull requests, they are very helpful.

## License

Texugo is released under the [MIT License](https://github.com/leozz37/texugo/blob/main/LICENSE).
