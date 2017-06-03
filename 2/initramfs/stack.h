#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>

#define __NR_stack_push 398
#define __NR_stack_pop 399

long stack_push(int value)
{
	return syscall(__NR_stack_push, value);
}

long stack_pop()
{
	return syscall(__NR_stack_pop);
}
