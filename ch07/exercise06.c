#include <string.h>
#include <ctype.h>

/*
 * Write a function
 */

void written_amount(unsigned int amount, char *buffer);

/* 
 * that converts the value in amount to words and stores them in the buffer. This
 * function might be used in a program that prints checks. For example, if value
 * is 16,312, then the string
 *
 *      SIXTEEN THOUSAND THREE HUNDRED AND TWELVE
 *
 * should be stored in the buffer. It is the caller's responsibility to make the
 * buffer large enough.
 *
 * Some values can be printed in two different ways. For example, 1,200 could be
 * either ONE THOUSAND TWO HUNDRED or TWELVE HUNDRED. You may convert these
 * values whichever way you wish.
 */

/*
 * For simplicity's sake, this program uses strcpy and strcat.
 * Program can also be implemented using pointers (obviously), instead of array
 * subscripts.
 * Function does not check for integer overflow. Onus is on the programmer using
 * this function.
 */

void process_group(unsigned int amount, unsigned int magnitude, char *buffer);

char *numbers[] = {
    "",
    "ONE ",
    "TWO ",
    "THREE ",
    "FOUR ",
    "FIVE ",
    "SIX ",
    "SEVEN ",
    "EIGHT ",
    "NINE ",
    "TEN ",
    "ELEVEN ",
    "TWELVE ",
    "THIRTEEN ",
    "FOURTEEN ",
    "FIFTEEN ",
    "SIXTEEN ",
    "SEVENTEEN ",
    "EIGHTEEN ",
    "NINETEEN ",
};

char *tens[] = {
    "",
    "",
    "TWENTY ",
    "THIRTY ",
    "FORTY ",
    "FIFTY ",
    "SIXTY ",
    "SEVENTY ",
    "EIGHTY ",
    "NINETY ",
};

char *magnitudes[] = {
    "",
    "THOUSAND ",
    "MILLION ",
    "BILLION ",
};

void process_group(unsigned int amount, unsigned int magnitude, char *buffer) {
    int number;
    if ((number = amount / 1000) > 0) {
        process_group(number, magnitude + 1, buffer);
    }

    amount %= 1000;

    if (amount / 100 > 0) {
        strcat(buffer, numbers[amount / 100]);
        strcat(buffer, "HUNDRED AND ");
    }
    if (amount % 100 > 20) {
        strcat(buffer, tens[(amount % 100) / 10]);
        strcat(buffer, numbers[amount % 10]);
    } else {
        strcat(buffer, numbers[amount % 100]);
    }

    strcat(buffer, magnitudes[magnitude]);
}

void written_amount(unsigned int amount, char *buffer) {
    int magnitude = 0;
    int remainder = amount;
    if (amount == 0)
        strcpy(buffer, "ZERO ");
    else {
        strcpy(buffer, "");
        process_group(amount, magnitude, buffer);
    }
    buffer[strlen(buffer)] = '\0';
}
