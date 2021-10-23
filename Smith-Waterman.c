#include "Smith-Waterman.h"

#include "scoring_matrix.h"
#include "traceback.h"

#include <stdio.h>
#include <string.h>

void print_smith_waterman(const char *a, const char *b)
{
    fprintf(stderr, "print_smith_waterman(\"%s\", \"%s\")\n", a, b);
    
    int match_score = 3;
    int gap_cost = 2;
 
    // create matrix
    scoring_matrix matrix = create_matrix(a, b, match_score, gap_cost);

    // create view
    scoring_matrix_view view = matrix_as_view(matrix);

    //compute traceback
    traceback_result* result = traceback(view, a, b);

    //Output Results
    printf("A: %s\n", result->a_);
    printf("B: %s\n", result->b_);

    //Free memory assigned by malloc
    free_matrix(matrix);
    freeResult(result);
}
