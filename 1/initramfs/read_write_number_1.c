#include <stdio.h>
#include <stdlib.h>
#include "read_write_number.h"
#include <time.h>

int main()
{
	int x=0;
	printf("Ola processo 1\n\n");
        time_t ltime; /* calendar time */
	while(1) {
		x++; 
		write_number(x);
   		x = read_number();
		ltime=time(NULL); /* get current cal time */
		printf("%s || Processo 1: %d\n",asctime( localtime(&ltime)), x);
   		sleep(5);
	}
        return 0;
}

