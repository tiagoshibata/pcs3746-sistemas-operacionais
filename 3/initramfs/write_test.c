#include <stdlib.h>
#include "write_device.h"
#include <stdio.h>
#include <unistd.h>
#include <time.h>


int main()
{
	while(1) {
		char c = getchar();
		if(c == 'e') {
			int r = rand() % 100;
			write_device(r);
		} else if(c == 'q') {
			break;
		}
	}
	return 0;
}
