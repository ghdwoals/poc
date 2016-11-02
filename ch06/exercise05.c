/*
** Modify the Sieve of Eratosthenes program in the previous program so that it
** uses an array of bits rather than characters, using the big array functions
** developed in the Chapter 5 programming exercises. This change makes the
** program even more space efficient, at a cost of time efficiency. What is the
** largest prime number you can compuete in this manner on your system?
*/

#include <stdio.h>

#define MAX 1000

void isprime(int *sieve, int i, int j);

int main(void) {
    int sieve[MAX];
    int numbers[MAX];
    int i;
    int j;
    int primes = 0;
    int largest = 2;

    for (i = 0, j = 0x0002; i < MAX; i++, j++)
        *(sieve + i) = j;

    for (i = 0, j = 0x0002; i < MAX; i++, j++)
        isprime(sieve, i, j);

    printf("List of primes:\n");
    for (i = 0, j = 1; i < MAX; i++)
        if (*(sieve + i))
            printf("[%04d]:\t%d\n", j++, *(sieve + i));

    for (i = 0; i < MAX; i++)
        if (*(sieve + i)) {
            primes++;
            largest = *(sieve + i);
        }

    printf("\n");
    printf("Total # of primes:\t%d\n", primes);
    printf("Largest prime between 2 and 1001:\t%d\n", largest);

    return 0;
}

void isprime(int *sieve, int i, int j) {
    while (i + j < MAX) {
        i += j;
        *(sieve + i) &= 0x0000;
    }
}
