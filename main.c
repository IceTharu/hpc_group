#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <cblas.h>
#include <unistd.h>

#include "datatools.h"		/* helper functions	        */
#include "mmmult.h"		/* my matrix add fucntion	*/

#include "libmatmult.h"

#define NREPEAT 100		/* repeat count for the experiment loop */

#define mytimer clock
#define delta_t(a,b) (1e3 * (b - a) / CLOCKS_PER_SEC)

#define min(x,y) ((x<y)?x:y)

int main(){

	
	int n;
	int k;
	int m;

	n = 31;
	k = 51;
	m = 33;


	double** matrix1;
	double** matrix2;
	double** matrix_out;
	
	matrix1 = malloc_2d(n, k);
	matrix2 = malloc_2d(k, m);
	matrix_out = malloc_2d(n,m);
	
	if (matrix1 == NULL || matrix2 == NULL || matrix_out == NULL) {
	    fprintf(stderr, "Memory allocation error...\n");
	    exit(EXIT_FAILURE);
	}

	init_data(n, k, matrix1, matrix1);
	init_data(k,m,matrix2,matrix2);
	/*init_data(n,m,matrix_out,matrix_out);*/



	int step = 17;
	
	int i_reach;
	int j_reach;
	int z_reach;
	
	i_reach = step * (n / step);
	j_reach = step * (m / step);
	z_reach = step * (k / step);
	printf("%d %d %d\n",i_reach, j_reach, z_reach);
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			matrix_out[i][j] = 0;
		}
	}

	
	/*for(int i_step = 0; i_step < n; i_step += step){
		
		for(int j_step = 0; j_step < m; j_step += step){
			
			for(int z_step = 0; z_step < k; z_step += step){
			
				for(int i = i_step; i < min(i_step + step, n); i++){
					
					for(int j = j_step; j < min(j_step + step, m); j++){
						
						for(int z = z_step; z < min(z_step + step, k); z++){


							matrix_out[i][j] = matrix_out[i][j] + matrix1[i][z] * matrix2[z][j];



						}
					}
				}
			}
		}
	}



	for(int i = i_reach; i < n; i++){
		for(int j = j_reach; j < m; j++){
			for(int z = z_reach; z < k; z++){
				matrix_out[i][j] = matrix_out[i][j] + matrix1[i][z] * matrix2[z][j];
			}
		}	
	}	*/

	matmult_blk(m, n, k, matrix1, matrix2, matrix_out,2);		
	
	
	printf("Matrix1\n");
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < k; j++){
			printf("Row, col, value: %d %d %lf\n", i, j, matrix1[i][j]);
		}
	} 

	printf("Matrix2\n");
	for(int i = 0; i < k; i++){
		for(int j = 0; j < m; j++){
			printf("Row, col, value: %d %d %lf\n", i, j, matrix2[i][j]);
		}
	} 


	printf("Resulting matrix:\n");
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			printf("Row, col, value: %d %d %lf\n",i, j, matrix_out[i][j]);
		}
	} 

	free_2d(matrix1);
	free_2d(matrix2);
	free_2d(matrix_out);

return 0;
}
