#include "app.h"

/*
 Variant 7
 f(x) = cos(x)
 0 <= x <= 1
 N = 7
 S = sum (-1)^n * x^(2n) / (2n)!

 Recurrence:
 a_0 = 1
 q_n = a_(n+1) / a_n = -x^2 / ((2n+1)*(2n+2))
*/

#define LAB02_1_VAR_7

#ifdef LAB02_1_VAR_7

#define N_COUNT 7            
#define EPS 0.0001         
#define START_FROM 0        
#define INIT_VALUE(x) (1.0)  
#define FUNC(x) (cos(x))

#define Q(x, n) ( (-1.0 * (x) * (x)) / ( (2.0 * (n) + 1.0) * (2.0 * (n) + 2.0) ) )

#define RESULT(x, S) (S)

#endif

int main() {
   
    double a_start = 0.0;
    double b_end = 1.0;
    int k = 11; 
    double h = (b_end - a_start) / (k - 1);

    double x;

    printf("   x   |  Etalon  |  S(N=%d)  |  S(eps) \n", N_COUNT);
    printf("-------|----------|----------|----------\n");

    for (int i = 0; i < k; i++)
    {
        x = a_start + i * h;

        double etalon = FUNC(x);

        double S_N;
        {
            double a = INIT_VALUE(x);
            double S = a;
            int n;

            for (n = START_FROM; n < START_FROM + N_COUNT; n++)
            {
                a *= Q(x, n);
                S += a;
            }
            S_N = RESULT(x, S);
        }

        double S_eps;
        {
            double a = INIT_VALUE(x);
            double S = a;
            int n = START_FROM;

            while (fabs(a) > EPS)
            {
                a *= Q(x, n);
                S += a;
                n++;
            }
            S_eps = RESULT(x, S);
        }

        printf(" %.2f  | %.6f | %.6f | %.6f \n", x, etalon, S_N, S_eps);
    }

    return 0;
}