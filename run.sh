#!/bin/bash

FILES_FOLDER_NAME=$1
[ "$1" == "" ] && FILES_FOLDER_NAME="1"
LINUX_FILES_PATH="$PWD/1"
FILES_PATH="$PWD/$FILES_FOLDER_NAME"
docker run -ti --rm -v "$LINUX_FILES_PATH/linux":/home/student/src/linux -v "$FILES_PATH/initramfs":/home/student/src/initramfs tiagoshibata/pcs3746
