/*
** Chapter 2, Exercise 1
**
** Write a program with three functions in three separate source files. The
**  function increment should take a single integer argument and return the
**  value of that argument plus one. This function should be in the file
**  increment.c. The second function is called negate. It also takes a single
**  integer argument and return the negated value of that argument (for example,
**  if the argument is 25, the function should return ‐25; if the argument is ‐6
**  12, the function should return 612). The final function is main, in the file
**  main.c, and it should call each of the other functions with the values 10,
**  0, and ‐10 and print the results.
*/

#include <stdio.h>

int main(void) {
    printf("10:\n");
    printf("Incremented:\t%d\n", increment(10));
    printf("Negated:\t%d\n", negate(10));
    printf("\n");
    printf("0:\n");
    printf("Incremented:\t%d\n", increment(0));
    printf("Negated:\t%d\n", negate(0));
    printf("\n");
    printf("-10:\n");
    printf("Incremented:\t%d\n", increment(-10));
    printf("Negated:\t%d\n", negate(-10));
    return 0;
}
