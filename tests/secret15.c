/*
 * Tests calling all of the functions with NULL Unix pointer arguments.
 */

#include <stdio.h>
#include "unix.h"

int main() {
  Unix filesystem;

  mkfs(&filesystem);

  mkdir(&filesystem, "chipmunk");
  touch(&filesystem, "pear");
  mkdir(&filesystem, "platypus");
  touch(&filesystem, "papaya");
  touch(&filesystem, "orange");

  /* here are the calls with NULL Unix pointer parameters- will your
     functions survive the challenge? */
  touch(NULL, "test1");
  mkdir(NULL, "test2");
  cd(NULL, "test3");
  ls(NULL, "test4");

  mkdir(&filesystem, "numbat");
  mkdir(&filesystem, "quokka");
  touch(&filesystem, "strawberry");
  touch(&filesystem, "raspberry");
  mkdir(&filesystem, "koala");

  ls(&filesystem, ".");

  return 0;
}
