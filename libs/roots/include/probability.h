#ifndef LAB06_H
#define LAB06_H

#include <math.h>

double f(double x);
double df(double x);
double ddf(double x);

double phi(double x, int mode);

double method_bisection(double a, double b, double eps);

double method_chord(double a, double b, double eps);

double method_newton(double x0, double eps);

double method_secant(double a, double b, double eps);

double method_iteration(double x0, double eps, int mode);

#endif