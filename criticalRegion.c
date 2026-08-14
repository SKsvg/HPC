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
          final_sum = final_sum + psum; //(Runtime: 0.007836 seconds)
    }

     /*{
        int myid = omp_get_thread_num();
         
        for (int i = 0; i < 1000000; i++) {
             #pragma omp critical  
              final_sum++;        //work just like sequential program- do not implement like this ( 0.601051 seconds)
        }
    }*/
    
    double end_time = omp_get_wtime(); 

    printf("Final value of shared_variable is %ld.\n", final_sum);
    printf("Runtime: %f seconds\n", end_time - start_time);

    return 0;
}
