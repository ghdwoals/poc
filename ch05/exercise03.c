/*
** Using the function:
**
**      unsigned int reverse_bits(unsigned int value);
**
**  return the number constructed by reversing the bit order from left to
**  right. For example, on a 32-bit machine, 25 contains the bits:
**
**      00000000000000000000000000011001
**
** The function should return:
**
**      11001000000000000000000000000000
**
*/
#include <stdio.h>
#include <inttypes.h>
#include <limits.h>

unsigned int reverse_bits(unsigned int value);
int main(void) {
    uint32_t num;

    printf("Enter the unsigned number:\t");
    while (scanf("%d", &num) == 1) {
        printf("Number reversed:\t\t%lu\n", (unsigned long)reverse_bits(num));
        printf("Enter another unsigned number:\t");
    }

    return 0;
}

unsigned int reverse_bits(unsigned int value) {
    uint32_t reverse = 0;
    uint32_t x = 1 << ((sizeof(uint32_t) * CHAR_BIT) - 1);

    while (x > 0) {
        if (value % 2 == 1)
            reverse += x;
        value >>= 1;
        x >>= 1;
    }

    return reverse;
}
