# Using Ubuntu 20.10
FROM ubuntu:focal

# Disable interactive cli
ARG DEBIAN_FRONTEND=noninteractive

# Install dependencies
RUN apt-get update && apt-get install -y \
    build-essential libssl-dev wget git \
    cmake \
 && rm -rf /var/lib/apt/lists/*

# Entrypoint set up
COPY entrypoint.sh /root/entrypoint.sh
RUN chmod +x /root/entrypoint.sh
ENTRYPOINT ["/root/entrypoint.sh"]