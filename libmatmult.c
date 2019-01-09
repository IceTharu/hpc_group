#include <stdio.h>
#include <cblas.h>

void matmult_nat(int rows1,int cols2,int cols1,double** matrix1,double** matrix2,double** matrix_out){
	
	for(int i = 0; i < rows1; i++){
		for(int j = 0; j < cols2; j++){
			for(int k = 0; k < cols1; k++){

				matrix_out[i][j] = matrix_out[i][j] + matrix1[i][k] * matrix2[k][j];

			}
		}
	}
}

void matmult_lib(int rows1,int cols2,int cols1,double** matrix1,double** matrix2,double** matrix_out){
	cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, rows1, cols2, cols1, 1, *matrix1, cols1, *matrix2, cols2, 0, *matrix_out, cols2);
}


