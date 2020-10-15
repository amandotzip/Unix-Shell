/*
 * Tests that the root directory can contain a file with the name "root".
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
