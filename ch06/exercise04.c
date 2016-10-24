/*
** Using the Sieve of Eratosthenes, write a program and algorithm for the
**  computation of prime numbers. The first step of the algorithm is to write
**  down all the numbers from two to some upper limit. In the rest of the
**  algorithm, you go through the list and cross out numbers that are not prime.*/

#include <stdio.h>
#include <stdbool.h>

#define MAX 1000

void array(int *isprime, int i, int j);

int main(void) {
    int isprime[MAX];
    int numbers[MAX];
    int i;
    int j;
    int primes = 0;

    for (i = 0; i < MAX; i++)
        *(isprime + i) = true;

    // We start with the number 2.
    // This array only exists to show corresponding numbers.
    for (i = 0, j = 2; i < MAX; i++, j++)
        *(numbers + i) = j;

    for (i = 0, j = 2; i < MAX; i++, j++)
        array(isprime, i, j);

    for (i = 0; i < MAX; i++)
        printf("isprime[%d]\t\t\tprime:\t%d;\tnumber:\t%d\n", i, *(isprime + i),
            *(numbers + i));

    for (i = 0; i < MAX; i++)
        if (*(isprime + i) == true)
            primes++;

    printf("\n");
    printf("Total # of primes:\t%d\n", primes);

    return 0;
}

void array(int *isprime, int i, int j) {
    while (i + j < MAX) {
        i += j;
        *(isprime + i) = false;
    }
}
