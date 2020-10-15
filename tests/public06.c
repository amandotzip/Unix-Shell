#include <stdio.h>
#include "unix.h"



int main() {
  Unix filesystem;

  mkfs(&filesystem);

  touch(&filesystem, "chipmunk");
  touch(&filesystem, "platypus");
  touch(&filesystem, "numbat");
  touch(&filesystem, "quokka");
  touch(&filesystem, "koala");

  ls(&filesystem, ".");
  printf("\n");

  rm(&filesystem, "koala");
  rm(&filesystem, "numbat");

  ls(&filesystem, ".");

  return 0;
}
