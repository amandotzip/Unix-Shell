/*
 * Tests some special cases for mkdir().
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
