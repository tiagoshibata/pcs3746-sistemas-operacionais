# Usage:

## Getting the image

Puling: `docker pull tiagoshibata/pcs3746`

Building: `cd docker ; docker build -t tiagoshibata/pcs3746 .`

## Running

Clone this repository with `git clone --recursive https://github.com/tiagoshibata/pcs3746-sistemas-operacionais.git` to clone with submodules. The `./run.sh` script does most of the required work.

If you need to customize the build:

`docker run -v "$PWD/linux":/home/student/src/linux -v "$PWD/initramfs":/home/student/src/initramfs tiagoshibata/pcs3746` will run the container, use `versatile_defconfig` if no .config is available, compile the kernel, generate the initramfs and boot qemu emulating the versatile ARM. The `<path to initramfs sources>` must contain a `Makefile` that outputs an initramfs image to `build/rootfs.gz`.

Adding a parameter after the container name runs the specified command in the container. Adding an empty string runs the default shell. `docker run -ti -v "$PWD/linux":/home/student/src/linux -v "$PWD/initramfs":/home/student/src/initramfs ''`, for example, runs the shell in an interactive session.

Tested with tag kernel tag `v4.12-rc1` (`2ea659a9ef488125eb46da6eb571de5eae5c43f6`).
