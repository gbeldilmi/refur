#include "refur.h"

int (*builtins_f[])(char **) = {
  &builtin_cd,
  &builtin_exit
};
char *builtins_s[] = {
  "cd",
  "exit"
};

size_t builtinscount() {
  return sizeof(builtins_s) / sizeof(char *);
}
