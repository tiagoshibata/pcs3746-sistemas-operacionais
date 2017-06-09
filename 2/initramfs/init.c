#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mount.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "hello_world.h"

#include "wait_fork.h"

#define len(_arr) ((int)((&_arr)[1] - _arr))

static const char * const programs[] = { "/queue_push", "/queue_pop" };

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

