#include <stdio.h>
#include "unix.h"
#include "driver.h"



int main() {
  Unix filesystem;

  mkfs(&filesystem);

  driver(&filesystem);

  return 0;
}
