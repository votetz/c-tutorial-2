#include <stdio.h>
#define N 10

int main()
{
    srand(time(NULL));

    int a[N];
    int i, d;

    for (i = 0; i < N; ++i) {
        a[i] = (rand() % 20) + 1;
    }

    printf("Original array:\n");
    for (i = 0; i < N; ++i) {
        printf("%d\t", a[i]);
    }
    printf("\n");

    for (i = 0; i < N; ++i) {
        int current_num = a[i];
        int sum_divisors = 0;

        for (d = 1; d <= current_num; ++d) {
            if (current_num % d == 0) {
                sum_divisors += d;
            }
        }

        a[i] = sum_divisors;
    }

    printf("Modified array (sum of divisors):\n");
    for (i = 0; i < N; ++i) {
        printf("%d\t", a[i]);
    }
    printf("\n");

    return 0;
}