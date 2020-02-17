#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N 100000000

int main(void)
{
    int i;
    long long a, b;
    double x, y;
    a = b = 0;

    srand((unsigned)time(NULL));

    for (i = 0; i < N; i++)
    {
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;
        a++;
        if (sqrt(x * x + y * y) < 1)
            b++;
    }
    printf("%f\n", 4 * (double)b / a);

    return 0;
}