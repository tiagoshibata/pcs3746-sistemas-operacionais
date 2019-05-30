#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>

typedef int bool;
#define true 1
#define false 0

#define __NR_read_number 405
#define __NR_write_number 404

bool flag[2] = {false, false};
int turn;

long read_number()
{
	return syscall(__NR_read_number);
}

long write_number(int value)
{
	return syscall(__NR_write_number, value);
}
