    
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
/*
distribute workload using parallel for
array of sum is useful
there is no race condition for local variables

for and omp parallel has barriers
#pragma omp parallel for schedule(satatic,1) - work round robin way
(the number we use here can be any thing 1,2,3,....)

#pragma omp parallel for schedule(dynamic,1) - just available task taken 
it is expensive bcz of inter thread communication

*/
