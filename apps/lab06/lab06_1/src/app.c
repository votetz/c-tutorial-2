#include <stdio.h>
#include <probability.h>

void print_result(int white, int red, double probability) {
    printf("Condition:\n");
    printf("- White balls: %d\n", white);
    printf("- Red balls:   %d\n", red);
    printf("- Total balls: %d\n\n", white + red);
    printf("Result: %.4f (approx. %.2f%%)\n", probability, probability * 100);
}

int main() {
    int white_balls = 7;
    int red_balls = 5;

    double prob = calculate_probability(white_balls, red_balls);

    print_result(white_balls, red_balls, prob);

    return 0;
}