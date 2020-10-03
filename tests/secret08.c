/*
 * CMSC 216, Fall 2019, Project #8
 * Secret test 8 (secret08.c)
 *
 * Tests that file and directory names are being properly compared for
 * equality (one case).
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

  touch(&filesystem, "cats");
  assert(ls(&filesystem, "catsup") == 0);

  mkdir(&filesystem, "pear");
  assert(ls(&filesystem, "disappears") == 0);

  ls(&filesystem, ".");

  return 0;
}
