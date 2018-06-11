#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>

#define __NR_hello_world 404

long hello_world(int value)
{
	return syscall(__NR_hello_world, value);
}
