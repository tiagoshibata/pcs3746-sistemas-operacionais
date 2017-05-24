#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>

#define __NR_inic 398
#define __NR_inc 399
#define __NR_dec 400

void inic(int x)
{
	syscall(__NR_inic, x);
}

int inc(void)
{
	return syscall(__NR_inc);
}

int dec(void)
{
    return syscall(__NR_dec);
}
