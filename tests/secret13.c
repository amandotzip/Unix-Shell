/*
 * CMSC 216, Fall 2019, Project #8
 * Secret test 13 (secret13.c)
 *
 * Tests some special cases for mkdir().
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

  mkdir(&filesystem, "emu");

  assert(mkdir(&filesystem, "") == 0);

  cd(&filesystem, "emu");
  assert(mkdir(&filesystem, "..") == 0);
  ls(&filesystem, ".");

  /* ensure that nothing changed */
  cd(&filesystem, "..");
  ls(&filesystem, ".");

  return 0;
}
