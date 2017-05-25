#include <stdlib.h>
#include "stack.h"
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    while(1) {
        printf("stack_pop: %d\n", stack_pop());
        sleep(rand() % 5 + 1);
        int fd = open("/sys/kernel/sys_stack/count", O_RDONLY);
        printf("stack_pop_count: %d\n", fd);
    }
    return 0;
}
