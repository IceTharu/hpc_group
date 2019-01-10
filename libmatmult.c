#include <stdio.h>
#include <cblas.h>
#define min(x,y) ((x<y)?x:y)

/* Natural method */
void matmult_nat(int rows1,int cols2,int cols1,double** matrix1,double** matrix2,double** matrix_out){

  for(int i = 0; i < rows1; i++){
    for(int j = 0; j < cols2; j++){
      matrix_out[i][j] = 0;
    }
  }
  for(int i = 0; i < rows1; i++){
    for(int j = 0; j < cols2; j++){
      for(int k = 0; k < cols1; k++){
	matrix_out[i][j] += matrix1[i][k]*matrix2[k][j];
      }
    }
  }
}

void matmult_lib(int rows1,int cols2,int cols1,double** matrix1,double** matrix2,double** matrix_out){

	cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, rows1, cols2, cols1, 1, *matrix1, cols1, *matrix2, cols2, 0, *matrix_out, cols2);
}


void matmult_mnk(int m,int n,int k,double** matrix1,double** matrix2,double** matrix_out){

  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      matrix_out[i][j] = 0;
    }
  }	

  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      for(int z = 0; z < k; z++){
	matrix_out[i][j] += matrix1[i][z] * matrix2[z][j];
      }
    }
  }
}


void matmult_nmk(int m,int n,int k,double** matrix1,double** matrix2,double** matrix_out){

  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      matrix_out[i][j] = 0;
    }
  }	
  for(int j = 0; j < n; j++){
    for(int i = 0; i < m; i++){
      for(int z = 0; z < k; z++){
	matrix_out[i][j] += matrix1[i][z]*matrix2[z][j];
      }
    }
  }
}


void matmult_kmn(int m,int n,int k,double** matrix1,double** matrix2,double** matrix_out){

  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      matrix_out[i][j] = 0;
    }
  }
	
  for(int z = 0; z < k; z++){
    for(int i = 0; i < m; i++){
      for(int j = 0; j < n; j++){	
	matrix_out[i][j] += matrix1[i][z] * matrix2[z][j];
      }
    }
  }
}


void matmult_knm(int m,int n,int k,double** matrix1,double** matrix2,double** matrix_out){

  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      matrix_out[i][j] = 0;
    }
  }
  for(int z = 0; z < k; z++){
    for(int j = 0; j < n; j++){
      for(int i = 0; i < m; i++){
	matrix_out[i][j] += matrix1[i][z] * matrix2[z][j];
      }
    }
  }
}


void matmult_mkn(int m,int n,int k,double** matrix1,double** matrix2,double** matrix_out){

  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      matrix_out[i][j] = 0;
    }
  }	
  for(int i = 0; i < m; i++){
    for(int z = 0; z < k; z++){
      for(int j = 0; j < n; j++){
	matrix_out[i][j] +=  matrix1[i][z] * matrix2[z][j];
      }
    }
  }
}


void matmult_nkm(int m,int n,int k,double** matrix1,double** matrix2,double** matrix_out){

  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      matrix_out[i][j] = 0;
    }
  }	
	
  for(int j = 0; j < n; j++){
    for(int z = 0; z < k; z++){
      for(int i = 0; i < m; i++){	
	matrix_out[i][j] = matrix_out[i][j] + matrix1[i][z] * matrix2[z][j];
      }
    }
  }
}

void matmult_blk(int m, int n, int k, double** matrix1, double** matrix2, double** matrix_out, int step){

  int i_start;
  int j_start;
  int z_start;
	
  i_start = step * (m / step);
  j_start = step * (n / step);
  z_start = step * (k / step);


  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      matrix_out[i][j] = 0;
    }
  }
  for(int i_step = 0; i_step < m; i_step += step){
    
    for(int j_step = 0; j_step < n; j_step += step){
			
      for(int z_step = 0; z_step < k; z_step += step){
	
	for(int i = i_step; i < min(i_step + step, m); i++){
	  
	  for(int j = j_step; j < min(j_step + step, n); j++){
						
	    for(int z = z_step; z < min(z_step + step, k); z++){

	      printf("%d %d %d\n",i,j,z);
	      matrix_out[i][j] = matrix_out[i][j] + matrix1[i][z] * matrix2[z][j];
	      
	      
	      
	    }
	  }
	}
      }
    }
  }
}
