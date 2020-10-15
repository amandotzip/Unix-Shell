/*
 * Tests creating a deeply nested subdirectory, changing to it, and calling
 * pwd() from it.
 */

#include <stdio.h>
#include "unix.h"

int main() {
  Unix filesystem;
  int i;

  mkfs(&filesystem);

  for (i= 0; i < 500; i++) {
    mkdir(&filesystem, "x");
    cd(&filesystem, "x");
  }

  pwd(&filesystem);

  return 0;
}
