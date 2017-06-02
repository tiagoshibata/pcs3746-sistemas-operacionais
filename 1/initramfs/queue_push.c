#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main()
{
	while(1) {
		int value = rand() % 100;
		printf("queue_push(%d)\n", value);
		queue_push(value);
		sleep(rand() % 4 + 1);
	}
	return 0;
}
