#include <stdio.h>
#define MAXLINE 1000 /*max input line size*/

/*exercise 1.20*/
/*Write a program detab that replaces tabs in the input with the
  proper number of blanks to space to the next tab stop.  Asume a
  fixed set of tab stops, say every n columns.  Should n be a variable
  or smbolic parameter?

tabstopwidth=5
tabs :0    0    0    0
dist :543215432154321
colno:0123456789
*/

int distToTabStop(int colNo);
const int tabStopWidth = 8;

main() {
  char c;
  int currentCol = 0;
  int i;

  while ((c = getchar())!=EOF) {
    if (c == '\n') {
      putchar(c);
      currentCol = 0;
    }
    else if (c == '\t') {
      int dist = distToTabStop(currentCol);
      for (i = 0; i < dist; i++) {
	putchar(' ');
	currentCol++;
      }
    }
    else {
      putchar(c);
      currentCol++;
    }
  }
  return 0;
}

/*distToTabStop: returns how many columns until the next column from
  colNo*/
int distToTabStop(int colNo) {
  return tabStopWidth - (colNo % tabStopWidth);
}
