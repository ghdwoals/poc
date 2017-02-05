/* Modify the identity_matrix function from the previous problem [exercise03.c]
 * so that it can take matrices of any size by flattening the array. The first
 * argument should be a pointer to an integer, and you will need a second
 * argument that specifies the size of the matrix.
 */

#include <stdbool.h>

int identity_matrix(int *matrix, int size) {
    int row, col;

    for (row = 0; row < size; row++)
        for (col = 0; col < size; col++)
            if (*matrix++ != (row == col))
                return false;

    return true;
}
