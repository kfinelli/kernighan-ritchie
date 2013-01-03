#include "stdio.h"

/* copy input to output, replace tab, bs, backslash with literal
   escape sequence */
/* ex 1-10 */

main() {
  int c; 

  while ((c = getchar()) != EOF) {
    if (c=='\b') {
      putchar('\\'); putchar('b');
    }
    else if (c=='\t') {
      putchar('\\'); putchar('t');
    }
    else if (c=='\n') {
      putchar('\\'); putchar('n');
    }
    else {
      putchar(c);
    }
  }
}
