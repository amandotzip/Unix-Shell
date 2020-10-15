#include <stdio.h>
#include "unix.h"
#include "memory-checking.h"



int main() {
  Unix filesystem;

  #if !defined(ENABLE_VALGRIND)
  setup_memory_checking();
  #endif

  mkfs(&filesystem);

  touch(&filesystem, "chipmunk");
  touch(&filesystem, "platypus");
  touch(&filesystem, "numbat");
  touch(&filesystem, "quokka");
  touch(&filesystem, "koala");

  ls(&filesystem, ".");

  /* now trash the whole thing */
  rmfs(&filesystem);

  #if !defined(ENABLE_VALGRIND)
  check_heap();
  #endif

  /* if this is the only thing printed the heap must be valid, and there
   * must not have been any memory leaks
   */
  printf("\nEverything in the heap looks valid!\n");

  return 0;
}
