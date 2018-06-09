#!/bin/bash

CURRENT_PATH=$PWD
cd ../1
docker run -ti --rm -v "$PWD/linux":/home/student/src/linux -v "$CURRENT_PATH/initramfs":/home/student/src/initramfs tiagoshibata/pcs3746
