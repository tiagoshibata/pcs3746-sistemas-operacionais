#include<linux/unistd.h>

#define __NR_insert 398
#define __NR_remove 399

long insert(int value)
{
	return syscall(__NR_insert, value);
}

// long remove()
// {
// 	return syscall(__NR_remove);
// }

// _syscall1(long, insert, int, value)  // FIXME Macros are cleaner
// _syscall0(long, remove)
