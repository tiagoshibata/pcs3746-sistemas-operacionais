#include "write_device.h"

#include <stdlib.h>
#include <stdio.h>


int main()
{
	for (;;) {
		switch (getchar()) {
			case 'e':
			{
				int r = rand() % 256;
				printf("Writing %x\n", r);
				write_device(r);
				break;
			}

			case 'q':
			case EOF:
			return 0;
		}
	}
}
