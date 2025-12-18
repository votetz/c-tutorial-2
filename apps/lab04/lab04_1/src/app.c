#include "app.h"
#include "divisors.h" 

int main()
{
    srand((unsigned int)time(NULL));

    int a[N];
    int i;

    for (i = 0; i < N; ++i) {
        a[i] = (rand() % 20) + 1;
    }

    printf("Original array:\n");
    print_array(a, N);

    process_array(a, N);

    printf("Modified array (sum of divisors):\n");
    print_array(a, N);

    return 0;
}