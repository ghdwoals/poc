#include <stdio.h>

/*
** Write a function that will search a string for any one of a given set of
**  characters. Your function should match this prototype:
*/

char *find_char(char const *source, char const *chars);

/*
** The basic idea is to locate the first character in the source string that
**  matches any of the characters in the chars string. The function then
**  returns a pointer to the place in source where the first match was found.
**  If none of the characters in the source match any chars, a NULL pointer is
**  returned. If either argument is null, or either string is empty, a NULL
**  pointer is returned.
**
** Example: suppose source points to ABCDEFG. If chars points to XYZ, JURY,
**  or QQQQ, the function should return NULL. If chars points to XRCQEF,
**  the function should return a pointer to the C in the source. The strings
**  are never modified.
**
** There is a function in the C library called strpbrk. But the goal of this
**  program is for you to manipulate the pointers yourself, so:
**      (a) no library string routines (strncpy, etc.); and
**      (b) no subscripts anywhere in the function.
*/


