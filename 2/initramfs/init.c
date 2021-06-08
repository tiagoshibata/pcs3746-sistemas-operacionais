#include <stdio.h>
#include "forkexecve.h"
int main()
{
	long pid = forkexecve("teste", NULL, NULL);
	printf("ARQUIVO: init.c; MODO: Usuario --> pid do forkexecve: %ld\n", pid);
	printf("ARQUIVO: init.c; MODO: Usuario --> pid %ld\n", getpid());

	while (1) { 
	printf("executando arquivo init.c\n");
	sleep(1);
   	}
   return 0;
}
