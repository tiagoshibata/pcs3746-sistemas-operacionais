#!/bin/bash
cd docker 
docker build -t rafalencar1997/pcs3746 .
cd ..
docker run -ti --rm -v "$PWD/linux":/home/student/src/linux -v "$PWD/initramfs":/home/student/src/initramfs rafalencar1997/pcs3746
