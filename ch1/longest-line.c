#include <stdio.h>
#define MAXLINE 100 /*max input line size*/

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/*exercise 1.16*/
/*print longest input line - rewrite main function to deal with lines
  longer than MAXLINE*/
main() {
  int len;     /*store length for extra-long lines*/
  int thislen; /*current line length*/
  int max; /*maximum length seen so far */
  char line[MAXLINE]; /*current input line*/
  char longline[MAXLINE]; /*temprorarily store first part of a long
			    line in case it is the longest*/
  char longest[MAXLINE]; /*longest line saved here*/
  char longLine = 0; /*program state - are we splitting a long line to
		       copy it?*/
  max = 0, len = 0;
  while ((thislen = getline(line, MAXLINE)) > 0) {
    len += thislen;
    if (thislen == MAXLINE-1) { /*limited by maxline size */
      if (!longLine) {
	longLine = 1;
	copy(longline, line); /*only copy the first part of long
				lines*/
      }
      continue;
    }
    if (len > max) {
      max = len;
      if (!longLine) /*only copy the first part of long lines*/
	copy(longest, line);
      else {
	copy(longest, longline);
      }
    }
    len = 0;
    longLine = 0;
  }
  if (max > 0) /*there was a line*/
    printf("Length: %i\n", max);
    printf("%s\n", longest);
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
