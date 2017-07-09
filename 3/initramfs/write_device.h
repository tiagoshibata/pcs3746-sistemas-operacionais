#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>

#define __NR_write_device 403

long write_device(int value)
{
	return syscall(__NR_write_device, value);
}
