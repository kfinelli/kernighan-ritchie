#include <stdio.h>
#define MAXLINE 1000 /*max input line size*/
#define CUTLEN 80 /*minimum length to print lines*/

int getline_stdin(char line[], int maxline); /*note, these function
					       names had to be changed
					       to comile on my
					       laptop*/
int isblankline(char check[]);
void copynoblank(char to[], char from[]);

/*exercise 1.18*/
/*Write a program to remove trailing blanks and tabs from each line of
  input, and to delete entirely blank lines.  Doesn't really handle
  extra-long lines very well*/
main() {
  char line[MAXLINE]; /*current input line*/
  char noBlankLine[MAXLINE];

  while (getline_stdin(line, MAXLINE) > 0) {
    if (!isblankline(line)) {
      copynoblank(noBlankLine,line);
    }
    printf("%s", noBlankLine);
  }
  return 0;
}

/*getline: read a lone into s, return length */
int getline_stdin(char s[], int lim) {
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

/*isblankLine: return 1 if the string is entirely blank*/
int isblankline(char check[]) {
  int i = 0;

  while(check[i]!='\0') {
    if (check[i] != '\n' && check[i]!=' ' && check[i]!='\t') return 0;
    i++;
  }
  return 1;
}

/*copynoblank: copy `from' into `to'; assume to is big enough.  Remove
  trailing blanks */
void copynoblank(char to[], char from[]) {
  int i, iFirstBlank;
  int isBlank;
  i = 0; iFirstBlank = MAXLINE;
  isBlank = 0;
  while((to[i] = from[i]) != '\0') {
    if (from[i]==' ' || from[i]=='\t') {
      if (!isBlank)
	iFirstBlank = i;
      isBlank = 1;
    } else if (isBlank && from[i]!='\n') {
      isBlank = 0;
    }
    ++i;
  }
  if (isBlank) {
    to[iFirstBlank] = '\n';
    to[++iFirstBlank] = '\0';
  }
}
