#include <omp.h>
#include <stdio.h>

#define N 10

int main() {
    int A[N] = {1,2,3,4,5,6,7,8,9,10};
    int s = 0; // this s is global one but it is same to the local each thread allow to keep there value of s
    
    #pragma omp parallel for reduction(+:s) // here s is the shared variable , it is a local variable 
    for (int i=0;i<N; i++){
      s+=A[i];
    }
    printf("sum = %d\n",s); // %d : double value(integer)
    return 0;
}

//inside reduction you can specify private variables(collect data from others sum up values)



/*
#include <omp.h>
#include <stdio.h>

#define N 10

int main() {
    //int j=10; // j depend on iteration count
    int s=0;
    
    #pragma omp parallel
    {   
        int j=10;
        #pragma omp for reduction(+:s)
          for (int i=0;i<N; i++){
            j+= 10 + (i+1)*5;
            s = i * j;
          }
    }      
    printf("sum = %d\n",s); 
    
    return 0;
}

*/

/*
#include <stdio.h>
#include <omp.h>

#define N 100000000L

int main()
{
    double pi = 0.0;
    double sum = 0.0;
    double start_time, run_time;

    double dx = 1.0 / (double)N;

    start_time = omp_get_wtime();

    #pragma omp parallel for reduction(+:sum) // this is parallel
    for (long i = 0; i < N; i++) { //this is serialisable
        double x = (i + 0.5) * dx;
        sum += 4.0 / (1.0 + x * x);
    }

    pi = sum * dx;

    run_time = omp_get_wtime() - start_time;

    printf("\nPi with %ld steps is %lf in %lf seconds\n",
           N, pi, run_time);

    return 0;
}
*/
