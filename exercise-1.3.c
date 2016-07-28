/*
** Chapter 1, Exercise 3
** Write a program that reads characters from the standard input and writes them
**  to the standard output. It should also compute a checksum and write it out 
**  after the characters.
**
** The checksum is computed in a signed char variable that is initialized to -1.
**  As each character is read from the standard input, it is added to the
**  checksum. Any overflow from the checksum variable is ignored. When all of
**  the characters have been written, the checksum is then written as a decimal
**  integer, which may be negative. Be sure to follow the checksum with a
**  new‐line.
**
** On computers that use ASCII, running your program on a file containing the
**  words "Hello world!" followed by a newline should produce the following
**  output:
**
**      Hello world!
**      102
*/

#include <stdio.h>
int main(void) {
    signed char checksum = -1;
    char ch;

    while ((ch = getchar()) != EOF) {
        putchar(ch);
        checksum += ch;
    }

    printf("%d\n", checksum);

    return 0;
}
