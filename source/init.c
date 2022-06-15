#include "refur.h"

void init(){
  FILE *cfg;

  if ((cfg = fopen(REFUR_CONFIG_FILE, "r"))){
    reploop(cfg);
    fclose(cfg);
  } else {
    if ((cfg = fopen(REFUR_CONFIG_FILE, "w"))){
      fclose(cfg);
    }
  }
}
