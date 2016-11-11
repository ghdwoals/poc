/*
 * Write a function called max_list that examines an arbitrary number of integer
 * arguments and returns the largest of them. The arguments will be terminated by
 * a value that is less than zero.
 */

#include <stdarg.h>

int max_list(int num, ...) {
    va_list args;
    int largest = 0;
    int cur_num;

    if (num >= 0) {
        largest = num;
        va_start(args, num);
        while ((cur_num = va_arg(args, int)) >= 0)
            if (cur_num > largest)
                largest = cur_num;
        va_end(args);
    }
    return largest;
}
