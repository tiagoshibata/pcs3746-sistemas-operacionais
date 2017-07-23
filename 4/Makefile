BUILD_DIR:=$(PWD)/build
ROOTFS:=$(PWD)/rootfs

# Set default target
all:

SELF_DIR:=$(dir $(word $(words $(MAKEFILE_LIST)),$(MAKEFILE_LIST)))
clean::
	find $(SELF_DIR) -name '*.o' -delete

USR_BIN_FILES:=capacity_page_fault mmap_page_fault
include ../initramfs_base/usr_bin_binaries.make
$(BUILD_DIR)/rootfs.gz: build_auxiliary_disk build_swap $(USR_BIN)

include ../initramfs_base/Makefile

.PHONY: build_auxiliary_disk build_swap

build_auxiliary_disk:
	if [ ! -f build/aux_disk.img ] ; then \
		fallocate -l 128M build/aux_disk.img ; \
		mkfs.ext2 build/aux_disk.img ; \
		echo "Auxiliary disk image created at build/aux_disk.img" ; \
		echo "To create a large file, mount it and run:" ; \
		echo "dd if=/dev/urandom of=mnt/large_file bs=1M count=120" ; \
	fi

build_swap:
	if [ ! -f build/swap.img ] ; then \
		fallocate -l 32M build/swap.img ; \
	fi
