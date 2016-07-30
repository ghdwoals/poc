/*
** Write a program that will read C source code from the standard input and
**  ensure that the braces are paired correctly. Note: you need not worry about
**  braces that appear within comments, string literals, or character constants.
*/

/*
** Note that this program is not sophisticated enough (yet, anyway) to
**  tell the user what lines any stray braces occur on. Maybe I will work on
**  that in the future for practice.
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
    // generic variable to denote whether or not the brace is within quotes,
    // comments, or preprocessor directives
    int braces = 0;         // total number of relevant braces
    int open_braces = 0;    // total number of opening braces
    int close_braces = 0;   // total number of closing braces
    int ch;                 // character from standard input

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
