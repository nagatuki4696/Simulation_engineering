// 数値積分
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define N 100000000
int main(void)
{
    long i, cnt;
    double x, y, f;
    srand((unsigned)time(NULL));
    cnt = 0;
    for (i = 0; i < N; i++)
    {
        x = (double)rand() / RAND_MAX * 5 - 1;
        y = (double)rand() / RAND_MAX * 32 - 11;
        f = pow(x, 4) - 8 * pow(x, 3) + 18 * pow(x, 2) - 11;
        if (f < 0)
        {
            if (y < 0 && y > f)
                cnt--;
        }
        else
        {
            if (y > 0 && y < f)
                cnt++;
        }
    }
    printf("%f\n", (double)cnt / N * 32 * 5);
    return 0;
}