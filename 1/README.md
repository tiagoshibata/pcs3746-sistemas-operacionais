# Usage:

## Getting the image

Puling: `docker pull tiagoshibata/pcs3746`

Building: `cd docker ; docker build -t tiagoshibata/pcs3746 .`

## Running

`docker run -v "$PWD/linux":/home/student/src/linux -v "$PWD":/home/student/src/initramfs tiagoshibata/pcs3746` will run the container, use `versatile_defconfig` if no .config is available, compile the kernel, generate the initramfs and boot qemu emulating the versatile ARM. The `<path to initramfs sources>` must contain a `Makefile` that outputs an initramfs image to `build/rootfs.gz`.

Adding a parameter after the container name runs the specified command in the container. Adding an empty string runs the default shell. `docker run -ti -v "$PWD/linux":/home/student/src/linux -v "$PWD":/home/student/src/initramfs ''`, for example, runs the shell in an interactive session.

Tested with tag kernel tag `v4.12-rc1` (`2ea659a9ef488125eb46da6eb571de5eae5c43f6`).
