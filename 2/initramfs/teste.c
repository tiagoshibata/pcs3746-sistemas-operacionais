#include <stdio.h>

long fib(int n) {
	long fib1 = 1, fib2 = 1, soma;
	int i;
	for (i = 3; i <= n; i= i +1) {

	soma = fib1 + fib2;
	fib1 = fib2;
	fib2 = soma;
	}
	return fib2;
}



int main() {
	int n = 0;
	printf("ARQUIVO: teste.c; MODO: Usuario --> pid %ld\n", getpid());
	while(1) {
		/*printf("fib de %d = %ld\n", n, fib(n));*/
		printf("estou printando 2 pela %d vez\n", n);
		n++;
		if(n > 100) {
			n = 0;
		}
		sleep(1);
	}
}


