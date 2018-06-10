#include <stdio.h>
#include <unistd.h>

int main() {
  //We're forking the proccess
  if (fork() == 0) {
    //Child proccess
    char* argv[] = { "child", NULL };
    execve("child", argv, NULL);
  } else {
    //Parent process
    while (1) {
      printf("1\n");
    }
  }

  return 0;
}
