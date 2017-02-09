/* Write a strcpy replacement called my_strcpy_end that returns a pointer to the
 * end of the destination string (that is, a pointer to the NULL byte) rather
 * than a pointer to the beginning of the destination string.
 */

/* Very, very minimal bounds-checking functionality.
 */
#include <string.h>
#include <stdio.h>

char *my_strcpy_end(char *dst, const char *src) {
    if (strlen(src) > strlen(dst))
        printf("Source string is too big for destination buffer.\n");
    else
        strcpy(dst, src);

    return dst + strlen(dst);
}
