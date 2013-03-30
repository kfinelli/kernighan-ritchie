#include <stdio.h>
#define MAXLINE 1000 /*max input line size*/

/*exercise 1.19*/
/*Write a function reverse(s) that reverses the character string s.
  Use it to write a program that reverses its input a line at a time*/

int getline_stdin(char line[], int maxline);
void reverse_line(char s[]);

main() {
  char line[MAXLINE]; /*current input line*/

  while (getline_stdin(line, MAXLINE) > 0) {
    reverse_line(line);
    printf("%s", line);
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

/* reverse: reverse a character string */
void reverse_line(char s[]) {
  int begin = 0, end = 0;
  char tmp;
  while (s[end] != '\0' & s[end] !='\n') {
    end++;
  }
  end--;
  while (end-begin>0) {
    tmp = s[end];
    s[end] = s[begin];
    s[begin] = tmp;
    begin++; end--;
  }
}
