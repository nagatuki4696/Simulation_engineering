#include <stdio.h>
#include <stdlib.h>

#define N 3

int main(void)
{
    int i, j, k;
    double *A;
    A = (double *)malloc(sizeof(double) * N * (N + 1));

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N + 1; j++)
        {
            scanf("%lf", &A[(N + 1) * i + j]);
        }
    }

    for (i = 0; i < N; i++)
    {
        for (j = i + 1; j < N + 1; j++)
        {
            A[(N + 1) * i + j] /= A[(N + 1) * i + i];
        }
        for (j = i + 1; j < N; j++)
        {
            for (k = i + 1; k < N + 1; k++)
            {
                A[(N + 1) * j + k] -= A[(N + 1) * i + k] * A[(N + 1) * j + i];
            }
        }
    }
    for (i = N - 2; i >= 0; i--)
    {
        for (j = i + 1; j < N; j++)
        {
            A[(N + 1) * i + N] -= A[(N + 1) * i + j] * A[(N + 1) * j + N];
        }
    }

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N + 1; j++)
        {
            printf("%lf ", A[(N + 1) * i + j]);
        }
        printf("\n");
    }

    free(A);

    return 0;
}