#include "stack.h" 
 
#include <fcntl.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
 
int main() 
{        
        while(1) { 
                printf("stack_pop: %ld\n", stack_pop()); 
                sleep(rand()% 5 + 1); 
        } 
        return 0; 
}

