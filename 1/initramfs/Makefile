CC=$(CROSS_COMPILE)gcc -Wall -Wextra -static -g

$(shell mkdir -p build/initramfs_root)

.PHONY: all clean
all: build/rootfs.gz

clean:
		rm -rf build
		find -name '*.o' -delete

build/rootfs.gz: build/initramfs_root/init build/initramfs_root/stack_pop build/initramfs_root/stack_push build/initramfs_root/monitor build/initramfs_root/read_write_number_0_pet build/initramfs_root/read_write_number_1_pet build/initramfs_root/read_write_number_1 build/initramfs_root/read_write_number_2
		cd build/initramfs_root ; \
		find -type f -print0 | cpio -0 -ov -H newc | gzip -9 > ../rootfs.gz

build/initramfs_root/init: init.o
		$(CC) -o $@ $^

build/initramfs_root/stack_push: stack_push.o
		$(CC) -o $@ $^

build/initramfs_root/stack_pop: stack_pop.o
		$(CC) -o $@ $^

build/initramfs_root/monitor: monitor.o
		$(CC) -o $@ $^

build/initramfs_root/read_write_number_1: read_write_number_1.o
		$(CC) -o $@ $^

build/initramfs_root/read_write_number_2: read_write_number_2.o
		$(CC) -o $@ $^

build/initramfs_root/read_write_number_0_pet: read_write_number_0_pet.o
		$(CC) -o $@ $^

build/initramfs_root/read_write_number_1_pet: read_write_number_1_pet.o
		$(CC) -o $@ $^

