#include <stdio.h>
#include "inic.h"

int main() {
	inic(10);
	pid_t increment;
	increment = fork();
	for(;;) {
		if (increment != 0)  { // This is the parent and should decrement
			printf("Dec: %d\n", dec());
			sleep(10);
		} else { // This is the child and should increment
			printf("Inc: %d\n", inc());
			sleep(5);
		}
	}
}
