/*
 * Tests some special cases for the functions when the current directory is
 * the root directory, and the filesystem is empty.
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
