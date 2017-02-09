/* Write a function called my_strcat that is similar to strcat but will not
 * overflow the destination array. The result must be a true string.
 */

/* Will segfault if destination string is a string literal that is smaller in
 * length than the size provided.
 */
#include <string.h>
#include <stdio.h>

void my_strcat(char *dst, const char *src, int size) {
    int src_len = strlen(src);
    int dst_len = strlen(dst);

    int length = --size - dst_len - src_len;

    if (length > 0)
        strncat(dst, src, size);
    else
        printf("Destination buffer too small to hold entire string.\n");

    // printf("Length of src+dst:\t%d\n", src_len + dst_len);
    // printf("Length of new dst:\t%d\n", strlen(dst));
}
