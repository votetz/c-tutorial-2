#include "app.h"

/*
  Variant 36

 tg(2 a − sin bx)
 -------------
 x ln|2 − x|

 a = 3.71, b = 5.22, x = -4.08

 */

int main()
{
    double a = 3.71, b = 5.22, x = -4.08;

    double t1 = tan(2 * a - sin(b * x));

    double t2 = x * log(fabs(2 - x));

    double result = t1 / t2;

    printf("tg(2*%.2f - sin(%.2f*%.2f))\n----------------------------- = %.3f", a, b, x, result);
    printf("\n%.2f * ln|2 - %.2f|", x, x);

    return 0;
}