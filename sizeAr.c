#include <omp.h>
#include <stdio.h>

int main() {
	int nrows = 10;  // More rows than threads
	int ncols = 3;
	int matrix[10][3] = { {1, 0, 1}, {0, 1, 0}, {1, 1, 0}, {0, 0, 1},
						 {1, 1, 1}, {0, 1, 1}, {1, 0, 0}, {1, 1, 0},
						 {0, 0, 1}, {1, 0, 1} };
	int vector[3] = { 1, 2, 3 };
	int result[10] = { 0 };

	omp_set_num_threads(4);

        #pragma omp parallel
	{
		int myid = omp_get_thread_num();
		int nt = omp_get_num_threads();

		 for (int j = myid; j < nrows; j+=nt) {
		  for (int i = 0; i < ncols; i++) {
                      result[j] += matrix[j][i] * vector[i];
                  }
                  printf("Thread %d >>>>> result[%d] = %d\n", myid, j, result[j]);
                }

		

	}
	return 0;
}

