/* 
 * Rishi Dutta 912790628
 * binary_matrix.c
 * Functions that involve BinaryMatrix structure functions
 */
#include "binary_matrix.h"

#include <stdio.h>
#include <stdlib.h>
/*
 * Input: 
 * 	int num_rows: number of rows
 * 	int num_cols: number of cols
 * Output:
 * 	BinaryMatrix* a newly allocated BinaryMatrix pointer
 * Summary:
 * 	Creates a new BinaryMatrix* allocates Coordinate data also
 */
BinaryMatrix* ConstructBinaryMatrix(int num_rows, int num_cols) {
    BinaryMatrix* result = (BinaryMatrix*) malloc(sizeof(BinaryMatrix));
    if (num_rows < 1 || num_cols < 1){
        printf("Error in CreateMatrix: number of rows and columns must be positive\n");
        return EXIT_FAILURE;
    }
    result->num_rows = num_rows;
    result->num_cols = num_cols;
    result->data = (int**) malloc(num_rows * sizeof(int*));
    for (int i = 0; i < num_rows; i++){ 
        result->data[i] = (int*) malloc(num_cols * sizeof(int));
        for (int j = 0; j < num_cols; j++){
            result->data[i][j] = 0;
        }
    }
    return result;
}
/* Input:
 * 	BinaryMatrix* M: A BinaryMatrix to be deleted
 * Summary:
 * 	frees the memory of a BinaryMatrix
 */
void DeleteBinaryMatrix(BinaryMatrix* M) {
    for(int i = 1; i < M->num_rows; i++){
        free(M->data[i]);
    }
    free(M);
}

/* Input:
 * 	BinaryMatrix* M: the binary matrix being updated
 * Output:
 * 	int row: x-coordinate
 * 	int col: y-coordinate
 * 	int content: 0 or 1 if cell is alive or not
 * Summary:
 * 	Updates one coordinate on the 2D Matrix to alive or dead
 */
void UpdateEntry(BinaryMatrix* M, int row, int col, int content) {
    if ((row > (M->num_rows)) || (col > (M->num_cols))){
        printf("Error in UpdateEntry: index out of bounds\n");
        return EXIT_FAILURE;
    }
    if((content != 0) && (content != 1)){
        printf("Error in UpdateEntry: content must be 0 or 1\n");
        return EXIT_FAILURE;
    }
    M->data[row][col] = content;
    return;
}

/*
 * Input:
 * 	BinaryMatrix* M: BinaryMatrix looked at
 * 	int row: x coordinate
 * 	int col: y coordinate
 * Output:
 * 	true or false
 * Summary:
 * 	Checks a coordinate on a BinaryMatrix to see if it exists,
 * 	pointer
 */
int IsMatrixIndex(BinaryMatrix* M, int row, int col) {
    if (M == NULL){
        printf("IsMatrixIndex Error: NULL parameter passed\n");
        return EXIT_FAILURE;
    }
    if ((row >= (M->num_rows)) || (col >= (M->num_cols))){
        return 0;
    }
    if (row < 0 || col < 0){
        return 0;
    }
    else {
        return 1;
    }
}

/*
 * Input:
 * 	BinaryMatrix* M: A Binary Matrix
 * Summary:
 * 	Prints 0s and 1s to stdout to represent the matrix
 */
void PrintMatrix(BinaryMatrix* M) {
    for(int i = 0; i < (M->num_rows); i++){
        for(int j = 0; j < (M->num_cols); j++){
            int a = M->data[i][j];
            printf("%d", a);
        }
        printf("\n");
    }
    return;
}
