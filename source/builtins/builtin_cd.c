#include "refur.h"

int builtin_cd(char **argv) {
  if (argv[1] == NULL) {
    if (chdir(getenv("HOME")) == -1) {
      fprintf(stderr, "error: failed to change directory\n");
    }
  } else {
    if (chdir(argv[1]) == -1) {
      fprintf(stderr, "error: failed to change directory\n");
    }
  }
  return 0;
}
