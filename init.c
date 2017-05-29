#include <stdio.h>
#include "inic.h"

void childProcess(void);
void parentProcess(void);

int main() {
	inic(10);

	pid_t increment;
	
	increment = fork();
	
	for (int i = 1; i <= 99; i++) {
		int pid = fork();
		if (pid == 0) {
			exec("somaNumeros.c");
		}
	}
	pid = fork();
	if (pid == 0) {
		exec("inOut.c");
	}
	
	for(;;) {
		if (increment != 0)  { // This is the parent and should decrement
			parentProcess();
		} else { // This is the child and should increment
			childProcess();
		}
	}
}


void  parentProcess(void)
{
	printf("Decrement: %d, pid: %d\n", dec(), getpid());
	sleep(10);
}

void  childProcess(void)
{
	printf("Increment: %d, pid: %d\n", inc(), getpid());
	sleep(5);
}