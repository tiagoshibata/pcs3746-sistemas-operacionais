#include <stdio.h>
#include <unistd.h>
#include <time.h>

#include "stop.h"

int main()
{
	pid_t pid_A = fork();
	if (pid_A == -1) {
		perror("fork");
		return -1;
	} else if (pid_A) {
		pid_t pid_int = fork();
		if (pid_int == -1) {
			perror("fork");
			return -1;
		} else if (pid_int) {
			for (;;) {
				char c = getchar();
				if (c == 'b') {
					if (stop_process(pid_A))
						return -1;
				} else if (c == 'a') {
					if (stop_process(pid_int))
						return -1;
				} else if (c == 'd') {
					continue_process();
				}
			}
		} else {
			for (int i = 0;;i++) {
				const struct timespec ts = {.tv_sec = 0, .tv_nsec = 5e8 };
				nanosleep(&ts, NULL);
				printf("%d\n", i);
			}
		}
	} else {
		for (;;) {
			const struct timespec ts = {.tv_sec = 0, .tv_nsec = 5e8 };
			nanosleep(&ts, NULL);
			printf("A\n");
		}
	}
}
