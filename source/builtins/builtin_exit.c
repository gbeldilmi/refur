#include "refur.h"

int builtin_exit(char **argv) {
  int s;

  if (argv[1] != NULL) {
    s = atoi(argv[1]);
    return s ? s : 1;
  }
  return 1;
}
