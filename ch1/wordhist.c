#include "stdio.h"

#define IN  1
#define OUT 0
#define NBINS 10

/* ex 1-13 */
/* print a histogram of the lengths of words in input*/

main() {
  int c, state, length;
  int length_hist[NBINS];
  int i,j;
  state = IN;
  length = 0;

  for (i= 0; i < NBINS; i++)
    length_hist[i] = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c=='\t' || c =='\n')
      state = OUT;
    else {
      if (state == OUT) {
	state = IN;
	/* increment the appropriate bin, treating the last bin as overflow */
	if (length>=NBINS) length_hist[NBINS-1]++;
	else length_hist[length]++;
	length = 0;
      }
      length++;
    }
  }
  /* in case the file doesn't end with newline, increment bins once more */
  if (length>=NBINS) length_hist[NBINS-1]++;
  else length_hist[length]++;


  /* now print the histogram  (horizontal) */  

  /* for (i = 0; i < NBINS; i++) { */
  /*   for (j = 0; j < length_hist[i]; j++) { */
  /*     putchar('*'); */
  /*   } */
  /*   putchar('\n'); */
  /* } */

  /* get y-max */
  int y_max = 0;
  for (i = 0; i < NBINS; i++) 
    if (length_hist[i] > y_max)
      y_max = length_hist[i];

  /* now print the histogram  (vertical) */  
  for (i = y_max; i > 0; i--) {
    for (j = 0; j < NBINS; j++) {
      if (length_hist[j] >= i)
	putchar('*');
      else putchar(' ');
    }
    putchar('\n');
  }

}
