USR_BIN_FILES+=$(PWD)/src/generate_page_fault.c
BUILD_DIR:=$(PWD)/build
ROOTFS:=$(PWD)/rootfs

MAKE_BASE:=$(MAKE) BUILD_DIR=$(BUILD_DIR) ROOTFS=$(ROOTFS) -C ../initramfs_base

$(shell mkdir -p $(BUILD_DIR))

.PHONY: all clean
# Expose targets all and clean from initramfs
all:
	$(MAKE_BASE) all

clean:
	$(MAKE_BASE) clean
