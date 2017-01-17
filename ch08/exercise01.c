/*
 * Write a declaration for an array that initializes certain locations of the
 * array to specific values. The array should be called char_values and contain
 * 3 * 6 * 4 * 5 unsigned characters. The following locations should be
 * statically initialized to these values:
 *
 * LOC          VALUE   LOC             VALUE   LOC             VALUE
 * 1,2,2,3      'A'     1,1,1,1         ' '     1,3,2,2         0xf3
 * 2,4,3,2      '3'     1,4,2,3         '\n'    2,2,3,1         '\121'
 * 2,4,3,3      3       2,5,3,4         125     1,2,3,4         'x'
 * 2,1,1,2      0320    2,2,2,2         '\''    2,2,1,1         '0'
 *
 * Note: Static initialization is to be used; there can be no executable code
 * in your solution.
 *
 * Note: Solving this problem twice, once using nested braces in the initializer
 * list and once without, will give you a greater appreciation of the usefulness
 * of nested braces.
 */
#include <stdio.h>

static char char_values[3][6][4][5] = {
    {   /* [0][][][] */
        {       /* [0][0][][] */
            { 0 }
        }
    },
    {   /* [1][][][] */
        {       /* [1][0][][] */
            { 0 }
        },
        {       /* [1][1][][] */
            { 0 },
            { 0, ' ' }
        },
        {       /* [1][2][][] */
            { 0 },
            { 0 },
            { 0, 0, 0, 'A' },
            { 0, 0, 0, 0, 'x' }
        },
        {       /* [1][3][][] */
            { 0 }
        },
        {       /* [1][4][][] */
            { 0 },
            { 0 },
            { 0, 0, 0, '\n' }
        }
    },
    {   /* [2][][][] */
        {       /* [2][0][][] */
            { 0 }
        },
        {       /* [2][1][][] */
            { 0 },
            { 0, 0, 0320 }
        },
        {       /* [2][2][][] */
            { 0 },
            { 0, '0' },
            { 0, 0, '\'' },
            { 0, '\121' }
        },
        {       /* [2][3][][] */
            { 0 }
        },
        {       /* [2][4][][] */
            { 0 },
            { 0 },
            { 0} ,
            { 0, 0, '3', 3 }
        },
        {       /* [2][5][][] */
            { 0 },
            { 0 },
            { 0 },
            { 0, 0, 0, 0, 125 }
        }
    }
};    

int main(void) {
    printf("1,2,2,3:\t'%c'\n", char_values[1][2][2][3]);
    printf("2,4,3,2:\t'%c'\n", char_values[2][4][3][2]);
    printf("2,4,3,3:\t'%c'\n", char_values[2][4][3][3]);
    printf("2,1,1,2:\t'%c'\n", char_values[2][1][1][2]);
    printf("1,1,1,1:\t'%c'\n", char_values[1][1][1][1]);
    printf("1,4,2,3:\t'%c'\n", char_values[1][4][2][3]);
    printf("2,5,3,4:\t'%c'\n", char_values[2][5][3][4]);
    printf("2,2,2,2:\t'%c'\n", char_values[2][2][2][2]);
    printf("1,3,2,2:\t'%x'\n", char_values[1][3][2][2]);
    printf("2,2,3,1:\t'%c'\n", char_values[2][2][3][1]);
    printf("1,2,3,4:\t'%c'\n", char_values[1][2][3][4]);
    printf("2,2,1,1:\t'%c'\n", char_values[2][2][1][1]);
    return 0;
}
