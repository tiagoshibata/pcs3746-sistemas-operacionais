#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>

#define __NR_hello_world 400

long hello_world()
{
	return syscall(__NR_hello_world);
}
