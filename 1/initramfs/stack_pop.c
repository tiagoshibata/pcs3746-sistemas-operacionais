#include <stdlib.h>
#include "stack.h"

int main()
{
	while(1) {
		printf("%d\n", stack_pop());
		sleep(rand() % 5 + 1);
	}
	return 0;
}
