/*
** Printing prime numbers from 1 to 100.
*/

/*
** Note that in his own solution, Reek gives a solution that exploits the fact
**  that every even number after 2 is not a prime number.
** The solution here is far more "brute-force" in that it tests every number.
*/

#include <stdio.h>
#define MAX 100

int is_prime(int x);

int main(void) {
    int a;

    for (a = 1; a <= MAX; a++) {
        if (a == 1) {
            printf("%d is special.\n", a);
            continue;
        } else if (a == 2) {
            printf("%d is a prime number.\n", a);
            continue;
        }
        if (is_prime(a) == 1)
            printf("%d is a prime number.\n", a);
        else
            printf("%d is not a prime number.\n", a);
    }

    return 0;
}

int is_prime(int x) {
    int i;
    int is_prime;
    
    for (i = 2; i < x; i++) {
        if (x % i == 0) {
            is_prime = 0;
            return is_prime;
        } else if (x % i == 1) {
            is_prime = 1;
        }
    }

    return is_prime;
}
