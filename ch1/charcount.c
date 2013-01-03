#include "stdio.h"

/* count blanks, tabs, and newlines. */
/* ex 1-8 */

main() {
  int c; 
  int blank = 0, tab= 0, newline = 0;

  while ((c = getchar()) != EOF) {
    if (c==' ')  blank++;
    if (c=='\t') tab++;
    if (c=='\n') newline++;
  }
  printf("blanks: %d\n",blank);
  printf("tabs: %d\n",tab);
  printf("newlines: %d\n",newline);
}
