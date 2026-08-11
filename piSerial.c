#include <stdio.h>
#include <omp.h>
#define NT 8
#define PAD 8

long N = 100000000;
double dx;

int main()
{
	double pi = 0.0;
	double sum[NT][PAD] = {{0.0}};
	double start_time, run_time;

	dx = 1.0 / (double)N;

	start_time = omp_get_wtime();
        #pragma omp parallel num_threads(NT)
        {
          int myid = omp_get_thread_num();
          double x;
	  for (int i= myid; i < N; i+=NT) {
		  x = (i + 0.5) * dx;
		  sum[myid][0] += 4.0 / (1.0 + x * x);    //we only modify first column only (0.34--->0.04) we include dummy data to avoid race condition. padding ---> remove false sharing ,even i not modify all value all value can be invalidated, 1st row in 1st cash line and others in another cash line
	  }
	}
	
	for(int j=0; j<NT; j++)
          pi += sum[j][0]* dx;
          
	run_time = omp_get_wtime() - start_time;
	printf("\n pi with %ld steps is %lf in %lf seconds\n ", N, pi, run_time);
}
