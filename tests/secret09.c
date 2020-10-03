/*
 * CMSC 216, Fall 2019, Project #8
 * Secret test 9 (secret09.c)
 *
 * Tests that file and directory names are being properly compared for
 * equality (another case).
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
  assert(ls(&filesystem, "cat") == 0);

  mkdir(&filesystem, "pear");
  assert(ls(&filesystem, "ear") == 0);

  ls(&filesystem, ".");

  return 0;
}
