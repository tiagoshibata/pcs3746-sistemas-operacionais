#!/bin/bash
set -ex

fail() {
    echo $1 >&2
    exit 1
}

SRC=/home/student/src
if [ ! -f $SRC/linux/Makefile ] ; then
    fail "Mount a linux tree volume under $SRC/linux"
fi
cd $SRC/linux
if [ ! -f .config ] ; then
    echo ".config not found, using versatile template"
    make ARCH=arm versatile_defconfig
    cat <<EOF > .config-fragment
CONFIG_DEBUG_INFO=y
CONFIG_DEVTMPFS=y
CONFIG_PCI=y
CONFIG_PCI_VERSATILE=y
CONFIG_VIRTIO_BLK=y
CONFIG_VIRTIO_PCI=y
CONFIG_VIRTIO_BALLOON=y
EOF
    # To enable SCSI and SCSI virtio:
    # CONFIG_SCSI_VIRTIO=y
    # CONFIG_SCSI_SYM53C8XX_2=y
    # CONFIG_SCSI=y
    $SRC/initramfs/merge_config.sh .config .config-fragment
    make ARCH=arm olddefconfig
fi
make ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- all

if ! cd $SRC/initramfs ; then
    fail "Mount a volume with initramfs source files under $SRC/initramfs"
fi
make ARCH=arm CROSS_COMPILE=arm-linux-gnueabi-

BOOT=$SRC/linux/arch/arm/boot
qemu-system-arm -M versatilepb -m 64M -nographic -kernel $BOOT/zImage -dtb $BOOT/dts/versatile-pb.dtb \
    -initrd build/rootfs.gz \
    -append "root=/dev/sda virtio_pci.force_legacy=1" \
    -drive file=build/swap.img,format=raw,if=virtio,index=0 \
    -drive file=build/aux_disk.img,format=raw,if=virtio,index=1
