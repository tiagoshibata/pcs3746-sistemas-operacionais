#include <stdio.h>
#include <stdlib.h>
#include "read_write_number.h"
#include <time.h>

int main()
{
	extern bool flag[2];
	extern int turn;
	int x=0;
	printf("Ola processo 0\n\n");
        time_t ltime; /* calendar time */
	while(1) {
		flag[0] = true;
		turn = 1;
		while (flag[1]==true && turn == 1)
		{

		}		
                x = read_number();
                //ltime=time(NULL); /* get current cal time */
                //printf("%s || Processo 0: %d\n",asctime( localtime(&ltime)), x);
                printf("%d\n", x);
		sleep(1);
                x++;
                write_number(x);
		flag[0]=false;
	}
        return 0;
}

