#include "queue.h"

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int fd = open("/sys/kernel/sys_queue/count", O_RDONLY);
	char queue_count[5];

	while(1) {
		if (lseek(fd, 0, SEEK_SET)) {
			perror("lseek");
		} else {
			int size = read(fd, queue_count, 4);
			if (size < 0) {
				perror("read");
			} else {
				queue_count[size] = 0;
				printf("queue item count: %s", queue_count);
			}
		}
		printf("queue_pop: %ld\n", queue_pop());
		sleep(rand() % 5 + 1);
	}
	return 0;
}
