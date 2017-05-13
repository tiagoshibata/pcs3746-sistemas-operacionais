#!/bin/bash
set -e

fail() {
    echo $1 >&2
    exit 1
}

if ! cd /home/user/src/linux ; then
    fail "Mount a linux tree under /home/user/src/linux"
fi

if [ ! -f .config ] ; then
    echo ".config not found, using versatile template"
    make ARCH=arm versatile_defconfig
fi

make ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- all
