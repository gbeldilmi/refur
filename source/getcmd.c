#include "refur.h"

#define CMD_BUF_LEN 1024

char *getcmd(FILE *src){
  char *buf;
  char *cmd;
  size_t buflen;
  size_t cmdlen;
  int c;

  cmd = NULL;
  cmdlen = 0;
  c = 1;
  if ((buf = malloc(CMD_BUF_LEN * sizeof(char)))){
    while (c){
      buf = fgets(buf, CMD_BUF_LEN, src);
      buflen = strlen(buf);
      if ((cmd = realloc(cmd, sizeof(char) * (cmdlen + buflen + 1)))){
        if (buf[buflen - 1] == '\n'){
          if (buflen == 1 || buf[buflen-2] != '\\'){
            c = 0;
          } else {
            if (buf[buflen-2] == '\\'){
              buf[buflen-2] = '\0';
            }
            buf[buflen-1] = '\0';
            buflen = strlen(buf);
          }
        }
        memcpy(cmd + cmdlen, buf, buflen);
        cmdlen += buflen;
        cmd[cmdlen] = '\0';
      } else {
        printf("error: failed to allocate memory\n");
        free(cmd);
        return NULL;
      }
    }
  }

  return cmd;
}
