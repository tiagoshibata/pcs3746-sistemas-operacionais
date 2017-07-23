#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ALLOC_SIZE	80 * 1024 * 1024
#define SAFE_ACCESS_SIZE	70 * 1024 * 1024

static char m[ALLOC_SIZE];

void do_access(char *p, size_t length)
{
	for (size_t i = 0; i < length; i++)
		p[i] = 2 * p[i / 2] + 1;
}

int main(int argc, char **argv)
{
	int oom = 0;
	int c;
	while ((c = getopt(argc, argv, "o")) != -1) {
		switch (c) {
			case 'o':
			oom = 1;
			break;

			case '?':
			fprintf(stderr, "Usage: %s [-o]\n"
				"\t-o\tTry to generate an OOM exception\n"
				, argv[0]);
			return -1;
		}
	}

	do_access(m, SAFE_ACCESS_SIZE);

	if (oom)
		do_access(m + SAFE_ACCESS_SIZE, ALLOC_SIZE - SAFE_ACCESS_SIZE);

	return 0;
}
