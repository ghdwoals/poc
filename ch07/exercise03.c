#include <string.h>
#include <ctype.h>

/*
** Write a function for the following prototype:
*/

int ascii_to_integer(char *string);

/*
** The string argument must contain one or more digits, and the function should
**  convert those digits to an integer and return the result. If any nondigit
**  characters are found, return the value 0 instead. Do not worry about
**  arithmetic overflow. Hint: The technique is simple: for each digit you find,
**  multiply the value you have so far and then add the value represented by the
**  new digit.
*/

int ascii_to_integer(char *string) {
    char i;
    int number;

    for (i = 0, number = 0; i < strlen(string); i++) {
        number *= 10;
        if (!(isdigit(*(string + i))))
            return 0;
        else
            number += *(string + i) - '0'; // creates an int out of the char
    }

    return number;
}
