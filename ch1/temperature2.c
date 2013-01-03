#include "stdio.h"

/* print Celsius-Fahrenheit table
   for celsius = 0, 20, ..., 300; floating-point version */
/* ex. 1-4 */

main() {
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  celsius = lower;
  printf("deg C  deg F\n");
  while (celsius <= upper) {
    fahr = (9.0/5.0)*celsius + 32.0;
    printf("%5.0f %6.0f\n", celsius, fahr);
    celsius = celsius + step;
  }
}
