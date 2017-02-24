/* Write a function with this prototype:
 *
 *      int count_chars(char const *str, char const *chars);
 *
 * The function should look through the first argument and return the number of
 * characters that match characters in the second argument.
 */

#include <string.h>

int count_chars(char const *str, char const *chars) {
    int count = 0;

    // strpbrk(str1, str2) function returns a pointer to the first character in
    // str1 that matches any character in str2.
    // As long as str does not equal NULL, this particular while loop will add 1
    // to the position of str and continue.
    while ((str = strpbrk(str, chars)) != NULL) {
        count += 1;
        str += 1;
    }

    return count;
}
