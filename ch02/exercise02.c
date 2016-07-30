/*
** Write a program that will read C source code from the standard input and
**  ensure that the braces are paired correctly. Note: you need not worry about
**  braces that appear within comments, string literals, or character constants.
*/

#include <stdio.h>

/*
** Random brace here: {
*/

// Another: }

#define BRACE   {
#define BRACE2  '{'

int main(void) {
    int in_comment = 0;
    int braces = 0;
    int open_braces = 0;
    int close_braces = 0;
    int ch;

    while ((ch = getchar()) != EOF) {
        if (ch == '/') {
            ch = getchar();
            if (ch == '*' && in_comment == 0)
                in_comment = 1;
            if (ch == '/') {
                while ((ch = getchar()) != '\n')
                    ;
            }
        } else if (ch == '*') {
            ch = getchar();
            if (ch == '/' && in_comment)
                in_comment = 0;
        }

        if (ch == '\"' && in_comment)
            in_comment = 0;
        else if (ch == '\"' && in_comment == 0)
            in_comment = 1;

        if (ch == '\'') {
            ch = getchar();
            if (ch == '{' || ch == '}')
                continue;
        }

        if (ch == '#')
            while ((ch = getchar()) != '\n')
                continue;

        if (in_comment)
            continue;
        
        if (ch == '{') {
            braces++;
            open_braces++;
        }
        else if (ch == '}') {
            braces--;
            close_braces++;
        }
    }

    if (braces != 0)
        printf("There are missing braces in your source code.\n");
    else
        printf("There are no missing braces in your source code.\n");

    printf("Opening braces:\t%d\n", open_braces);
    printf("Closing braces:\t%d\n", close_braces);

    return 0;
}
