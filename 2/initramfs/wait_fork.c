#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "wait_fork.h"
#include "wait.h"

int wait_parent(int pid)
{
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
		c = getchar();
	} while (c != 'b' && c != 'd');
	if (c == 'b') {
		wait_lock(pid);
	} else {
		wait_unlock();
	}
	return 0;
}

int wait_child()
{
	while (1) {
		printf("A");
		sleep(1);
	}
	return 0;
}
