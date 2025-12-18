#include <stdio.h>

void print_line() {
    printf("------------------------------------------------------------------------\n");
}

int main() {

    double eps_values[] = { 0.01, 1e-4, 1e-6 }; 
    int eps_count = 3;

    double a1 = -1.0, b1 = 0.0;

    double a2 = 1.0, b2 = 2.0;

    printf("\nTask: Find roots of e^(-x) + x^2 - 2 = 0\n");

    for (int i = 0; i < eps_count; i++) {
        double eps = eps_values[i];
        printf("\n=== Precision EPS = %g ===\n", eps);
        print_line();
        printf("| %-15s | %-12s | %-12s |\n", "Method", "Root 1 (-)", "Root 2 (+)");
        print_line();

        double r1 = method_bisection(a1, b1, eps);
        double r2 = method_bisection(a2, b2, eps);
        printf("| %-15s | %-12.8f | %-12.8f |\n", "Bisection", r1, r2);

        r1 = method_chord(a1, b1, eps);
        r2 = method_chord(a2, b2, eps);
        printf("| %-15s | %-12.8f | %-12.8f |\n", "Chord", r1, r2);

        r1 = method_newton((a1 + b1) / 2, eps);
        r2 = method_newton((a2 + b2) / 2, eps);
        printf("| %-15s | %-12.8f | %-12.8f |\n", "Newton", r1, r2);

        r1 = method_secant(a1, b1, eps);
        r2 = method_secant(a2, b2, eps);
        printf("| %-15s | %-12.8f | %-12.8f |\n", "Secant", r1, r2);

        r1 = method_iteration(-0.5, eps, 2);
        r2 = method_iteration(1.5, eps, 1);
        printf("| %-15s | %-12.8f | %-12.8f |\n", "Iteration", r1, r2);

        print_line();
    }

    return 0;
}