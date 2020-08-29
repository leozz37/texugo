# Using Ubuntu 20.10
FROM ubuntu:groovy

# Disable interactive cli
ARG DEBIAN_FRONTEND=noninteractive

# Install dependencies
RUN apt-get update -y
RUN apt-get install -y build-essential \
                       libssl-dev \
                       wget \
                       git

# Install CMake 17
ARG cmake_version=3.17.3
RUN wget https://github.com/Kitware/CMake/releases/download/v${cmake_version}/cmake-${cmake_version}.tar.gz && \
    tar -zxvf cmake-${cmake_version}.tar.gz
WORKDIR $PWD/cmake-${cmake_version}
RUN ./bootstrap && \
    make -j8 && \
    make install

# Entrypoint set up
COPY entrypoint.sh /root/entrypoint.sh
RUN chmod +x /root/entrypoint.sh
ENTRYPOINT ["/root/entrypoint.sh"]