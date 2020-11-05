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
    zlib1g-dev \
    libcurl4-gnutls-dev \
 && rm -rf /var/lib/apt/lists/*

# Copying files
COPY . .
WORKDIR /build-docker

# Building texugo
RUN cmake .. \
 && make -j8

# Running texugo
WORKDIR /build-docker/bin
CMD [ "./texugo_process" ]