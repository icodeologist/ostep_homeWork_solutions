#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc , char *argv[]) {
  printf("The main process started with pid : %d\n", (int)getpid());
  int x;
  x = 100;
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "Fork() called\n");
    exit(1);
  }else if (rc == 0) {
    // child process
    printf("Value of X in child process before updating : %d\n", x);
    x = 10;
    printf("Value of X in child process after updating : %d\n", x);
    printf("address of x in child: %p\n", &x);
  }else{
    int rc_wait = wait(NULL);
    printf("Value of X in main process before updating : %d\n", x);
    x = 11;
    printf("Value of X in main process after updating : %d\n", x);
    printf("address of x in main: %p\n", &x);
  }
  return 0;
}
