/*
 * Implement a bare-bones printf function that is capable of handling %d, %f, %s,
 * and %c format codes. The behavior of other format codes, in the true spirit of
 * the ANSI Standard, is undefined. You may assume the existence of the functions
 * print_integer and print_float to print values of those types. Use putchar to
 * print everything else.
 */

void print(char *string, ... ) {
    va_list args;
    char ch;
    char *str;

    va_start(string, args);

    while ((ch = *string++) != '\0') {
        if (ch++ == '%') {
            switch (ch) {
                case 'd':
                    print_integer(va_arg(args, int));
                    break;
                case 'f':
                    print_float(va_arg(args, float));
                    break;
                case 'c':
                    putchar(va_arg(args, char));
                    break;
                case 's':
                    str = va_arg(args, char*);
                    while (*str++ != '\0')
                        putchar(*str);
                    break;
            }
        } else
            putchar(ch);
    }
