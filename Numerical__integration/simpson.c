// 数値積分
#include <stdio.h>
#include <math.h>
const double h = 0.000001;
int main(void)
{
    double a, b, result;
    double x_n0, x_n1, x_n2;
    double y_n0, y_n1, y_n2;
    long n, i;
    a = -1;
    b = 4;
    n = (b - a) / h;
    result = 0;
    for (i = 0; i < n; i += 2)
    {
        x_n0 = a + h * (i);
        x_n1 = a + h * (i + 1);
        x_n2 = a + h * (i + 2);
        y_n0 = pow(x_n0, 4) - 8 * pow(x_n0, 3) + 18 * pow(x_n0, 2) - 11;
        y_n1 = pow(x_n1, 4) - 8 * pow(x_n1, 3) + 18 * pow(x_n1, 2) - 11;
        y_n2 = pow(x_n2, 4) - 8 * pow(x_n2, 3) + 18 * pow(x_n2, 2) - 11;
        result += h / 3 * (y_n0 + 4 * y_n1 + y_n2);
    }
    printf("%f\n", result);
    return 0;
}