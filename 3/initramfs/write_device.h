#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>

#define __NR_write_device 403

long write_device()
{
	return syscall(__NR_write_device);
}
