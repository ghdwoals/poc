/*
** Write a function that will search a string for any one of a given set of
**  characters. Your function should match this prototype:
*/
char *find_char(char const *source, char const *chars);

/*
** The basic idea is to locate the first character in the source string that
**  matches any characters in the chars string. The function returns a pointer
**  to the place in the source where the match is first found. If none of the
**  characters in source match any of the chars, then a NULL pointer is
**  returned. If either argument is NULL, or either string is empty, a NULL
**  pointer is returned.
**
** Example: suppose source points to ABCDEFG. If chars points to XYZ, JURY, or
**  QQQQ, the function should return NULL. If chars points to XRCQEF, the
**  function should return a pointer to the c character in the source string.
**  The strings that the arguments point to are never modified.
**
** Do not use any library string routines.
** Do not use any subscripts in the function.
*/

char *find_char(char const *source, char const *chars) {
    char *pointer;

    if (source == 0 || chars == 0)
        return 0;
    else if (*source == '\0' || *chars == '\0')
        return 0;
    else {
        for ( ; *source != '\0'; source++)
            for (pointer = chars; *pointer != '\0'; pointer++)
                if (*source == *pointer)
                    return source;
    }

    return 0;
}
