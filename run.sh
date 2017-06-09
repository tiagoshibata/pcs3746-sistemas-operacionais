#!/bin/bash

if [[ "$1" ]] ; then
	docker run --rm -v "$PWD/linux":/home/student/src/linux -v "$PWD/$1/initramfs":/home/student/src/initramfs tiagoshibata/pcs3746
else
	docker run --rm -v "$PWD/linux":/home/student/src/linux -v "$PWD/2/initramfs":/home/student/src/initramfs tiagoshibata/pcs3746
fi
