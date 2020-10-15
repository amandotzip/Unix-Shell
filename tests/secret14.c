/*
 * Tests some special cases for touch().
 */

#include <stdio.h>
#include <assert.h>
#include "unix.h"

int main() {
  Unix filesystem;

  mkfs(&filesystem);

  mkdir(&filesystem, "emu");

  assert(touch(&filesystem, "") == 0);

  cd(&filesystem, "emu");
  assert(touch(&filesystem, "..") == 1);
  ls(&filesystem, ".");

  /* ensure that nothing changed */
  cd(&filesystem, "..");
  ls(&filesystem, ".");

  return 0;
}
