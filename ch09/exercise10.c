/* Write this function:
 *
 *      int palindrome(char *string);
 *
 * which returns a true value if the argument string is a palindrome and false
 * otherwise. A palindrome is a string that reads the same forwards and
 * backwards. The function should ignore all nonalphabetic characters, and
 * character comparisons should be case independent.
 */

#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int palindrome(char *string) {
    char *beginning = string;
    char *end = string + strlen(string) - 1;

    while (beginning <= end) {
        while (!isalpha(*beginning))
            beginning += 1;
        while (!isalpha(*end))
            end -= 1;

        if (toupper(*beginning) == toupper(*end)) {
            beginning += 1;
            end -= 1;
        }
        else return false;
    }

    return true;
}
