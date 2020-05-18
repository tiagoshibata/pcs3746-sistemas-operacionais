#include "iterate_sys_calls.h"
#include <stdio.h>
#include <sys/wait.h>

#define __NR_calls 11
#define SECONDS_TO_WAIT 3

int main(){
	while(1){
		int calls[__NR_calls] = {20, 199, 200, 201, 202, 205, 209, 211, 224, 364, 400};

		int system_call_NR;
		int timer;
		for(system_call_NR = 0; system_call_NR < __NR_calls; system_call_NR++){
			printf("Executando a syscall %d\n", calls[system_call_NR]);
			iterate_sys_calls(calls[system_call_NR]);
			
			sleep(SECONDS_TO_WAIT);
		}
	}
	return 0;
}