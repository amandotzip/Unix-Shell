#include <stdio.h>
#include <assert.h>
#include "unix.h"


int main() {
  Unix filesystem;

  mkfs(&filesystem);

  touch(&filesystem, "chipmunk");
  touch(&filesystem, "platypus");
  touch(&filesystem, "numbat");
  mkdir(&filesystem, "quokka");
  mkdir(&filesystem, "koala");

  ls(&filesystem, ".");
  printf("\n");

  assert(rm(&filesystem, "frog") == 0);
  assert(rm(&filesystem, "emu") == 0);

  ls(&filesystem, ".");

  return 0;
}
