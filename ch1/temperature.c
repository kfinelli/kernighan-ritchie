#include "stdio.h"

/* print Fahrenheit-Celsius table
   for fahr = 0, 20, ..., 300; floating-point version */
/* ex. 1-3 */

main() {
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  printf("deg F  deg C\n");
  while (fahr <= upper) {
    celsius = (5.0/9.0) * (fahr-32.0);
    printf("%5.0f %6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
}
