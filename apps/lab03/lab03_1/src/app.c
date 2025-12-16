#include "app.h"


int main()
{
    double a = -6.0, b = 6.0, h = 0.3, x;
    double min_y, max_y;
    int first = 1;

    printf("x\t\ty\n");

    for (x = a; x <= b; x += h)
    {
        double y;

        if (x <= 0)
        {
            y = log(x + sqrt(x * x + 1));
        }
        else if (x > 0 && x < 5)
        {
            y = sin(x + 2.0 / (x - 1.0));
        }
        else
        {
            y = -x + 2;
        }

        printf("%.3f\t%.3f\n", x, y);

        if (first)
        {
            min_y = y;
            max_y = y;
            first = 0;
        }
        else
        {
            if (y < min_y) min_y = y;
            if (y > max_y) max_y = y;
        }
    }

    printf("\nMin: %.3f\tMax: %.3f\n", min_y, max_y);

    return 0;
}