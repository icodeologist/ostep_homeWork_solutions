#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int fd = open("./hello.txt", O_CREAT | O_WRONLY | O_TRUNC);
  if (fd < 0) {
    perror("open failed");
    exit(1);
  }
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    printf("Fd in childP : %d\n", fd);
    char *new_msg =
        "This is child p and i want to tell you that you need to leave\n";
    char buffer[10];
    long bytes_written = write(STDOUT_FILENO, new_msg, strlen(new_msg));
    printf("Child wrote %ld bytes to the file.\n", bytes_written);
    close(fd);
  } else {
    printf("Fd in mainP : %d\n", fd);
    char *new_msg = "From main. Hello this is no a typical hello message and "
                    "im waiting to child to finish its job\n";
    char buffer[10];
    long bytes_written = write(STDOUT_FILENO, new_msg, strlen(new_msg));
    printf("Child wrote %ld bytes to the file.\n", bytes_written);
    close(fd);
    int rc_wait = wait(NULL);
  }
  return 0;
}
