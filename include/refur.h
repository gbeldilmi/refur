#pragma once

#include <celya.h>

#define REFUR_CONFIG_FILE "~/.refur/refur.cfg"

int execute(char **argv);
char *getcmd(FILE *fd);
void init();
void prompt();
void reploop(FILE *fd);
char **splitargs( char *cmd);

#include "builtins.h"
