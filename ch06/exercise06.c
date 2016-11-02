/*
** Are there as many large prime numbers as there are small ones?
*/

/*
** For sake of simplicity, I have DEFINEd MAX to be 50000 numbers, and
** ranges of 1000 numbers for output. These numbers can be easily changed.
*/

#include <stdio.h>
#include <limits.h>

#define MAX 50000
#define DIV 1000

void isprime(unsigned int *primes, unsigned int i, unsigned int j);
void nprimes(unsigned int *primes, unsigned int div, unsigned int max);

int main(void) {
    unsigned int primes[MAX];
    unsigned int i;
    unsigned int j;
    unsigned int primenums = 0;

    for (i = 0, j = 2; i < MAX; i++, j++)
        *(primes + i) = j;

    for (i = 0, j = 2; i < MAX; i++, j++)
        isprime(primes, i, j);

    nprimes(primes, DIV, MAX);

    return 0;
}

void isprime(unsigned int *primes, unsigned int i, unsigned int j) {
    while (i + j < MAX) {
        i += j;
        *(primes + i) &= 0x0000;
    }
}

void nprimes(unsigned int *primes, unsigned int div, unsigned int max) {
    unsigned int i;
    unsigned int j;
    unsigned int primenums = 0;

    printf("PER %d NUMBERS:\n");
    printf("RANGE:\t\t\t\t\t# OF PRIMES:\n");
    for (i = 0, j = i; i < max + 1; i++) {
        if (*(primes + i))
            primenums++;
        if (i % div == 0 && i != 0) {
            printf("%lu to %lu\t\t\t\t%lu\n", j, i, primenums);
            j = i;
            primenums = 0;
        }
    }
}
