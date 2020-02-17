#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int i, j;
    double x, y, z;
    double _x, _y, _z;
    double error;
    double A[3][4];

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            scanf("%lf", &A[i][j]);
        }
    }

    x = atoi(argv[1]);
    y = atoi(argv[2]);
    z = atoi(argv[3]);
    error = 10;
    while (error > 0.001)
    {
        _x = (A[0][3] - A[0][1] * y - A[0][2] * z) / A[0][0];
        _y = (A[1][3] - A[1][0] * x - A[1][2] * z) / A[1][1];
        _z = (A[2][3] - A[2][0] * x - A[2][1] * y) / A[2][2];

        error = pow(A[0][3] - (A[0][0] * x + A[0][1] * y + A[0][2] * z), 2) + pow(A[1][3] - (A[1][0] * x + A[1][1] * y + A[1][2] * z), 2) + pow(A[2][3] - (A[2][0] * x + A[2][1] * y + A[2][2] * z), 2);

        x = _x;
        y = _y;
        z = _z;
    }

    printf("x : %lf\ny : %lf\nx : %lf\n", x, y, z);

    return 0;
}