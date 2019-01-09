#ifndef __LIBMATMULT_H
#define __LIBMATMULT_H


void matmult_nat(int rows1,int cols2,int cols1,double** matrix1,double** matrix2,double** matrix_out);

void matmult_lib(int rows1,int cols2,int cols1,double** matrix1,double** matrix2,double** matrix_out);

void matmult_mnk(int rows1,int cols2,int cols1,double** matrix1,double** matrix2,double** matrix_out);

void matmult_mkn(int rows1,int cols2,int cols1,double** matrix1,double** matrix2,double** matrix_out);

void matmult_kmn(int rows1,int cols2,int cols1,double** matrix1,double** matrix2,double** matrix_out);

void matmult_nkm(int rows1,int cols2,int cols1,double** matrix1,double** matrix2,double** matrix_out);

void matmult_nmk(int rows1,int cols2,int cols1,double** matrix1,double** matrix2,double** matrix_out);

void matmult_knm(int rows1,int cols2,int cols1,double** matrix1,double** matrix2,double** matrix_out);
#endif
