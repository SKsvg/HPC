#include <stdio.h>
#include <omp.h>

#define N 8

int main()
{
    int P[N][N] = {0};

    // First element
    P[0][0] = 1;

    // Generate rows 0 to N-1
    for (int i = 1; i < N; i++)
    {
        // First and last elements
        P[i][0] = 1;
        P[i][i] = 1;

        // Calculate middle elements in parallel
        #pragma omp parallel for
        for (int j = 1; j < i; j++)
        {
            P[i][j] = P[i - 1][j - 1] + P[i - 1][j];

            printf("Thread %d -> P[%d][%d] = %d\n",
                   omp_get_thread_num(), i, j, P[i][j]);
        }
    }

    // Print Pascal's Triangle
    printf("\nPascal's Triangle:\n\n");

    for (int i = 0; i < N; i++)
    {
        // Spaces for triangle shape
        for (int space = 0; space < (N - i - 1) * 2; space++)
        {
            printf(" ");
        }

        // Print row
        for (int j = 0; j <= i; j++)
        {
            printf("%4d", P[i][j]);
        }

        printf("\n");
    }

    return 0;
}
