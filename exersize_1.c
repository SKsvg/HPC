#include <stdio.h>
#include <omp.h>

int main() {
    int N = 20;
    int A[20];

    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        A[i] = i;
    }

    #pragma omp parallel
    {
        #pragma omp master
        {
            printf("Array elements:\n");
            for (int i = 0; i < N; i++) {
                printf("%d ", A[i]);
            }
            printf("\n");
        }
    }

    return 0;
}
