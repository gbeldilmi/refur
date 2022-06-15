#include "refur.h"

int execute(char **argv){
  pid_t pid;
  int status;

  pid = fork();
  if (pid == 0) {
    if (execvp(argv[0], argv) == -1) {
      fprintf(stderr, "error: failed to execute command\n");
    }
    exit(0);
  } else {
    if (pid < 0) {
      fprintf(stderr, "error: failed to fork\n");
    } else {
      do {
        waitpid(pid, &status, WUNTRACED);
      } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
  }

  return status;
}
