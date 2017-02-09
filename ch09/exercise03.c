/* Write a function called my_strcpy that is similar to strcpy but will not
 * overflow the destination array. The result of the copy must be a true string.
 */

#include <string.h>

void my_strcpy(char *dst, const char *src, int size) {
    strncpy(dst, src, size);
    dst[size - 1] = '\0';
}
