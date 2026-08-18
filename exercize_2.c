#include <stdio.h>
#include <omp.h>

int main() {
    int A[5][5];

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            A[i][j] = i + j;
            printf("Thread %d: A[%d][%d] = %d\n",
                   omp_get_thread_num(), i, j, A[i][j]);
        }
    }

    return 0;
}
