#include <stdio.h>
#define MAXLINE 1000
#define COLSIZE 30   /*width of columns to create*/

/*exercise 1.22*/
/*Write a program to fold long input lines into two or more shorter
  lines after the last non-blank character that occurs before the n-th
  column of input.  Make sure your program does something intelligent
  with very long lines, and if there are no blanks or tabs before the
  specified column.

*/

void dumpbuf(char *buf, size_t bufIdx) {
  size_t tempIdx = 0;
  while (tempIdx < bufIdx) {
    putchar(buf[tempIdx]);
    ++tempIdx;
  }
  
}

main() {
  char c;
  char buf[MAXLINE];
  int currentCol = 0;
  size_t bufIdx = 0;
  int i;

  while ((c = getchar())!=EOF) {
    if (c == ' ' || c == '\n') {
      if ((currentCol >= COLSIZE)) {
	dumpbuf(buf, bufIdx);
	putchar('\n');
	currentCol = 0;
	bufIdx = 0;
      }  else {
	dumpbuf(buf, bufIdx);
	putchar(c);
	currentCol++;
	if (c=='\n') currentCol = 0;
	bufIdx = 0;
      }
    }
    else {
      buf[bufIdx] = c;
      bufIdx++;
      currentCol++;
    }
  }
  dumpbuf(buf, bufIdx);
  return 0;
}
