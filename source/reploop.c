#include "refur.h"

void reploop(FILE *src){
  char *cmd;
  char **argv;
  int c;

  c = 1;
  while (c) {
    if (src == stdin) {
      prompt();
    }
    cmd = getcmd(src);
    if (cmd != NULL) {
      if (strlen(cmd) > 0) {
        argv = splitargs(cmd);
        if (argv != NULL) {
          if (isbuiltin(argv[0])) {
            c = !builtins(argv);
          } else {
            execute(argv);
          }
          free(argv);
        }
      }
      free(cmd);
    }
  }
}
