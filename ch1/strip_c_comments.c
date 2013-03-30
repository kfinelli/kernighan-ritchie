#include <stdio.h>

/*exercise 1.23*/
/*Write a program to remove comments from a c program.  */

/*program states*/
const int NOMINAL = 0;
const int QUOTE = 1;
const int CHAR = 2;
const int COMMENT = 3;

main() {
  int state = NOMINAL;
  char c, prev = '\0';

  while ((c = getchar())!=EOF) {
    if (state == COMMENT) {
      if (c == '/' && prev == '*') {
	state = NOMINAL;
	prev = '\0';
      }
      continue;
    }
    if (c == '*' && prev == '/') {
      if (state == NOMINAL) {
	state = COMMENT;
	prev = c;
	continue;
      }
    }
    else if (c == '"') {
      if (state == NOMINAL) { 
	state = QUOTE;
      }
      else if (state == QUOTE) {
	state = NOMINAL;
      }
    }
    else if (c == '\'') {
      if (state == NOMINAL ) {
	state = CHAR;
      }
      else if (state == CHAR && prev != '\\') {
	state = NOMINAL;
      }
    }
    else if (c == '/') {
      prev = c;
      continue;
    }
    if (prev == '/') {
      putchar(prev);
    }
    putchar(c);
    prev = c;
  }
  return 0;
}

