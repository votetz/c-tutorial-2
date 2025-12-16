#include "app.h"

int main()
{
 
    double a = -4.0, b = 4.0, hx = 0.2, c = 0.0, d = 3.0, hy = 0.1;

    double x, y, z;
    double min_z, max_z;
    int first = 1;

    printf("y\\x\t");

    for (x = a; x <= b; x += hx)
    {
        printf("%.3f\t", x);
    }

    printf("\n");

    for (y = c; y <= d; y += hy)
    {
        printf("%.3f\t", y);

        for (x = a; x <= b; x += hx)
        {
      
            if ((x + y) <= 0)
            {
                printf("nan\t");
            }
            else
            {
                z = log(x + y) / exp(x - y);
                printf("%.3f\t", z);

                if (first)
                {
                    min_z = z;
                    max_z = z;
                    first = 0;
                }
                else
                {
                    if (z < min_z) min_z = z;
                    if (z > max_z) max_z = z;
                }
            }
        }

        printf("\n");
    }

    if (!first) {
        printf("\nMin: %.3f\tMax: %.3f\n", min_z, max_z);
    }

    return 0;
}