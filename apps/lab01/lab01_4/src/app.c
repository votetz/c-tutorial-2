#include "app.h"

// Variant 19
// x * cos^2(a - x) / (bx + 1)
// a = 7.23, b = 4.18, x = 6.27

int main()
{
    double a, b, x;

    printf("Enter a, b, x:");

    int ret = scanf("%lf %lf %lf", &a, &b, &x);

    if (ret != 3)
    {
        printf("Error! Cannot read 3 arguments but only %d\n", ret);
        return -1;
    }

    printf("\n");

    double t1 = x * pow(cos(a - x), 2);

    double t2 = b * x + 1;

    double result = t1 / t2;

    printf("x * cos^2(a - x) / (bx + 1) = %.6f\n", result);

    return 0;
}