/* Write a program that reads from the standard input and computes the percentage
 * of characters it find in each of the following categories:
 *
 *      control characters
 *      whitespace characters
 *      digits
 *      lowercase letters
 *      uppercase letters
 *      punctuation characters
 *      non-printable characters
 */

#include <stdio.h>
#include <ctype.h>

int main(void) {
    int total;
    int ctrl_counter;
    int whitespace_counter;
    int digit_counter;
    int lowercase_counter;
    int uppercase_counter;
    int punct_counter;
    int non_print_counter;

    char ch;

    total = ctrl_counter = whitespace_counter = digit_counter = lowercase_counter
        = uppercase_counter = punct_counter = non_print_counter = 0;

    while ((ch = getchar()) != EOF) {
        if (iscntrl(ch))
            ctrl_counter++;
        if (isspace(ch))
            whitespace_counter++;
        if (isdigit(ch))
            digit_counter++;
        if (islower(ch))
            lowercase_counter++;
        if (isupper(ch))
            uppercase_counter++;
        if (ispunct(ch))
            punct_counter++;
        if (!isprint(ch))
            non_print_counter++;

        total++;
    }

    if (total == 0)
        printf("No characters!\n");
    else {
        printf("Total # of characters:\t%d\n", total);
        printf("%% of control characters:\t%.2f\n",
            ctrl_counter * 100.0 / total);
        printf("%% of whitespace characters:\t%.2f\n",
            whitespace_counter * 100.0 / total);
        printf("%% of digit characters:\t\t%.2f\n",
            digit_counter * 100.0 / total);
        printf("%% of lowercase characters:\t%.2f\n",
            lowercase_counter * 100.0 / total);
        printf("%% of uppercase characters:\t%.2f\n",
            uppercase_counter * 100.0 / total);
        printf("%% of punctuation:\t\t%.2f\n",
            punct_counter * 100.0 / total);
        printf("%% of non-printable characters:\t%.2f\n",
            non_print_counter * 100.0 / total);
    }

    return 0;
}
