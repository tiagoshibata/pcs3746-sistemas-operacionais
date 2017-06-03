#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>

#define __NR_queue_push 401
#define __NR_queue_pop 402

long queue_push(int value)
{
	return syscall(__NR_queue_push, value);
}

long queue_pop()
{
	return syscall(__NR_queue_pop);
}
