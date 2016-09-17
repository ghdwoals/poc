#include <stdio.h>
#include <inttypes.h>
#include <limits.h>

/*
** Write a function that will store a given value into specified bit positions
**  of an integer. It should have this prototype:
*/

int store_bit_field(int original_value, int value_to_store,
    unsigned starting_bit, unsigned ending_bit);

/*
** Assume that the bits in an integer are numbered from right to left. Thus,
**  the starting bit position may not be less than the ending bit position.
** To illustrate:
**
** Original |   Value   |   Ending  |   Starting    |   Return value
** Value    | to Store  |    Bit    |     Bit       |
** -----------------------------------------------------------------
** 0x0      |   0x1     |     4     |      4        |   0x10
** 0xffff   |   0x123   |     15    |      4        |   0x123f
** 0xffff   |   0x123   |     13    |      9        |   0xc7ff
** -----------------------------------------------------------------
*/

/*
** Method:
**  -- Create a mask setting 1s for the field length comprising starting bit to
**      ending bit
**  -- Zero-out the rest of the value to be stored
**  -- Shift the mask to the starting bit, get its one's-complement, and zero-
**      out the specified field
**  -- Shift the value to be stored to the specified starting bit
**  -- OR the specified value and the original value
*/

/*
** This program compiled on a CentOS 7.2.1511 machine, gcc version 4.8.5.
*/

int main(void) {
    int16_t num;
    int16_t value_to_store;
    int16_t final_value;
    unsigned int start_bit;
    unsigned int end_bit;

    printf("Enter original number:\t");
    while (scanf("%" SCNd16, &num) == 1) {
        printf("Enter value to store:\t");
        while (scanf("%" SCNd16, &value_to_store) == 1) {
            printf("Enter starting bit:\t");
            scanf("%d", &start_bit);
            printf("Enter ending bit:\t");
            scanf("%d", &end_bit);
            if (start_bit < 0 || end_bit < 0 || start_bit > end_bit ||
                end_bit > 15) {
                printf("One of the bits entered is invalid.\n");
                break;
            } else {
                final_value = store_bit_field(num, value_to_store, start_bit,
                    end_bit);
            }
            printf("Final value (hex):\t0x%08" PRIx16 "\n", final_value);
            break;
        }
        printf("Enter another number:\t");
    }

    return 0;
}

int store_bit_field(int original_value, int value_to_store,
    unsigned starting_bit, unsigned ending_bit) {

    int i;
    int16_t mask;
    int16_t modified_value;

    for (i = 0; i < ending_bit - starting_bit + 1; i++) {
        mask |= 1 << i;
    }

    modified_value = (mask & value_to_store) << starting_bit;
    original_value &= ~(mask << starting_bit);
    return (modified_value |= original_value);
}
