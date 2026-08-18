#include <stdio.h>
#include <omp.h>

#define N 5

int main() {
    int A[N][N], B[N][N], C[N][N];

    // Initialize A and B in the master thread
    #pragma omp parallel
    {
        #pragma omp master
        {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    A[i][j] = i + j;
                    B[i][j] = i + j;
                }
            }
        }
    }

    // Matrix multiplication in parallel
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;

            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Print result
    printf("Matrix C:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
