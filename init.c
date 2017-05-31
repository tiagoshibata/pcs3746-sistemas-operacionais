#include <stdio.h>
#include <sched.h>
#include "inic.h"

void childProcess(void);
void parentProcess(void);

int main() {
	inic(10);

	pid_t increment;
	
	increment = fork();

	struct sched_param param = { .sched_priority = 1 };

	pid_t pid = getpid();

	printf("Default scheduler: %d (SCHED_NORMAL) from process pid: %d \n", sched_getscheduler(pid), pid);
	sched_setscheduler(pid, SCHED_RR, &param);
	printf("New scheduler: %d (SCHED_RR) from process pid: %d \n", sched_getscheduler(pid), pid);

	// for (int i = 1; i <= 99; i++) {
	// 	int pid = fork();
	// 	if (pid == 0) {
	// 		exec("somaNumeros.c");
	// 	}
	// }
	// pid = fork();
	// if (pid == 0) {
	// 	exec("inOut.c");
	// }
	
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
	printf("Decrement: %d, pid: %d, Scheduler: %d(SCHED_RR) \n", dec(), getpid(), sched_getscheduler(getpid()));
	sleep(10);
}

void  childProcess(void)
{
	printf("Increment: %d, pid: %d, Scheduler: %d(SCHED_RR) \n", inc(), getpid(), sched_getscheduler(getpid()));
	sleep(5);
}