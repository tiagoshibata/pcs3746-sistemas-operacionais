#!/bin/bash
set -ex

fail() {
    echo $1 >&2
    exit 1
}

if ! cd /home/student/src/linux ; then
    fail "Mount a linux tree under /home/student/src/linux"
fi

if [ ! -f .config ] ; then
    echo ".config not found, using versatile template"
    make ARCH=arm versatile_defconfig
    make ARCH=arm silentoldconfig
fi

make ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- all
