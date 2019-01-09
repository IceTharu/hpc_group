#include <stdio.h>

void mmmult(int rows1,int rows2,int cols1,int cols2,double** matrix1,double** matrix2,double** matrix_out){

	for(int i = 0; i < rows1; i++){
		for(int j = 0; j < cols2; j++){
			for(int k = 0; k < cols1; k++){

				matrix_out[i][j] = matrix_out[i][j] + matrix1[i][k] * matrix2[k][j];

			}
		}
	}
}
