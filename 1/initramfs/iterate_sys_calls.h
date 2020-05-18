#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>

long iterate_sys_calls(int system_call_NR)
{
	syscall(system_call_NR);
}
