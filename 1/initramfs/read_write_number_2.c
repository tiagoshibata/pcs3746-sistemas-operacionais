#include <stdio.h>
#include <stdlib.h>
#include "read_write_number.h"

int main()
{

	int x=0;
	printf("Ola processo 2\n\n");
        time_t ltime; /* calendar time */
	while(1) {
		x++; 
		write_number(x);
   		x = read_number();
		ltime=time(NULL); /* get current cal time */
		printf("\n%s || Processo 2: %d\n",asctime( localtime(&ltime)), x);
   		sleep(1);
	}
        return 0;
}

