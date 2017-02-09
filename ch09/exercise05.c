/* Write the function
 *
 *      void my_strncat(char *dst, char *src, int dest_len);
 * 
 * which concatenates the string in src to the end of the string in dst, making
 * sure not to overflow the dst array, which is dest_len bytes long. Unlike
 * strncat, this function takes into account the length of the string already in
 * dst, thereby insuring that the array bounds are not exceeded.
 */
#include <string.h>
#include <stdio.h>

void my_strncat(char *dst, char *src, int dest_len) {
    int length;

    length = strlen(dst);

    dest_len = dest_len - length + 1;

    if (dest_len > 0)
        strncat(dst + length, src, dest_len);
    else
        printf("Destination buffer is too small to hold string.\n");
}
