/*
 * Tests that file and directory names are being properly compared for
 * equality (another case).
 */

#include <stdio.h>
#include <assert.h>
#include "unix.h"

int main() {
  Unix filesystem;

  mkfs(&filesystem);

  touch(&filesystem, "cats");
  assert(ls(&filesystem, "cat") == 0);

  mkdir(&filesystem, "pear");
  assert(ls(&filesystem, "ear") == 0);

  ls(&filesystem, ".");

  return 0;
}
