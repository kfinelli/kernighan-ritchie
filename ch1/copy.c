#include "stdio.h"

/* copy input to output, replace multiple blanks with single blank */
/* ex 1-8 */

main() {
  int c; 
  int blank = 0;

  while ((c = getchar()) != EOF) {
    if (c==' ')  {
      if (blank==0) putchar(c);
      blank++;
    } else {
      putchar(c);
      blank= 0;
    }
  }
}
