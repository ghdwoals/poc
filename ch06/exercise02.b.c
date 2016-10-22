#include <stdio.h>

/*
** Write a function that deletes a portion of a string. Here is its prototype:
*/

int del_substr(char *str, char const *substr);

/*
** The function should first determine whether the string substr occurs in str.
**      If not, a value of 0 should be returned. If the substring does appear,
**      the function should remove it by copying the characters in str that
**      follow the substring over the substring itself. The value 1 should then
**      be returned. If the substring appears several times in the first
**      argument, only the first occurrence should be delted.
**
** To illustrate, str points to ABCDEFG. If substr points to FGH, CDF, XABC,
**      the function returns 0, and str is unchanged. If substr points to CDE,
**      the function should change str to ABFG and return 1.
**
** Do not use any of the library string routines.
** Do not use any subscripts in your function.
*/

/*
** This problem really gave me some trouble initially. After five hours (and a
**      very liberal sprinkling of "diagnostic" printf statements), I finally
**      remembered that newlines are characters, too. Thus, I had to modify the
**      initial for loop to keep them in mind.
**
** Compiled and tested this on a CentOS 7 box, along with a simple test.c file.
**      The test file used in conjunction with this source file uses scanf() to
**      obtain relevant strings.
*/

int del_substr(char *str, char const *substr) {
    int startaddr = 0;
    int endaddr = 0;
    int flag = 0;
    int i;
    int j;
    int strlen_ = 0;
    int substrlen = 0;

    while (*(str + strlen_) != '\0') strlen_++;

    while (*(substr + substrlen) != '\0') substrlen++;

    if (strlen_ < substrlen) {
        printf("Substring cannot be longer than the original string!\n");
        return flag;
    }

    for (i = 0; i < strlen_; i++) {
        if (*(str + i) == *substr) {
            startaddr = endaddr = i;
            flag = 1;
            j = 0;
            while (j < substrlen) {
                endaddr++;
                j++;
                if (*(str + endaddr) != *(substr + j)) {
                    if (*(substr + j) != '\n' && *(substr + j) != '\0') {
                        flag = 0;
                        break;
                    }
                }
            }
        }
        if (flag)       break;
    }

    if (flag) {
        for (i = 0, j = endaddr; i < strlen_ || *(str + j) != '\0'; i++) {
            if (i < startaddr)  continue;
            else if (i >= startaddr) {
                *(str + i) = *(str + j);
                j++;
            }
        }
        *(str + i) = '\0';
    }

    return flag;
}
