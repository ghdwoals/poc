/*
** Chapter 1, Exercise 4
** Write a program that reads input lines one by one until end of file is
**  reached, determines the length of each input line, and then prints out only
**  the longest line that was found. To simplify matters, you may assume that no
**  input line will be longer than 1000 characters.
*/

#include <stdio.h>
#include <string.h>

#define MAX_INPUT 1000

int main(void) {
    char longest_line[MAX_INPUT];           // array to store longest line
    char line[MAX_INPUT];                   // array to store current line
    unsigned int longest_line_length = 0;
    int count = 0;                          // character counter
    int ch;                                 // input character

    while ((ch = getchar()) != EOF && count < MAX_INPUT) {
        if (ch == '\n') {
            if (strlen(line) > longest_line_length) {
                line[count] = '\0';
                longest_line_length = strlen(line);
                strncpy(longest_line, line, MAX_INPUT);
            }
            count = 0;
        } else {
            line[count] = ch;
            count++;
        }
    }

    printf("Longest line: %s\n", longest_line);
    printf("Number of characters in longest line: %ld\n",
        strlen(longest_line));

    return 0;
}
