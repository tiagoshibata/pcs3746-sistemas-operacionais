#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int fd = open("/dev/blocking_dev", O_RDONLY);
	char item[1];

	while(1) {
		int size = read(fd, item, 1);
		if (size < 0) {
			perror("read");
		} else {
			printf("Read item: %x\n", item[0]);
		}
	}
	return 0;
}
