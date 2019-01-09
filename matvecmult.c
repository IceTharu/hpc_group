void
matvecmult(int m, int n, double **A, double **B, double **C) {
    
    int i, j;
    double temp_value;

    for(i = 0; i < m; i++)
	temp_value = 0;
	for(j = 0; j < n; j++)
	    C[i][j] = A[i][j] + B[i][j];
	    
}


//
