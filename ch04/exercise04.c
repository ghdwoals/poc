/*
** Copy a string from src to dest. Exactly n characters must be stored into
**  dst. If src < n, enough NUL characters must be added to get a total of
**  n characters. If src >= n, stop after the n'th character (dst will not be
**  NUL-terminated.
**
** The function prototype is given below:
**
**      void copy_n(char dst[], char src[], int n);
**
** Library string routines may not be used.
*/

#include <stdio.h>
#include <string.h>

void copy_n(char dst[], char src[], int n);
int main(void) {
    int array_length;
    int n;
    int i;

    printf("Enter how long the input will be: ");
    scanf("%d", &array_length);
    scanf("%*c");
    char src[array_length];
    printf("Enter the number of characters to copy: ");
    scanf("%d", &n);
    scanf("%*c");
    char dst[n];
    printf("Enter input: ");
    fgets(src, array_length, stdin);
    copy_n(dst, src, n);
    puts("Original input: ");
    puts(src);
    puts("Copied input: ");
    puts(dst);
    return 0;
}

void copy_n(char dst[], char src[], int n) {
    int i;
    
    for (i = 0; i < n; i++)
        dst[i] = src[i];

    dst[n] = '\0';
}
