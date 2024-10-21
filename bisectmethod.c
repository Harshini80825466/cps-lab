#include <stdio.h>
#include <math.h>

double f(double x) {
    return x*x*x*x*x*x -  x + 1;
}

double bisection(double a, double b, double tolerance) {
    double c;
    int iterations = 50;

    while (fabs(b - a) > tolerance) {
        c = (a + b) / 2;

        if (f(c) == 0 || fabs(b - a) / 2 < tolerance)
            return c;

        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;

        iterations++;
    }

    return c;
}

int main() {
    double a = 1, b = 1.5, tolerance = 0.001;
    double root = bisection(a, b, tolerance);

    printf("Root: %.4f\n", root);

    return 0;
}
