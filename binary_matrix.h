/*
 * binary_matrix.h
 * Rishi Dutta / 912790628
 * A header file for the BinaryMatrix program
 * Also creates the struct BinaryMatrix
 */

typedef struct{
	int num_rows;
	int num_cols;
	int** data;
}BinaryMatrix;

/*
 * Input:
 * 	int num_rows, number of rows
 * 	int num_cols, number of columns
 * Output:
 * 	BinaryMatrix*, a newly allocated BinaryMatrix pointer
 * Summary:
 * 	Creates the new BinaryMatrix* 
 */
BinaryMatrix* ConstructBinaryMatrix(int num_rows, int num_cols);

/*
 * Input:
 * 	BinaryMatrix* M, The previously allocated BinaryMatrix
 * Summary:
 * 	frees the memory of a BinaryMatrix
 */
void DeleteBinaryMatrix(BinaryMatrix* M);

/*
 * Input: 
 * 	BinaryMatrix* M, the BinaryMatrix being updated
 * 	int row, x-coordinate
 * 	int col, y-coordinate
 * 	int content, a value of 0 or 1 that will be inputed
 * Summary:
 * 	Updates a coordinate in the BinaryMatrix with a 0 or 1
 */
void UpdateEntry(BinaryMatrix* M, int row, int col, int content);

/*
 * Input:
 * 	BinaryMatrix* M, the BinaryMatrix being checked
 * 	int row, x-coordinate
 * 	int col, y-coordinate
 * Output: 
 * 	1 or 0 (true or false)
 * Summary:
 * 	Checks a coordinate of the BinaryMatrix to see if it exists
 */ 
int IsMatrixIndex(BinaryMatrix* M, int row, int col);

/*
 * Input:
 * 	BinaryMatrix* M, the updated BinaryMatrix
 * Summary:
 * 	Prints out the BinaryMatrix
 */
void PrintMatrix(BinaryMatrix* M);
#ifndef _BINARY_MATRIX_H_
#define _BINARY_MATRIX_H_

#endif /* _BINARY_MATRIX_H_ */
