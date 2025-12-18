#include <stdio.h>
#define N 10

int calc_divisor_sum(int num);
void process_array(int arr[], int size);
void print_array(const int arr[], int size);

int main()
{
    srand(time(NULL));

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

int calc_divisor_sum(int num) {
    int sum = 0;
    int d;
    for (d = 1; d <= num; ++d) {
        if (num % d == 0) {
            sum += d;
        }
    }
    return sum;
}

void process_array(int arr[], int size) {
    int i;
    for (i = 0; i < size; ++i) {
        arr[i] = calc_divisor_sum(arr[i]);
    }
}

void print_array(const int arr[], int size) {
    int i;
    for (i = 0; i < size; ++i) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}