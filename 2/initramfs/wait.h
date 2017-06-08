#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>

#define __NR_wait_lock 403
#define __NR_wait_unlock 404

long wait_lock(int process)
{
	return syscall(__NR_wait_lock, process);
}

long wait_unlock()
{
	return syscall(__NR_wait_unlock);
}
