#include <stdio.h>
#include <omp.h>

#define NT 8

int main() {
    long final_sum = 0; 

    double start_time = omp_get_wtime(); 

    #pragma omp parallel num_threads(8)
    {
        int myid = omp_get_thread_num();
        long psum = 0;
        for (int i = 0; i < 1000000; i++) {
            psum++; 
        }
        #pragma omp critical  //not allow access unsafe regions: no 2 process can access this region
          final_sum = final_sum + psum;
    }

    double end_time = omp_get_wtime(); 

    printf("Final value of shared_variable is %ld.\n", final_sum);
    printf("Runtime: %f seconds\n", end_time - start_time);

    return 0;
}
