#include <stdio.h>
#define MAXLINE 1000 /*max input line size*/
#define CUTLEN 80 /*minimum length to print lines*/

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/*exercise 1.17*/
/*print lines longer than CUTLEN, 80 characters by default*/
main() {
  int len;     /*store length for extra-long lines*/
  int thislen; /*current line length*/
  int max; /*maximum length seen so far */
  char line[MAXLINE]; /*current input line*/
  char longline[MAXLINE]; /*temprorarily store first part of a long
			    line in case it passes the cut*/
  char isLongLine = 0; /*program state - are we splitting a long line to
		       copy it?*/
  max = 0, len = 0;
  while ((thislen = getline(line, MAXLINE)) > 0) {
    len += thislen;
    if (thislen == MAXLINE-1) { /*limited by maxline size */
      if (!isLongLine) {
	isLongLine = 1;
	copy(longline, line); /*only copy the first part of long
				lines*/
      }
      continue;
    }
    if (len > CUTLEN) {
      if (!isLongLine) /*only copy the first part of long lines*/
	printf("%s", line);
      else
	printf("%s\n", longline);

    }
    len = 0;
    isLongLine = 0;
  }
  return 0;
}

/*getline: read a lone into s, return length */
int getline(char s[], int lim) {
  int c, i;
  for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

/*copy: copy `from' into `to'; assume to is big enough */
void copy(char to[], char from[]) {
  int i;

  i = 0;
  while((to[i] = from[i]) != '\0')
    ++i;
}
