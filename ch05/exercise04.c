#include <stdio.h>
#include <string.h>

/* Write a set of functions that implement an array of bits. The functions
 * should have the following prototypes:
 */

void set_bit(char bit_array[], unsigned bit_number);
void clear_bit(char bit_array[], unsigned bit_number);
void assign_bit(char bit_array[], unsigned bit_number, int value);
int test_bit(char bit_array[], unsigned bit_number);

/* The first argument in each of these functions is a character array in which
 * the bits are actually stored. The second argument identifies the bit to be
 * accessed; it is up to the caller to ensure that this value is not too large
 * for the array being used.
 *
 * The first function sets the specified bit to one, and the second clears it.
 * The third function sets the bit to zero if the value is zero, otherwise it
 * sets the bit to one. The last funtion returns true if the specified bit is
 * nonzero, else false.
 */

/* All functions will be tested accordingly.
 * Assuming a bit array is an array of 1s and 0s.
 * Also assuming that bit number that is entered must be decremented by one to
 * get index in bit_array.
 */
void set_bit(char bit_array[], unsigned bit_number) {
    if (bit_number > strlen(bit_array) - 1)
        printf("Invalid bit number.\n");
    else
        bit_array[bit_number - 1] = '1';
}

void clear_bit(char bit_array[], unsigned bit_number) {
    if (bit_number > strlen(bit_array) - 1)
        printf("Invalid bit number.\n");
    else
        bit_array[bit_number - 1] = '0';
}

void assign_bit(char bit_array[], unsigned bit_number, int value) {
    if (bit_number > strlen(bit_array) - 1)
        printf("Invalid bit number.\n");
    else
        if (value == 0)
            bit_array[bit_number - 1] = '0';
        else
            bit_array[bit_number - 1] = '1';
}

int test_bit(char bit_array[], unsigned bit_number) {
    if (bit_number > strlen(bit_array) - 1)
        printf("Invalid bit number.\n");
    else
        if (bit_array[bit_number - 1] != '0')
            return 1;
        else
            return 0;
}
