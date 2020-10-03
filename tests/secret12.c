/*
 * CMSC 216, Fall 2019, Project #8
 * Secret test 12 (secret12.c)
 *
 * Tests creating a deeply nested subdirectory, changing to it, and calling
 * pwd() from it.
 *
 * (c) Larry Herman, 2019.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
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
