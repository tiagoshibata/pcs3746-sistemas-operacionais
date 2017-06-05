#include <stdio.h>
#include <sys/types.h> 

int main() {
	pid_t processo;
	for (int i = 0; i < 99; i++){
		processo = fork();
		if (processo == 0)
		{
			break;
		}
	}
	if (processo == 0){
		printf("filho\n");
		int error = execl("./conta", "conta", "", (char*) NULL);
		if (error == -1) {
			printf("An error occured!\n");
		} 
	} else {
		printf("pai\n");
	}
}
