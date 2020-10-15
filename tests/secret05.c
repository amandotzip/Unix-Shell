/*
 * Tests that the root directory can contain a directory with the name
 * "root".
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
