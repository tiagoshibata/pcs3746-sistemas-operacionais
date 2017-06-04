#include <stdio.h>
#include <stdlib.h>

int main() {
	int rand1 = rand();
	int rand2 = rand();
	int total = rand1 * rand2;
	printf("%d\n", total);
	return 0;
}
