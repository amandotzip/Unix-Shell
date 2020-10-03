/*
 * CMSC 216, Fall 2019, Project #8
 * Secret test 4 (secret04.c)
 *
 * Tests that the root directory can contain a file with the name "root".
 *
 * (c) Larry Herman, 2019.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#include <stdio.h>
#include "unix.h"

int main() {
  Unix filesystem;

  mkfs(&filesystem);

  touch(&filesystem, "leaf");
  touch(&filesystem, "root");
  touch(&filesystem, "tree");

  ls(&filesystem, ".");

  return 0;
}
