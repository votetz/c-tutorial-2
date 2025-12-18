#include "divisors.h" 

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int sum_of_divisors(int num) {
    int sum = 0;
    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return sum;
}

void process_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = sum_of_divisors(arr[i]);
    }
}