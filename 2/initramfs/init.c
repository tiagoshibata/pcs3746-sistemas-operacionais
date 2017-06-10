#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mount.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

#include "hello_world.h"
#include "wait.h"

#define len(_arr) ((int)((&_arr)[1] - _arr))

int wait_parent(int pid)
{
	while (1) {
		int fd = open("/sys/kernel/sys_wait/count", O_RDONLY);
		char wait_count[5];

		if (lseek(fd, 0, SEEK_SET)) {
			perror("lseek");
		} else {
			int size = read(fd, wait_count, 4);
			if (size < 0) {
				perror("read");
			} else {
				wait_count[size] = 0;
				printf("\nWait queue item count: %s\t", wait_count);
			}
		}

		char c;
		do {
			printf("\nInsert your char.");
			c = getchar();
		} while (c != 'b' && c != 'd');
		if (c == 'b') {
			wait_lock(pid);
		} else {
			int error = wait_unlock();
			if (error) {
				printf("\nWARNING: Could not unlock process from queue. (%d)\t", error);
			}
		}
	}
	return 0;
}

int wait_child()
{
	while (1) {
		printf("\nA");
		sleep(1);
	}
	return 0;
}

void panic(const char *msg)
{
	fprintf(stderr, "%s: %s (errno = %d)\n", msg, strerror(errno), errno);
	exit(-1);
}

void mount_fs()
{
	printf("Mounting filesystems\n");
	// If /sys is not created, make it read-only (mode = 444)
	if (mkdir("/sys", 0x124) && errno != EEXIST)
		panic("mkdir");
	if (mount("none", "/sys", "sysfs", 0, ""))
		panic("mount");
}

int main()
{
	printf("Custom initramfs - Hello World syscall:\n");
	hello_world();
	mount_fs();

	printf("Forking to run wait queue programs\n");
	int process_count = 0;

	while (1) {
		pid_t pid = fork();
		if (pid == -1) {
			panic("fork");
		} else if (pid) {
			printf("\nRunning parent process #%d (child pid = %d)\t", ++process_count, pid);
			wait_parent(pid);
			panic("wait_parent");
		} else {
			wait_child();
			panic("wait_child");
		}
	}

	printf("init finished\n");
	for (;;)
		sleep(1000);
	return 0;
}
