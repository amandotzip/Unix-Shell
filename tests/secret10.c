/*
 * Tests creating a large number of files and directories and calling ls().
 *
 */

#include <stdio.h>
#include "unix.h"
#include "driver.h"

int main() {
  Unix filesystem;

  driver(&filesystem);

  return 0;
}
