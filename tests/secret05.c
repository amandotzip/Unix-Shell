/*
 * CMSC 216, Fall 2019, Project #8
 * Secret test 5 (secret05.c)
 *
 * Tests that the root directory can contain a directory with the name
 * "root".
 *
 * (c) Larry Herman, 2019.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#include <stdio.h>
#include "unix.h"

int main() {
  Unix filesystem;

  mkfs(&filesystem);

  mkdir(&filesystem, "tree");
  mkdir(&filesystem, "root");
  mkdir(&filesystem, "leaf");

  ls(&filesystem, ".");

  return 0;
}
