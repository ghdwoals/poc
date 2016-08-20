/*
** Read chars from stdin and write to stdout. All uppercase characters should be
**  converted to lowercase.
**
** tolower() library function used.
*/

#include <stdio.h>
#include <ctype.h>

int main(void) {
    int c;
    while ((c = getchar()) != EOF)
        putchar(tolower(c));

    return 0;
}
