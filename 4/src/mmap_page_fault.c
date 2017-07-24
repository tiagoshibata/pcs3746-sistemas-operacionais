#include <ctype.h>
#include <fcntl.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

__attribute__((noreturn)) void panic(const char *msg)
{
	perror(msg);
	exit(-1);
}

__attribute__((noreturn)) void usage(const char *program_name)
{
	fprintf(stderr, "Usage: %s [-p] file\n"
		"\t-p\tPopulate the mapping\n", program_name);
	exit(-1);
}

size_t get_file_size(const char *filename) {
	struct stat st;
	if (stat(filename, &st) == -1)
		panic("stat");
	return st.st_size;
}

void *map_fd(int fd, size_t length, int flags) {
	void *mapped_file = mmap(NULL, length, PROT_READ, flags, fd, 0);
	if (mapped_file == MAP_FAILED)
		panic("mmap");
	return mapped_file;
}

int main(int argc, char **argv)
{
	int mmap_flags = MAP_SHARED;
	int c;
	while ((c = getopt(argc, argv, "p")) != -1) {
		switch (c) {
			case 'p':
			mmap_flags |= MAP_POPULATE;
			break;

			case '?':
			usage(argv[0]);
			return -1;
		}
	}

	if (optind != argc - 1)  // Only 1 name parameter should be used
		usage(argv[0]);

	char *filename = argv[optind];
	size_t length = get_file_size(filename);
	int fd = open(filename, O_RDONLY);
	if (fd == -1)
		panic("open");

	char *data = map_fd(fd, length, mmap_flags);
	printf("File mapped to %" PRIuPTR "\n", (uintptr_t)data);
	for (size_t i = 0; i < length; i++)
		printf("%zu: %.2x (%c)\n", i, data[i], isprint(data[i]) ? data[i] : '.');

	if (munmap(data, length))
		panic("munmap");
	return 0;
}
