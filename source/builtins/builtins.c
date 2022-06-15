#include "refur.h"

int builtins(char **argv) {
  size_t i;

  i = 0;
  while(i < builtinscount()) {
    if (strcmp(argv[0], builtins_s[i]) == 0) {
      return (*builtins_f[i])(argv);
    }
  }
  return 0;
}
