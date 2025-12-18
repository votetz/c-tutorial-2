#include "probability.h"
#include <math.h>
#include <stdio.h>

double f(double x) {
    return exp(-x) + pow(x, 2) - 2;\

}
double df(double x) {
    return -exp(-x) + 2 * x;
}

double ddf(double x) {
    return exp(-x) + 2;
}

double phi(double x, int mode) {
    if (mode == 1) {

        double val = 2 - exp(-x);
        return (val >= 0) ? sqrt(val) : x;
    }
    else {
 
        double val = 2 - x * x;
        return (val > 0) ? -log(val) : x;
    }
}

double method_bisection(double a, double b, double eps) {
    double x;
    while (fabs(b - a) > eps) {
        x = (a + b) / 2.0;
        if (f(x) == 0.0) return x;
        if (f(a) * f(x) < 0) b = x;
        else a = x;
    }
    return (a + b) / 2.0;
}

double method_chord(double a, double b, double eps) {
    double x_curr = a, x_next = b;

    if (f(a) * ddf(a) > 0) x_curr = a; 
    else x_curr = b;                  

    do {
        double fx = f(x_next);
        double f_stat = f(x_curr); 

        double temp = x_next;
        x_next = x_next - fx * (x_curr - x_next) / (f_stat - fx);

        if (fabs(x_next - temp) < eps) break;
    } while (1);

    return x_next;
}

double method_newton(double x0, double eps) {
    double x = x0;
    double h;
    int iter = 0;
    do {
        h = f(x) / df(x);
        x = x - h;
        iter++;
        if (iter > 1000) break;
    } while (fabs(h) > eps);
    return x;
}

double method_secant(double x0, double x1, double eps) {
    double x_prev = x0;
    double x_curr = x1;
    double x_next;

    do {
        double f_curr = f(x_curr);
        double f_prev = f(x_prev);

        if (fabs(f_curr - f_prev) < 1e-15) break;

        x_next = x_curr - f_curr * (x_curr - x_prev) / (f_curr - f_prev);

        if (fabs(x_next - x_curr) < eps) break;

        x_prev = x_curr;
        x_curr = x_next;
    } while (1);

    return x_curr;
}

double method_iteration(double x0, double eps, int mode) {
    double x_curr = x0;
    double x_next;
    int iter = 0;

    do {
        x_next = phi(x_curr, mode);
        if (fabs(x_next - x_curr) < eps) break;
        x_curr = x_next;
        iter++;
        if (iter > 1000) break;
    } while (1);

    return x_next;
}