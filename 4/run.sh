#!/bin/bash
docker run -ti --rm \
    -v "$PWD/../1/linux":/home/student/src/linux \
    -v "$PWD":/home/student/src/initramfs \
    -v "$PWD/../initramfs_base":/home/student/src/initramfs_base \
    -v "$PWD/docker_cmd.sh":/default_cmd.sh \
    tiagoshibata/pcs3746
