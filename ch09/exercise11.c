/* Write a program that scans the standard input and counts the number of times
 * the word "the" appears. The comparison should be case independent, so "The"
 * and "THE" don't count. You may assume that words will be separated from each
 * other by one or more whitespace characters and that the input lines will be
 * less than 100 characters in length. The count should be written to the
 * standard input.
 */
#include <stdio.h>
#include <string.h>

#define LENGTH 100

int main(void) {
    char string[100];
    char *last;
    int count;
    printf("Enter a string.\nThe number of times the word 'the' appears will "
        "be returned to you.\n");
    fgets(string, 100, stdin);

    for (count = 0, last = strstr(string, "the");
        last != '\0';
        last = strstr(last + 1, "the"))
        count += 1;

    printf("Number of 'the's:\t%d\n", count);

    return 0;
}

