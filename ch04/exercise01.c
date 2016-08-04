/*
** Computing square roots.
*/

#include <stdio.h>

int main(void) {
    float n;
    int a;
    float b;
    float i = 1.0;

    printf("Enter a number:\t");
    while ((scanf("%f", &n)) == 1) {
        if (n < 0) {
            printf("Cannot accept negative numbers.\n");
            printf("Enter another number:\t");
            continue;
        }
        i = 1;
        for (a = 1; ; a++) {
            b = (i + (n / i)) / 2;
            printf("%d:\t%.10f\n", a, b); 
            if (b == i)
                break;
            else
                i = b;
        }
        printf("The square root of %g is %g.\n", n, b);
        printf("Enter another number:\t");
    }

    return 0;
}
