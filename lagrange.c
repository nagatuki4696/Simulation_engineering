#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int m, n, i, j, k;
    double *x, *y, *z, *z_denom;
    double xx, yy;
    double a, b, w;
    scanf("%d", &n);
    scanf("%lf %lf %d", &a, &b, &m);
    w = b - a;
    x = (double *)malloc(sizeof(double) * (n + 1));
    y = (double *)malloc(sizeof(double) * (n + 1));
    z = (double *)malloc(sizeof(double) * (n + 1));
    z_denom = (double *)malloc(sizeof(double) * (n + 1));
    for (i = 0; i < n + 1; i++)
    {
        scanf("%lf %lf", &x[i], &y[i]);
    }
    for (i = 0; i < n + 1; i++)
    {
        z_denom[i] = 1;
        for (j = 0; j < n + 1; j++)
        {
            if (i == j)
                continue;
            z_denom[i] *= x[i] - x[j];
        }
    }
    // ラグランジュ補間
    for (i = 0; i <= m; i++)
    {
        xx = a + w * ((double)i / m);
        for (j = 0; j < n + 1; j++)
        {
            z[j] = 1;
            for (k = 0; k < n + 1; k++)
            {
                if (j == k)
                    continue;
                z[j] *= xx - x[k];
            }
            z[j] /= z_denom[j];
        }

        yy = 0;
        for (j = 0; j < n + 1; j++)
        {
            yy += y[j] * z[j];
        }
        printf("%f %f\n", xx, yy);
    }
    return 0;
}