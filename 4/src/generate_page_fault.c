#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>

__attribute__((noreturn)) void panic(const char *msg)
{
	perror(msg);
	exit(-1);
}

size_t get_file_size(const char *filename) {
	struct stat st;
	if (stat(filename, &st) == -1)
		panic("stat");
	return st.st_size;
}

void *map_fd(int fd, size_t length) {
	void *mapped_file = mmap(NULL, length, PROT_READ, MAP_SHARED, fd, 0);
	if (mapped_file == MAP_FAILED)
		panic("mmap");
	return mapped_file;
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		fprintf(stderr, "Usage: %s file\n", argv[0]);
		return -1;
	}

	size_t length = get_file_size(argv[1]);
	int fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		panic("open");

	char *data = map_fd(fd, length);
	for (size_t i = 0; i < length; i++)
		putchar(data[i]);

	if (munmap(data, length))
		panic("munmap");
	return 0;
}
