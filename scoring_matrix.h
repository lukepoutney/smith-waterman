#ifndef SCORING_MATRIX_H
#define SCORING_MATRIX_H

#include <stdlib.h>

// A struct representing the scoring matrix
typedef struct
{
    size_t width;
    size_t height;
    int *data;
} scoring_matrix;

// A struct representing a "view" into a sub-part of the
// scoring matrix starting in the top left corner
typedef struct
{
    size_t width;
    size_t height;
    scoring_matrix matrix;
} scoring_matrix_view;

// Creates the scoring matrix of length of a + 1 width and
// length of b + 1 height.
// It is initialised with 0 and then filled following this formula:
//
// for all 1 < i < matrix.height and 1 < j < matrix.width:
//  matrix[i][j] = max(
//    matrix[i-1][j-1] + (a[i-1] == b[j-1] ? match_score : -match_score),
//    matrix[i-1][j] - gap_cost,
//    matrix[i][j-1] - gap_cost,
//    0
//  )
scoring_matrix create_matrix(const char *a,
                             const char *b,
                             int match_score,
                             int gap_cost);

// Frees the resources allocated in create_matrix
void free_matrix(scoring_matrix matrix);

// Makes a view that represents the entire matrix
scoring_matrix_view matrix_as_view(scoring_matrix matrix);

// Prints all values of the given view as a 2D matrix
void print_matrix(scoring_matrix_view view);

#endif // SCORING_MATRIX_H