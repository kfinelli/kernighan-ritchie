/* 2-2 Write a loop equivalent to
 * for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i) s[i] = c;
 * without using && or ||.
 */

#include <stdio.h>

void main() {
  const unsigned lim=20;
  char s[lim];

  int i, c;

  for (i=0; i<lim-1; ++i) {
    if ((c=getchar()) != '\n') {
      if (c != EOF) {
        s[i] = c;
      }
    }
  }
  printf("%s\n",s);
}
