#pragma once

int builtins(char **argv);
size_t builtinscount();
int isbuiltin(char *cmd);

int builtin_cd(char **argv);
int builtin_exit(char **argv);

extern char *builtins_s[];
extern int (*builtins_f[])(char **);

