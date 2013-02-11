#include "stdio.h"

#define IN  1
#define OUT 0
#define NBINS 256

/* ex 1-14 */
/* print a histogram of the frequency of characters in input*/

main() {
  int c;
  int char_hist[NBINS];
  int i,j;

  for (i= 0; i < NBINS; i++)
    char_hist[i] = 0;

  while ((c = getchar()) != EOF) {
    /* increment the appropriate bin */
    char_hist[c]++;
  }

  /* get y-max */
  int y_max = 0;
  for (i = 0; i < NBINS; i++) 
    if (char_hist[i] > y_max)
      y_max = char_hist[i];

  /* now print the histogram  (vertical) */  
  for (i = y_max; i > 0; i--) {
    for (j = 0; j < NBINS; j++) {
      if (char_hist[j] >= i)
	putchar('*');
      else if (char_hist[j]>0)
	putchar(' ');
    }
    putchar('\n');
  }
  
  /* not a perfect way to represent tabs and newlines, but you get the
     idea */
  for (j = 0; j < NBINS; j++) {
    if (char_hist[j] > 0) {
      if (j=='\t') putchar('T');
      else if (j=='\n') putchar('N');
      else putchar(j);
    }
  }
  putchar('\n');
}
