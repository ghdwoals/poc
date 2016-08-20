/*
** Write a function that removes excess white space from a string. The function
**  should have this prototype:
**
**      void deblank(char string[]);
**
** Every run of one or more white space characters should be replaced by one
**  space character. The string should be null-terminated.
**
** Reek's solution involves using a second function to determine if a character
**  is whitespace (myself, I got smart [read: lazy] and simply used isspace()
**  from ctype.h. Reek also used pointers in his solution, while I opted to
**  use array subscripts.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void deblank(char string[]);
int main(void) {
    int length;
    printf("Enter length of string: ");
    while ((scanf("%d", &length)) == 1) {
        scanf("%*c");
        char string[length];
        printf("Enter string:\t");
        fgets(string, length, stdin);
        deblank(string);
        printf("New string:\t%s\n", string);
        printf("Enter length of string: ");
    }
    return 0;
}

void deblank(char string[]) {
    int i;
    int j;
    int whitespace = 0;
    int length = strlen(string);

    for (i = 0, j = 0; i < length; i++) {
        if (!(isspace(string[i]))) {
            string[j] = string[i];
            j++;
            whitespace = 0;
        } else if (isspace(string[i])) {
            if (whitespace == 0) {
                string[j] = ' ';
                j++;
                whitespace = 1;
            } else continue;
        }
    }

    string[j] = '\0';
}
