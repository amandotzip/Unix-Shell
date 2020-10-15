/*
 *
 * Tests calling ls() on an empty subdirectory.
 *
 */

#include <stdio.h>
#include "unix.h"

int main() {
  Unix filesystem;

  mkfs(&filesystem);

  mkdir(&filesystem, "chipmunk");

  ls(&filesystem, "chipmunk");

  printf("This should be the only output of this test.\n");

  return 0;
}
