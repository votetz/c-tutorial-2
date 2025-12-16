#include "app.h"

// Variant 36
// tg(2 a - sin bx) / (x ln|2 - x|)
// a = 3.71, b = 5.22, x = -4.08

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

    double t1 = tan(2 * a - sin(b * x));

    double t2 = x * log(fabs(2 - x));

    double result = t1 / t2;

    printf("tg(2a - sin(bx)) / (x * ln|2 - x|) = %.6f\n", result);

    return 0;
}