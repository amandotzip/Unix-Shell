#include <stdio.h>
#include "unix.h"



int main() {
  Unix filesystem;

  mkfs(&filesystem);

  mkdir(&filesystem, "chipmunk");
  mkdir(&filesystem, "platypus");
  mkdir(&filesystem, "numbat");
  mkdir(&filesystem, "quokka");
  mkdir(&filesystem, "koala");

  ls(&filesystem, ".");
  printf("\n");

  rm(&filesystem, "koala");
  rm(&filesystem, "numbat");

  ls(&filesystem, ".");

  return 0;
}
