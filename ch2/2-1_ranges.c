/* Write a program to determine the ranges of char, short, int and long
 * variables, both signed and unsigned, by printing appropriate values from
 * standard headers and by direct computation.  Harder if you compute them:
 * determine the ranges of the various floating-point types. */

#include <limits.h>
#include <float.h>
#include <stdio.h>

int main() {

  /*a posteriori pick close to the right starting values to save time*/
  char  c=0,                  cs=1;
  short s=32760,              ss=32761;
  int   i=2147483640,         is=2147483641;
  long  l=0x7ffffffffffffff0, ls=0x7ffffffffffffff1;

  unsigned char  uc=0,                  ucs=1;
  unsigned short us=32760,              uss=32761;
  unsigned int   ui=4294967290,         uis=4294967291;
  unsigned long  ul=18446744073709551610UL, uls=18446744073709551611UL;

  while (c < cs){
    ++c; ++cs;
  }
  printf("Found max value of char: %d \n",c);
  printf("limits.h max value of char: %d \n",CHAR_MAX);

  while (s < ss){
    ++s; ++ss;
  }
  printf("Found max value of short: %d \n",s);
  printf("limits.h max value of short: %d \n",SHRT_MAX);

  while (i < is){
    ++i; ++is;
  }
  printf("Found max value of int: %d \n",i);
  printf("limits.h max value of int: %d \n",INT_MAX);

  while (l < ls){
    ++l; ++ls;
  }
  printf("Found max value of long: %ld \n",l);
  printf("limits.h max value of long: %ld \n",LONG_MAX);


  while (uc < ucs){
    ++uc; ++ucs;
  }
  printf("Found max value of uchar: %u \n",uc);
  printf("limits.h max value of uchar: %u \n",UCHAR_MAX);

  while (us < uss){
    ++us; ++uss;
  }
  printf("Found max value of ushort: %u \n",us);
  printf("limits.h max value of ushort: %u \n",USHRT_MAX);

  while (ui < uis){
    ++ui; ++uis;
  }
  printf("Found max value of uint: %u \n",ui);
  printf("limits.h max value of uint: %u \n",UINT_MAX);

  while (ul < uls){
    ++ul; ++uls;
  }
  printf("Found max value of ulong: %lu \n",ul);
  printf("limits.h max value of ulong: %lu \n",ULONG_MAX);

  printf("float.h max value of float: %e \n", FLT_MAX);
  printf("float.h max value of double: %e \n", DBL_MAX);
}
