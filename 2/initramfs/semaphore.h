#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>

#define __NR_init_semaphore 404
#define __NR_up 405
#define __NR_down 406

long init_semaphore(int initial_value)
{
	return syscall(__NR_init_semaphore, initial_value);
}

long up(int semaphore_id)
{
	return syscall(__NR_up, semaphore_id);
}

long down(int semaphore_id)
{
	return syscall(__NR_down, semaphore_id);
}