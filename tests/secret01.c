/*
 * Tests that each filesystem (Unix variable) is independent, and doesn't
 * share any data with other ones.  (If you used global variables- which is
 * prohibited according to the project style guide- you will probably fail
 * this test.)
 *
 */

#include <stdio.h>
#include "unix.h"

int main() {
  Unix filesystem1, filesystem2;

  mkfs(&filesystem1);
  mkfs(&filesystem2);

  touch(&filesystem1, "chipmunk");
  mkdir(&filesystem1, "dog");
  touch(&filesystem1, "llama");
  touch(&filesystem1, "poodle");

  mkdir(&filesystem2, "chipmunk");
  mkdir(&filesystem2, "koala");
  touch(&filesystem2, "llama");
  touch(&filesystem2, "quokka");

  ls(&filesystem1, ".");
  printf("\n");

  ls(&filesystem2, ".");

  return 0;
}
