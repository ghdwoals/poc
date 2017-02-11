/* Write a function called my_strnchr with this prototype:
 *
 *      char *my_strnchr(char const *str, int ch, int which);
 *
 * The function is similar to strchr except that the third argument specifies
 * which occurrence of the character is desired. For example, if the third
 * argument is one, the function behaves exactly like strchr. If the third
 * argument is two, the function returns a pointer to the second occurrence of ch
 * in the string str.
 */
#include <string.h>

char *my_strnchr(char const *str, int ch, int which) {
    char *location = NULL;
    char *latest = strchr(str, ch);

    while (latest != NULL && --which >= 0) {
        location = latest++;
        latest = strchr(latest, ch);
    }

    return location;
}
