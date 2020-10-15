/*
 * Tests that file and directory names are being properly compared for
 * equality (one case).
 *
 */

#include <stdio.h>
#include <assert.h>
#include "unix.h"

int main() {
  Unix filesystem;

  mkfs(&filesystem);

  touch(&filesystem, "cats");
  assert(ls(&filesystem, "catsup") == 0);

  mkdir(&filesystem, "pear");
  assert(ls(&filesystem, "disappears") == 0);

  ls(&filesystem, ".");

  return 0;
}
