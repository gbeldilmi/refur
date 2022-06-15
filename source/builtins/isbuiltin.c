#include "refur.h"

int isbuiltin(char *cmd) {
  size_t i;

  i = 0;
  while(i < builtinscount()) {
    if (strcmp(cmd, builtins_s[i]) == 0) {
      return 1;
    }
  }
  return 0;
}
