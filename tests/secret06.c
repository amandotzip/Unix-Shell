/*
 * CMSC 216, Fall 2019, Project #8
 * Secret test 6 (secret06.c)
 *
 * Tests some special cases for the functions when the current directory is
 * the root directory, and the filesystem is empty.
 *
 * (c) Larry Herman, 2019.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#include <stdio.h>
#include "unix.h"

int main() {
  Unix filesystem;

  mkfs(&filesystem);

  ls(&filesystem, ".");
  ls(&filesystem, "");

  cd(&filesystem, "..");
  pwd(&filesystem);
  cd(&filesystem, ".");
  pwd(&filesystem);
  cd(&filesystem, "/");
  pwd(&filesystem);

  return 0;
}
