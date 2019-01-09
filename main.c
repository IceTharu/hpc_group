#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <cblas.h>
#include <unistd.h>

#include "datatools.h"		/* helper functions	        */
#include "mmmult.h"		/* my matrix add fucntion	*/
#include "matmult_nat.h"

#define NREPEAT 100		/* repeat count for the experiment loop */

#define mytimer clock
#define delta_t(a,b) (1e3 * (b - a) / CLOCKS_PER_SEC)

int main(){


	int rows1;
	int cols1;
	int rows2;
	int cols2;
	
	int count = 0;

	float myTimes[100];
	float blasTimes[100];
	
	for(rows1 = 1; rows1 < 1000; rows1 = rows1 + 50){
		
		cols1 = rows1 + 15;
		rows2 = cols1;
		cols2 = cols1 + 25;

		double** matrix1;
		double** matrix2;
		double** matrix_out;
		
		matrix1 = malloc_2d(rows1, cols1);
		matrix2 = malloc_2d(rows2, cols2);
		matrix_out = malloc_2d(rows1,cols2);
		
		if (matrix1 == NULL || matrix2 == NULL) {
		    fprintf(stderr, "Memory allocation error...\n");
		    exit(EXIT_FAILURE);
		}

		init_data(rows1, cols1, matrix1, matrix1);
		init_data(rows2,cols2,matrix2,matrix2);




		clock_t t1, t2;
		
		t1 = mytimer();
		/*mmmult(rows1,rows2,cols1,cols2,matrix1,matrix2,matrix_out);*/
		matmult_nat(rows1,cols2,cols1,matrix1,matrix2,matrix_out);
		t2 = mytimer();
		

		
		clock_t t1_blas, t2_blas;
		t1_blas = mytimer();
		cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, rows1, cols2, cols1, 1, *matrix1, cols1, *matrix2, cols2, 0, *matrix_out, cols2);
		t2_blas = mytimer();
		
		

		printf("My time and blas time: %f %f\n",delta_t(t1,t2),delta_t(t1_blas,t2_blas));


		myTimes[count] = delta_t(t1,t2);
		blasTimes[count] = delta_t(t1_blas,t2_blas);
		count++;


	}
	for(int i = 0; i < 100; i++){
		printf("%f%f\n", myTimes[i], blasTimes[i]);
	}

return 0;


}
