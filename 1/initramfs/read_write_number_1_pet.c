#include <stdio.h>
#include <stdlib.h>
#include "read_write_number.h"
#include <time.h>


int main()
{
	int x = 0;
	printf("Entrando no processo 1...\n\n");
	while(1) {
		write_flag(1, true);
                write_turn(0);
                while (read_turn() == 0 && read_flag(0) == true) {
                }
                x = read_number();
		printf("%d\n", x);
		sleep(1);
                x++;
                write_number(x);
		write_flag(1, false);
	}
        return 0;
}

