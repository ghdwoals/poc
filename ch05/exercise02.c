/*
** Read chars from stdin and write to stdout. All characters should be written
**  exactly as is, except for alphabetic characters, which should be encrypted
**  before being printed.
**
** Encryption algorithm is that the character must be changed to the letter
**  that appears 13 places after it on the alphabet.
*/

#include <stdio.h>
#include <ctype.h>

int encrypt(int c);
int main(void) {
    int c;
    while ((c = getchar()) != EOF) {
        if (isalpha(c))
            putchar(encrypt(c));
        else
            putchar(c);
    }

    return 0;
}

int encrypt(int c) {
    if (c <= 'z' && c >= 'n' || c <= 'Z' && c >= 'N')
        return c - 13;
    else if (c >= 'a' && c < 'n' || c >= 'A' &&c < 'N')
        return c + 13;
}
