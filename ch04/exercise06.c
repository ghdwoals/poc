/* Write a program that extracts a substring from a string. The function has
**  the following prototype:
**
**      int substr(char dst[], char src[], int start, int len);
**
** It should copy a string starting at start characters part the beginning
**  of the src array, up to len non-NUL characters should be copied. Function
**  also returns the length of the dst string.
**
** If start specifies a position beyond the end of the src string, or if either
**  start or len are < 0, then dst should be empty.
*/

#include <stdio.h>
#include <string.h>

int substr(char dst[], char src[], int start, int len);
int main(void) {
    int array_length;
    int start;
    int length;

    printf("Enter the length of the string:\t");
    scanf("%d", &array_length);
    char src[array_length];
    printf("Enter the the range of characters to be copied:\n");
    printf("Starting character:\t");
    scanf("%d", &start);
    scanf("%*c");
    printf("Number of characters to copy:\t");
    scanf("%d", &length);
    scanf("%*c");
    char dst[length];
    printf("Enter the string to be copied:\n");
    if (fgets(src, array_length, stdin) != NULL) {
        length = substr(dst, src, start, length);
    }
    printf("Copied string:\t");
    printf("\"%s\"\n", dst);
    printf("Length of copied string:\t%d\n", length);
    return 0;
}

int substr(char dst[], char src[], int start, int len) {
    if ((start > strlen(src)) || start < 0 || len < 0) {
        dst[0] = '\0';
        return 0;
    }

    strncpy(dst, src + start, len);
    dst[len] = '\0';
    return strlen(dst);
}
