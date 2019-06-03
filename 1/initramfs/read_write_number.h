#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>

#define __NR_read_number 405
#define __NR_write_number 404
#define __NR_write_turn 406
#define __NR_read_turn 407
typedef int bool;
#define true 1
#define false 0


struct peterson {
	static int turn;
	static bool flag[2];
}


struct peterson read_turn() {
	return syscall(__NR_read_turn);
}

long write_turn(int turn, bool firstFlag, bool secondFlag) {
	return syscall(__NR_write_turn, turn, firstFLag, secondFlag);
}


long read_number()
{
	return syscall(__NR_read_number);
}

long write_number(int value)
{
	return syscall(__NR_write_number, value);
}
