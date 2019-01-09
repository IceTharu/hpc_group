#ifndef __LIBMATMULT_H
#define __LIBMATMULT_H


void matmult_nat(int rows1,int cols2,int cols1,double** matrix1,double** matrix2,double** matrix_out);

void matmult_lib(int rows1,int cols2,int cols1,double** matrix1,double** matrix2,double** matrix_out);

#endif
