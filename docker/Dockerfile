FROM ubuntu:latest

ARG DEBIAN_FRONTEND=noninteractive

RUN apt update -y && apt upgrade -y

RUN apt install -y build-essential \
                   libssl-dev \
                   wget

# Install CMake 17
ARG cmake_version=3.17.3
RUN wget https://github.com/Kitware/CMake/releases/download/v${cmake_version}/cmake-${cmake_version}.tar.gz && \
    tar -zxvf cmake-${cmake_version}.tar.gz && \
    cd cmake-${cmake_version} && \
    ./bootstrap && \
    make -j8 && \
    make install

RUN apt install -y git

COPY entrypoint.sh /root/entrypoint.sh
RUN chmod +x /root/entrypoint.sh
ENTRYPOINT ["/root/entrypoint.sh"]