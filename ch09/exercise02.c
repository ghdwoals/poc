/* Write a function called my_strnlen that is similar to strlen but is able to
 * handle unterminated strings created with the strn--- functions. You will have
 * to pass an argument containing the size of the array that holds the string to
 * be tested.
 */

int my_strnlen(char *string, int size) {
    int i;

    for (i = 0; i < size; i++)
        if (*string++ == '\0')
            break;

    return i;
}
