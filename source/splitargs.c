#include "refur.h"

#define ARGV_REALLOC_LEN 3

char **splitargs(char *cmd){
  size_t i;
  int argc;
  char c;
  char **argv;

  argc = 0;
  i = 0;
  if (!(argv = (char**) malloc(sizeof(char*) * ARGV_REALLOC_LEN))){
    printf("error: failed to allocate memory\n");
    return NULL;
  }
  argv[0] = NULL;
  while ((c = cmd[i]) != '\0' && c != EOF){
    if (isspace(c)){
      cmd[i] = '\0';
      i++;
    } else {
      if (c == '"' || c == '\'' || c == '`'){
        cmd[i] = '\0';
        i++;
      }
      if (argc > 0 && argc + 1 % ARGV_REALLOC_LEN == 0){
        if (!(argv = (char**) realloc(argv, sizeof(char*) * (argc + ARGV_REALLOC_LEN)))){
          printf("error: failed to allocate memory\n");
          free(argv);
          return NULL;
        }
      }
      argv[argc] = cmd + i;
      (argc)++;
      argv[argc] = NULL;
      if (c == '"' || c == '\'' || c == '`'){
        while (cmd[i] != '\0' && (cmd[i] != c || cmd[i - 1] == '\\')){
          i++;
        }
        if (cmd[i] == c){
          cmd[i] = '\0';
        } else {
          printf("error: unmatched quote\n");
          free(argv);
          return NULL;
        }
        i++;
      } else {
        while (cmd[i] != '\0' && !isspace(cmd[i])){
          i++;
        }
      }
    }
  }

  return argv;
}
