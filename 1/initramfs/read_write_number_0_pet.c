#include <stdio.h>
#include <stdlib.h>
#include "read_write_number.h"
#include <time.h>

int main()
{
	int x=0;
	struct peterson meuPet;

	printf("Ola processo 0\n\n");
        //time_t ltime; /* calendar time */
	while(1) {
		write_turn(1, true, -1);
		meuPet = read_turn();
		while (meuPet.turn == 1 && meuPet.flag[1] == true)
		{
			meuPet = read_turn();
		}		
                x = read_number();
                //ltime=time(NULL); /* get current cal time */
                //printf("%s || Processo 0: %d\n",asctime( localtime(&ltime)), x);
                printf("%d\n", x);
		sleep(1);
                x++;
                write_number(x);
		write_turn(-1, false, -1);
	}
        return 0;
}

