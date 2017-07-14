CC=$(CROSS_COMPILE)gcc -Wall -Wextra -Werror -static -g
USR_BIN_FILES+=tree

# End of user configuration

BUILD_DIR?=build
ROOTFS?=rootfs
USR_BIN:=$(addprefix $(BUILD_DIR)/initramfs_root/usr/bin/,$(notdir $(USR_BIN_FILES)))

# TODO Ideally, use fakeroot during build and set proper directory permissions
$(shell mkdir -p $(BUILD_DIR)/initramfs_root/usr/bin)

.PHONY: all clean busybox
all: $(BUILD_DIR)/rootfs.gz

clean:
	rm -rf $(BUILD_DIR)
	find -name '*.o' -delete

$(BUILD_DIR)/rootfs.gz: $(BUILD_DIR)/initramfs_root/init $(USR_BIN) busybox
	cp -ruav $(ROOTFS)/. $(BUILD_DIR)/initramfs_root/
	cd $(BUILD_DIR)/initramfs_root ; find -print0 | cpio -0 -ov -H newc | gzip -9 > ../rootfs.gz

$(BUILD_DIR)/initramfs_root/init: init.o
	$(CC) -o $@ $^

$(USR_BIN): $(BUILD_DIR)/initramfs_root/usr/bin/%: %.o
	$(CC) -o $@ $^

busybox:
	./busybox/configure.sh
	$(MAKE) -C busybox/busybox
	cp -uav busybox/busybox/busybox $(BUILD_DIR)/initramfs_root/usr/bin/busybox
