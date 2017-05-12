FROM ubuntu
MAINTAINER Tiago Koji Castro Shibata

# Environment
RUN locale-gen en_US.UTF-8
ENV LANG en_US.UTF-8

# Packages
RUN apt-get update && apt-get install --no-install-recommends -y binutils-arm-linux-gnueabi \
    build-essential gcc-arm-linux-gnueabi qemu-arm sudo \
    && rm -rf /var/lib/apt/lists/*

# Non-root "student" user
RUN useradd -mG sudo student && mkdir -p /etc/sudoers.d && \
    echo '%sudo   ALL=(ALL:ALL) NOPASSWD: ALL' > /etc/sudoers.d/sudo_nopasswd && \
    mkdir -p /home/user/src

COPY ./entrypoint.sh /
COPY ./default_cmd.sh /
ENTRYPOINT ["/entrypoint.sh"]
CMD ["/default_cmd.sh"]
