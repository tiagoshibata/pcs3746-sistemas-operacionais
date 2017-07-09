#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int fd = open("/dev/blocking_dev", O_RDONLY);
	if (fd == -1) {
		perror("open");
		return -1;
	}

	char item;

	while(1) {
		int size = read(fd, &item, 1);
		if (!size) {
			printf("EOF\n");
			return 0;
		}
		if (size < 0) {
			perror("read");
			return -1;
		}
		printf("Read item: %x\n", item);
	}
	return 0;
}
