#include <stdio.h>
#include <omp.h>
#define NT 8

long N = 100000000;
double dx;

int main()
{
	double pi = 0.0;
	
	double start_time, run_time;

	dx = 1.0 / (double)N;

	start_time = omp_get_wtime();

        #pragma omp parallel num_threads(NT)
        {
          int myid = omp_get_num_threads();
          double x,sum = 0.0;
          for (int i = myid; i < N; i+=NT) {
		x = (i + 0.5) * dx;
		sum += 4.0 / (1.0 + x * x);
	  }
	  #pragma omp critical
	        pi = sum*dx;
        }

	/*sum=sum*dx;
	  
	  #pragma omp atomic           //completed in a serial way
	        pi += sum;
	*/
	
        
	run_time = omp_get_wtime() - start_time;
	printf("\n pi with %ld steps is %lf in %lf seconds\n ", N, pi, run_time);
}
