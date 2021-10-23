#ifndef TRACEBACK_H
#define TRACEBACK_H

#include <stdlib.h>

#include "scoring_matrix.h"

typedef struct {
  char *a_; // the aligned string a
  char *b_; // the aligned stirng b
} traceback_result;

// computes the traceback throught the scoring matrix
// it returns the substring of a and the aligned and
// modified string of b
// 
// The pseudo code (in a Python-like syntax)
// for this function looks like:
// 
// def traceback(view, a, b, b_='', old_i=0):
//     i, j = find_last_index_of_max_value(view)
//
//     if (view[i][j] == 0):
//         a_ = a[j:j+len(b_)]
//         return a_, b_
//     if (old_i - i > 1):
//         b_ = b[j - 1] + b_
//     else:
//         b_ = b[j - 1] + '-' + b_ 
//     return traceback(view[0:i][0:j], a, b, b_, i)

traceback_result *traceback(scoring_matrix_view view,
                            const char *a,
                            const char *b);

// frees the resources allocated for result
void freeResult(traceback_result *result);

#endif // TRACEBACK_H