/* Write a function called my_strrchr with this prototype:
 *
 *      char *my_strrchr(char const *str, int ch);
 * 
 * The function is similar to strchr except that it returns a pointer to the last
 * (rightmost) occurrence of the character.
 */
#include <string.h>

char *my_strrchr(char const *str, int ch) {
    char *last;
    char *current;

    last = NULL;

    if (*str != '\0') {
        current = strchr(str, ch);

        while (current != NULL) {
            last = current++;
            current = strchr(current, ch);
        }
    }

    return last;
}
