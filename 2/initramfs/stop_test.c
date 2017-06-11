#include <stdio.h>
#include <unistd.h>
#include <time.h>

#include "stop.h"

int main()
{
	pid_t pid = fork();
	if (pid == -1) {
		perror("fork");
		return -1;
	} else if (pid) {
		for (;;) {
			char c = getchar();
			if (c == 'b') {
				if (stop_process(pid))
					return -1;
			} else if (c == 'd') {
				continue_process();
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
