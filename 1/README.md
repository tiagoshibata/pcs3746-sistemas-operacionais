# Usage:

## Building the image

```
cd docker
docker build -t opsys .
```

## Running

`docker run -v <path to linux sources>:/home/student/src/linux -v <path to initramfs sources>:/home/student/src/initramfs opsys` will run the container, use `versatile_defconfig` if no .config is available, compile the kernel, generate the initramfs and boot qemu emulating the versatile ARM. The `<path to initramfs sources>` must contain a `Makefile` that outputs an initramfs image to `build/rootfs.gz`.

Adding a parameter after the container name runs the specified command in the container. Adding an empty string runs the default shell. `docker run -ti -v <path to linux sources>:/home/student/src/linux -v <path to initramfs sources>:/pcs opsys ''`, for example, runs the shell in an interactive session.
