#include <stdio.h>
#include "inic.h"

int main() {
	inic(10);
	pid_t increment;
	increment = fork();
	for(;;) {
		if (increment != 0)  { // This is the parent and should decrement
			printf("Decrement: %d, pid: %d\n", dec(), getpid());
			sleep(10);
		} else { // This is the child and should increment
			printf("Increment: %d, pid: %d\n", inc(), getpid());
			sleep(5);
		}
	}
}
