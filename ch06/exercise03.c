/* 
 * Write the function reverse_string, whose prototype is shown below:
 */

void reverse_string(char *string);

/* 
 * The function reverses the characters in the argument string. Use pointers
 * rather than subscripts, and do not use any of the C library string functions.
 * Hint: there is no need to declare a local array to temporarily hold the
 * argument string.
 */

/*
 * No trailing newline.
 */

/*
 * Several ways to accomplish this, this is just one. Another method is to
 * declare a pointer to the end of the string and then increment and decrement
 * away. It basically accomplishes the same thing as this function. That version
 * is found in exercise03.b.c.
 */

void reverse_string(char *string) {
    char temp;
    int str_len = 0;
    int i;

    if (string == 0 || *string == '\0')
        return;

    while (*(string + str_len) != '\0') 
        str_len++;

    for (i = 0, str_len -= 1; i < str_len; i++, str_len--) {
        temp = *(string + i);
        *(string + i) = *(string + str_len);
        *(string + str_len) = temp;
    }
}
