#include <stdio.h>
#include <stdlib.h>
#include "read_write_number.h"
#include <time.h>

int main()
{
	int x = 0;
	printf("Entrando no processo 0...\n\n");
	while(1) {
		write_flag(0, true);
		write_turn(1);
		while (read_turn() == 1 && read_flag(1) == true) {
		}		
                x = read_number();
                printf("%d\n", x);
		sleep(1);
                x++;
                write_number(x);
		write_flag(0, false);
	}
        return 0;
}

