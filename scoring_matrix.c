#include "scoring_matrix.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Function to find the maximum value for a given list of size n
int max(int a[], int n) 
{ 
    int max = a[0]; 
  
    int i;
    for (i = 1; i < n; i++){
		if (a[i] > max) {
			max = a[i]; 
		}
	}
    return max; 
}

scoring_matrix create_matrix(const char *a, const char *b, int match_score, int gap_cost)
{
	//Find the length of a and b
	int len_a = strlen(a);
	int len_b = strlen(b);

	//Allocate memory for the data and the struct
	//Data will be stored in a 1D array
	int* data = malloc( (len_a+1)*(len_b+1)  * sizeof(int));
	scoring_matrix *matrix = malloc(sizeof(scoring_matrix));
	//Assign the values within the struct
	matrix->width = len_b+1;
	matrix->height = len_a+1;
	matrix->data = data;

    // Fill matrix
	int i,j,upleft,up,left;
	for (i=1; i < matrix->height; i++){
		for (j=1; j < matrix->width; j++){

			upleft = matrix->data[(matrix->width)*(i-1) + (j-1)] + (a[i-1] == b[j-1] ? match_score : -match_score); 
			up = matrix->data[(matrix->width)*(i-1) +j] - gap_cost;
			left = matrix->data[(matrix->width)*i+ (j-1)] -gap_cost;

			//Find the maximum of the above 3 values and 0 and set it as the value for the current matrix postition
			int a[] = {upleft, up, left, 0};
			matrix->data[(matrix->width)*i+j] = max(a, 4);
		}
	}

	return *matrix;
}

void free_matrix(scoring_matrix matrix)
{
	free(matrix.data);
}

scoring_matrix_view matrix_as_view(scoring_matrix matrix)
{
    scoring_matrix_view view = {matrix.width, matrix.height, matrix};
    return view;
}

void print_matrix(scoring_matrix_view view)
{
	int i,j;
	printf("Current view:\n");
	for (i=0; i < view.height; i++){
		for (j=0; j < view.width; j++){
			printf("%d \t", view.matrix.data[(i*view.matrix.width)+j]);
		}
		printf("\n");
	}
}
