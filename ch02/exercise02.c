#include <stdio.h>

int main(void) {
    int in_comment = 0;
    int braces = 0;
    int open_braces = 0;
    int close_braces = 0;
    int ch;

    while ((ch = getchar()) != EOF) {
        if (ch == '/') {
            ch = getchar();
            if (ch == '*')
                in_comment = 1;
        } else if (ch == '*') {
            ch = getchar();
            if (ch == '/')
                in_comment = 0;
        }

        if (in_comment)
            continue;

        if (ch == '{') {
            braces++;
            open_braces++;
        }
        if (ch == '}') {
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
