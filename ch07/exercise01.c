/*
** Write a recursive function to compute the Hermite Polynomials. The function
**  should match this prototype:
*/

int hermite(int n, int x);

int hermite(int n, int x) {
    if (n <= 0)
        return 1;
    if (n == 1)
        return 2 * x;

    return 2 * x * hermite(n - 1, x) - 2 * (n - 1) * hermite(n - 2, x);
}
