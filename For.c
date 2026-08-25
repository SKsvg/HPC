    
    #include <stdio.h>
    #include <omp.h>  

    int main() {
        int i;
        #pragma omp parallel for //once implement for here here after need to implement for loop , if we remove for there's no work distribution,allow all thread will execute all
        for (i = 0; i < 20; i++) {
            printf("Thread %d working on iteration %d\n", omp_get_thread_num(), i);
        }

        return 0;
    }
