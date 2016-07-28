/*
** Chapter 1, Exercise 2
** Write a program that reads lines from the standard input.
**  Each line is printed on the standard output preceded by its line number.
**  Try to write the program so that it has no built‐in limit on how long a line
**  it can handle.
*/

#include <stdio.h>
int main(void) {
    char ch;
    int lines = 0;
    int new_line = 1;

    while ((ch = getchar()) != EOF) {
        if (new_line) {
            lines++;
            printf("%d: ", lines);
            new_line = 0;
        }
        putchar(ch);
        if (ch == '\n')
            new_line = 1;
    }

    return 0;
}
