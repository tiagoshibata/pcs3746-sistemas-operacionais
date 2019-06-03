#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>

#define __NR_write_number 404
#define __NR_read_number  405
#define __NR_write_turn   406
#define __NR_read_turn    407
#define __NR_write_flag   408
#define __NR_read_flag    409

#define true 1
#define false 0

long read_flag(int index) {
        return syscall(__NR_read_flag, index);
};

long write_flag(int index, int value) {
	return syscall(__NR_write_flag, index, value);
};

long read_turn() {
	return syscall(__NR_read_turn);
};

long write_turn(int turn) {
	return syscall(__NR_write_turn, turn);
};


long read_number() {
	return syscall(__NR_read_number);
};

long write_number(int value) {
	return syscall(__NR_write_number, value);
};
