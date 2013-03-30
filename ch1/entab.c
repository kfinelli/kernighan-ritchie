#include <stdio.h>
#define MAXLINE 1000 /*max input line size*/

/*exercise 1.21*/
/*Write a program entab that replaces strings of blanks by the minumum
  number of tabs and blanks to space to the next tab stop.  Use the
  same tab stops as for detab.

tabstopwidth=5
tabs :0    0    0    0
dist :543215432154321
colno:0123456789
*/

int distToTabStop(int colNo);
const int tabStopWidth = 8;

main() {
  char c;
  int currentCol = 0, spacesFound = 0;
  int i;

  while ((c = getchar())!=EOF) {
    if (spacesFound>0 && c != ' ') {
      if (spacesFound!=1) {
	/*if only one space if found by itself, let it be*/
	while (distToTabStop(currentCol-spacesFound) <= spacesFound) {
	  putchar('\t');
	  spacesFound -= distToTabStop(currentCol-spacesFound);
	}
      }
      while (spacesFound>0) {
	putchar(' ');
	spacesFound--;
      }
    }
    if (c == '\n') {
      putchar(c);
      currentCol = 0;
    }
    else if (c == ' ') {
      spacesFound++;
      currentCol++;
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
