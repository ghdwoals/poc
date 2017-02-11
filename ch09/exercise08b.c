/* I wanted to add Kenneth Reek's for its lack of verbosity (aka simplicity).
 */
#include <string.h>
#include <stdio.h>

char *my_strnchr(char const *str, int ch, int which) {
    char *answer = NULL;

    while (--which >= 0 && (answer = strchr(str, ch)) != NULL)
        str = answer + 1;

    return answer;
}
