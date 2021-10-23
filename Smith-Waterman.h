#ifndef SMITH_WATERMAN_H
#define SMITH_WATERMAN_H

// Prints the local sequence alignment of the two strings `a' and `b'
// as computed by the Smith-Waterman algorithm.
// The Smith-Waterman algorithm is described in detail on Wikipedia:
// https://en.wikipedia.org/wiki/Smith-Waterman_algorithm#Algorithm
//
// For the inputs:
//   a = GGTTGACTA
// and
//   b = TGTTACGG
// this function should print:
// A: GTTGAC
// B: GTT-AC
//
// The implementation should contain of two major steps:
//  1. create the scoring matrix by implementing `create_matrix` in
//     scoring_matrix.c
//  2. compute the traceback result by implementing the `traceback` function
//     in traceback.c
//
// A (incomplete!) pseudo code of the implementation should look like:
// void print_smith_waterman(const char *a, const char *b) {
//   int match_score = 3;
//   int gap_cost = 2;
//   scoring_matrix matrix = create_matrix(a, b, match_score, gap_cost);
//   traceback_result result = traceback(matrix_as_view(matrix), a, b, ?, 0);
//
//   printf("A: %s\n", result->a_);
//   printf("B: %s\n", result->b_);
//
// }
//
void print_smith_waterman(const char *a, const char *b);

#endif // SMITH_WATERMAN_H