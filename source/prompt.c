#include "refur.h"

void prompt(){
  char *cwd;

  cwd = getcwd(NULL, 0);
  fprintf(stderr, "\033[32m%s\n\033[33mrefur >> \033[0m", cwd);
  free(cwd);
}
