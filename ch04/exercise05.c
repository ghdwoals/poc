/* Read standard input line by line. For each set of two or more identical,
**  adjacent lines in the file, one line from the set should be printed out.
**  Assume that lines in the file do not exceed 128 characters (127 characters
**  plus one newline).
**
** Book instructs student to use gets(). fgets() is used instead.
*/

#include <stdio.h>
#include <string.h>

#define STRING_LENGTH 128

int main(void) {
    char previous_line[STRING_LENGTH];
    char input[STRING_LENGTH];
    int repeat = 0;

    printf("Enter a line (127 characters + 1 newline character):\n");
    while (fgets(previous_line, STRING_LENGTH, stdin) != NULL) {
        while (fgets(input, STRING_LENGTH, stdin) != NULL) {
            if (strcmp(previous_line, input) == 0 && repeat == 0) {
                strncpy(previous_line, input, STRING_LENGTH);
                printf("%s", input);
                repeat = 1;
            } else if (strcmp(previous_line, input) != 0) {
                strncpy(previous_line, input, STRING_LENGTH);
                repeat = 0;
            }
        }
    }

    return 0;
}
