#include "stdio.h"

/* print Fahrenheit-Celsius table
   for fahr = 0, 20, ..., 300; floating-point version */
/* ex. 1-5 */

main() {
  int fahr;

  printf("deg F  deg C\n");
  for (fahr = 300; fahr >= 0; fahr = fahr - 20)
    printf("%d %6.1f\n", fahr, (5.0/9.0)*(fahr-32.0));
}
