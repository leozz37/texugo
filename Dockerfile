# Using Ubuntu 20.10
FROM ubuntu:focal

# Disable interactive cli
ARG DEBIAN_FRONTEND=noninteractive

# Install dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    libssl-dev \
    git \
    cmake \
 && rm -rf /var/lib/apt/lists/*

# Copying files
COPY . .
WORKDIR /build-docker

# Building texugo
RUN cmake .. \
 && make -j4

# Running texugo
WORKDIR /build-docker/bin
ENTRYPOINT [ "./texugo_process" ]