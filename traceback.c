#include "traceback.h"

#include <string.h>
#include <stdio.h>

void traceback_rec(scoring_matrix_view view, const char* a, const char* b, char* a_, char* b_, int i) {
    //Find the current position value, the value above and above and to the left 
    int current = view.matrix.data[ (view.matrix.width*(view.height-1)) + view.width-1];
    int diag = view.matrix.data[ view.matrix.width*(view.height-2) + view.width-2];
    int up = view.matrix.data[ view.matrix.width*(view.height-2) + view.width];
    //If true we have reached the end
    if ( current == 0 ) {
        return;
    }
    //Set a to the current corresponding letter and perform a conditon statement to see whether b matches
    //based on the size of up and diagonal
    a_[i] = a[ (view.height-2) ];
    view.height -= 1;
    if ( diag > up || diag == 0 ) {
        b_[i] = b[ (view.width-2) ];
        view.width -= 1;
    } else {
        b_[i] = '-';
    }

    //Reduce the counter and call the function again
    i--;
    traceback_rec( view, a, b, a_, b_, i);
    return;
}

traceback_result *traceback(scoring_matrix_view view, const char* a, const char* b) {
    int max = 0;
    int new_width = 0;
    int new_height = 0;

    //Get the max value and corresponding new width and height
    int i, j;
    for (i=1; i < view.height; i++){
		for (j=1; j < view.width; j++){
            if ( view.matrix.data[((view.matrix.width)*i+j)] >= max){
                max = view.matrix.data[((view.width)*i+j)];
                //This is +1 as the data is 0 indexed
                new_width = j+1;
                new_height = i+1;
            }
        }
    }
    //Asign the new width and height to the view's width and height
    view.width = new_width;
    view.height = new_height;

    //Asign i as the view height-3 as the width and height has additonal length for the 0 row and column
    //as well as both the matrix and the word is 0 indexed 
    i = view.height-3;

    char* a_ = malloc( view.height  * sizeof(char));
    char* b_ = malloc( view.width  * sizeof(char));
    
    //Call the traceback recursively until we reach 0
    traceback_rec(view, a, b, a_, b_, i);

    //Assign the resulting a_ and b_ to a struct result
    traceback_result* result = malloc(sizeof(traceback_result));
    result->a_ = a_;
    result->b_ = b_;

    return result;
}

void freeResult(traceback_result *result)
{
    free(result->a_);
    free(result->b_);
    free(result);
}