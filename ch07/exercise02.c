/* 
** The greatest common divisor of two integers M and N (where M, N > 0) can
**  be computer as follows:
**
**      gcd(M, N) = { M % N = 0:                N
**                  { M % N = R, R > 0:         gcd(N, R)
**
** Write a function called gcd that takes two integer arguments and returns the
**  greatest common divisor of those numbers. If either of the arguments is not
**  greater than zero, function returns zero.
*/

int gcd(int m, int n) {
    if (m <= 0 || n <= 0)
        return 0;
    if (m % n = 0)
        return n;
    if (m % n > 0)
        return gcd(n, m % n);
}

/*
** Reek's solution is as follows:
*/

int gcd_reek(int m, int n) {
    int r;

    if (m <= 0 || n <= 0)
        return 0;

    r = m % n;
    return r > 0 ? gcd_reek(n, r) : n;
}
