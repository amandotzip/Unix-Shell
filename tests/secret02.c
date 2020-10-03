/*
 * CMSC 216, Fall 2019, Project #8
 * Secret test 2 (secret02.c)
 *
 * Tests calling ls() on an empty subdirectory.
 *
 * (c) Larry Herman, 2019.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
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
