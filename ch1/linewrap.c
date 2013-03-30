#include <stdio.h>
#define MAXLINE 1000 /*max input line size*/

/*exercise 1.22*/
/*Write a program to ``fold'' long input lines into two or more
shorter lines after the last non-blank characer that occurs before the
n-th column of input.  Make sure your program does something
intelligent with very long lines, and if there are no blanks or tabs
before the specified column.  */

int copy(char to[], char from[], int start);
const int lineWidth = 20;

main() {
  char c;
  int currentCol = 0, lastBlank = -1;
  int i;
  char lineinput[lineWidth+1];

  while ((c = getchar())!=EOF) {
    if (c == '\n') {
      lineinput[currentCol] = '\0';
      printf("%s\n",lineinput);
      lastBlank = -1;
      currentCol = 0;
    }
    else if (c == ' ' || c == '\t') {
      lastBlank = currentCol;
      lineinput[currentCol] = c;
      currentCol++;
    }
    else {
      lineinput[currentCol] = c;
      currentCol++;
    }

    if (currentCol == lineWidth) {
      lineinput[currentCol] = '\0';
      if (lastBlank < 0) {
	printf("%s\n",lineinput);
	currentCol = 0;
      } else {
	lineinput[lastBlank] = '\0';
	printf("%s\n",lineinput);
	currentCol = copy(lineinput,lineinput,lastBlank+1);
      }
      lastBlank = -1;
    }

  }
  return 0;
}

/*copy: copy `from' into `to', beginning at `start'; assume to is big
  enough. Return length of string copied */
int copy(char to[], char from[], int start) {
  int i = start;
  int j = 0;
  while((to[j] = from[i]) != '\0') {
    ++i; ++j;
  }
  return j;
}
