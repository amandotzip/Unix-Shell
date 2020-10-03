/*
 * CMSC 216, Fall 2019, Project #8
 * Secret test 7 (secret07.c)
 *
 * Tests calling some of the functions with argument names that contain
 * forward slashes.
 *
 * (c) Larry Herman, 2019.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#include <stdio.h>
#include <assert.h>
#include "unix.h"

int main() {
  Unix filesystem;

  mkfs(&filesystem);

  mkdir(&filesystem, "chipmunk");

  assert(mkdir(&filesystem, "chipmunk/platypus") == 0);
  assert(touch(&filesystem, "chipmunk/quokka") == 0);
  assert(cd(&filesystem, "chipmunk/numbat") == 0);
  assert(ls(&filesystem, "chipmunk/koala") == 0);

  cd(&filesystem, "chipmunk");
  ls(&filesystem, ".");

  cd(&filesystem, ".");
  ls(&filesystem, ".");

  printf("This should be the only output of this test.\n");

  return 0;
}
