/*
 * CMSC 216, Fall 2019, Project #8
 * Secret test 3 (secret03.c)
 *
 * Tests that a directory can contain files and directories with the same
 * names as itself.
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
  touch(&filesystem, "pear");
  mkdir(&filesystem, "platypus");
  touch(&filesystem, "papaya");
  touch(&filesystem, "orange");

  cd(&filesystem, "chipmunk");
  mkdir(&filesystem, "chipmunk");
  ls(&filesystem, ".");

  cd(&filesystem, "..");

  cd(&filesystem, "platypus");
  touch(&filesystem, "platypus");
  ls(&filesystem, ".");

  cd(&filesystem, "..");

  ls(&filesystem, ".");
  ls(&filesystem, "chipmunk");
  ls(&filesystem, "platypus");

  return 0;
}
