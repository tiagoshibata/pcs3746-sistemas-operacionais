#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
	while(1) {
		int value = rand() % 100;
		printf("stack_push(%d)\n", value);
		stack_push(value);
		sleep(rand() % 4 + 1);
	}
	return 0;
}
