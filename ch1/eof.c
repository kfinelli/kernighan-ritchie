#include "stdio.h"

/* misc examples about file input */
/* ex 1-6, 1-7 */

main() {
  int c;

  while (c= (getchar() != EOF) ) {
    printf("%d\n", c);
  }
  printf("EOF = %d\n",EOF);
}
