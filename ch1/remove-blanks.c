#include <stdio.h>
#define MAXLINE 1000 /*max input line size*/
#define CUTLEN 80 /*minimum length to print lines*/

int getline(char line[], int maxline);
int isblank(char check[]);
void copynoblank(char to[], char from[]);

/*exercise 1.18*/
/*Write a program to remove trailing blanks and tabs from each line of
  input, and to delete entirely blank lines*/
main() {
  int len;     /*store length for extra-long lines*/
  int longline;
  char line[MAXLINE]; /*current input line*/
  len = 0;
  longLine = 0;

  while ((len = getline(line, MAXLINE)) > 0) {
    if (len == MAXLINE-1) { /*limited by maxline size */
      copynoblank(longline, line); /*only copy the first part of long
				lines*/
      }
      continue;
    }
  if (!isblank(line)) {
    if (!longLine) /*only copy the first part of long lines*/
      printf("%s", line);
    else
      printf("%s\n", longline);
    
  }
  len = 0;

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

/*isblank: return 1 if the newline-terminated character array is not
  entirely blank*/
int isblank(char check[]) {
  int i = 0;
  if (check[i]=='\n') return 1;

  while(check[i]!='\n') {
    if (check[i]==' ' || check[i]=='\t') return 1;
    i++;
  }
  return 0;
}

/*copynoblank: copy `from' into `to'; assume to is big enough.  Remove
  trailing blanks */
void copynoblank(char to[], char from[]) {
  int i;

  i = 0;
  while(from[i] != '\0') {
    if (from[i] != ' ' && from[i] != '\t' )
      to[i] = from[i];
    ++i;
  }
}
