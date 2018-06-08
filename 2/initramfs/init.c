#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main() {
  int child_pid;

  child_pid = fork();
  if (child_pid == 0) {
    char* argv[] = { "child", NULL };
    execve("child", argv, NULL);
  } else {
    while (1) {
      sleep(5);
      kill(child_pid, SIGFPE);
    }
  }
  return 0;
}
