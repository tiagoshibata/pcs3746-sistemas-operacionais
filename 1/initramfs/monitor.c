#include <fcntl.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
 
int main() 
{ 
        int fdc = open("/sys/kernel/sys_stack/count", O_RDONLY); 
        int fdf = open("/sys/kernel/sys_stack/first_value", O_RDONLY); 
        int fdl = open("/sys/kernel/sys_stack/last_value", O_RDONLY); 
 
        char stack_count[5]; 
        char stack_first_value[5]; 
        char stack_last_value[5]; 
         
        while(1) { 
                if (lseek(fdc, 0, SEEK_SET) || lseek(fdf, 0, SEEK_SET) || lseek(fdl, 0, SEEK_SET)) { 
                        perror("lseek"); 
                } else { 
                        int sizec = read(fdc, stack_count, 4); 
                        int sizef = read(fdf, stack_first_value, 4); 
                        int sizel = read(fdl, stack_last_value, 4); 
                        if (sizec < 0){ 
                                perror("read count"); 
                        } else if (sizef < 0){ 
                                perror("read first"); 
                        } else if (sizel < 0){ 
                                perror("read last"); 
                        } else { 
                                stack_count[sizec] = 0; 
                                stack_first_value[sizef] = 0; 
                                stack_last_value[sizel] = 0; 
                                printf("\n---Stack Monitor---\n"); 
                                printf("Stack item count: %s\nStack first item value: %s\nStack last item value: %s\n", 
                                        stack_count, stack_first_value, stack_last_value); 
                        } 
                } 
                sleep(5); 
        } 
        return 0; 
}

