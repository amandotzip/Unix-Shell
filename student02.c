/*TerpConnect: aawoke
  UID: 114094155
  Discussion #: 0202
  I pledge on my honor that I have not given nor recieved
  any unauthorized assistance on this assignment
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
  
  cd(&filesystem, "chipmunk");
  touch(&filesystem, "kiwi");
  mkdir(&filesystem, "papaya");
  mkdir(&filesystem, "pear");
  touch(&filesystem, "orange");
  
  cd(&filesystem, "..");

  cd(&filesystem, "platypus");
  touch(&filesystem,"apple");
  mkdir(&filesystem, "grape");
  mkdir(&filesystem, "banana");
  touch(&filesystem,"cherry");

  cd(&filesystem, "grape");
  mkdir(&filesystem, "blue");
  touch(&filesystem,"green"); 
  mkdir(&filesystem, "purple");
  touch(&filesystem,"yellow");
  touch(&filesystem,"white");
  mkdir(&filesystem,"red");
  
  cd(&filesystem, "red");
  pwd(&filesystem);
  return 0;
}