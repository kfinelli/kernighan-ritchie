#include "stdio.h"

/* print Fahrenheit-Celsius table
   for fahr = 0, 20, ..., 300; floating-point version */
/* ex. 1-16 */

float fahr_to_cel(float);

main() {
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  printf("deg F  deg C\n");
  while (fahr <= upper) {
    celsius = fahr_to_cel(fahr);
    printf("%5.0f %6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
}

float fahr_to_cel(float f) {
  return (5.0/9.0) * (f-32.0);
}
