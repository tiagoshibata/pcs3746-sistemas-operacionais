#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>

#define __NR_stop	401
#define __NR_start	402

long stop_process(int pid)
{
	return syscall(__NR_stop, pid);
}

long continue_process()
{
	return syscall(__NR_start);
}
