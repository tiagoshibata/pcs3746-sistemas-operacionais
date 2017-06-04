#include <stdio.h>
#include <sys/types.h> 

int main() {
	pid_t processo;
	for (int i = 0; i < 100; i++){
		processo = fork();
	}
	for(;;) {
		if (processo!= 0)  { // This is the parent and should exec de i/o
			// exec i/o
		} else { // This is the child and should exec operation
			execv("conta","");
		}
	}
}
