#include "stdio.h"

#define IN  1
#define OUT 0

/* ex 1-11 */
/* Inputs that seem likely to cause bugs would involve combinations of
tabs, newlines, spaces.  Files not terminated in newlines may cause an
issue*/

/* ex 1-12 */
/*print input one word per line*/

main() {
  int c, state;

  state = IN;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c=='\t' || c =='\n')
      state = OUT;
    else {
      if (state == OUT) {
	state = IN;
	putchar('\n');
      }
      putchar(c);
    }
  }
  putchar('\n');
}
