#include <stdio.h>
#include "unix.h"



int main() {
  Unix filesystem;

  mkfs(&filesystem);

  mkdir(&filesystem, "wombat");
  mkdir(&filesystem, "koala");
  touch(&filesystem, "chipmunk");
  touch(&filesystem, "quokka");
  ls(&filesystem, "");

  touch(&filesystem, "koala");
  mkdir(&filesystem, "koala");
  touch(&filesystem, "chipmunk");
  mkdir(&filesystem, "chipmunk");
  ls(&filesystem, "");

  return 0;
}
