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
 * Function tested on a CentOS 7 box in conjunction with simple test.c program
 * using scanf() to obtain string.
 */

void reverse_string(char *string) {
    char *end;
    char temp;

    for (end = string; *end != '\0'; end++)
        ;

    end -= 1;

    while (string < end) {
        temp = *string;
        *string++ = *end;
        *end-- = temp;
    }
}
