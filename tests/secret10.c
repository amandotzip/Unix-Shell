/*
 * CMSC 216, Fall 2019, Project #8
 * Secret test 10 (secret10.c)
 *
 * Tests creating a large number of files and directories and calling ls().
 *
 * (c) Larry Herman, 2019.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#include <stdio.h>
#include "unix.h"
#include "driver.h"

int main() {
  Unix filesystem;

  driver(&filesystem);

  return 0;
}
