#include "refur.h"

int main(int argc, char **argv){
  FILE *src;

  init();
  src = stdin;
  if (argc != 1) {
    if ((src = fopen(argv[1], "r")) == NULL) {
      printf("%s: no such file or directory\n", argv[1]);
      return EXIT_FAILURE;
    }
  }
  reploop(src);
  if (argc != 1) {
    fclose(src);
  }

  return EXIT_SUCCESS;
}
