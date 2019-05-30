#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>

#define __NR_read_number 405
#define __NR_write_number 404

long read_number()
{
	return syscall(__NR_read_number);
}

long write_number(int value)
{
	return syscall(__NR_write_number, value);
}
