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
