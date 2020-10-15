#include <stdio.h>
#include "unix.h"
#include "driver.h"


int main() {
  Unix filesystem;

  /* note the first command in the input is mkfs */
  driver(&filesystem);

  /* now trash the whole thing */
  rmfs(&filesystem);

  return 0;
}
