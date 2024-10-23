#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <math.h>

double EPSILON =0.0001;
// double x;

// int y = pow(x,6);

// Function to evaluate the given equation
double f(double x) {
    // Replace this with your desired function
    return (pow(x,6)-x-1);  
}

// Bisection Method
double bisectionMethod(double a, double b) {
    double c;
    int iterations = 0;

    if (f(a) * f(b) >= 0) {
        printf("Incorrect interval\n");
        return 0;
    }

    while ((b - a) >= EPSILON) {
        c = (a + b) / 2;
        if (f(c) == 0.0) {
            break;
        } else if (f(c) * f(a) < 0) {
            b = c;
        } else {
            a = c;
        }
        iterations++;
    }

    printf("Bisection Method: Root = %lf, Iterations = %d\n", c, iterations);
    return c;
}

// Newton-Raphson Method
double newtonRaphsonMethod(double x0) {
    double x1, f_x0, f_prime_x0;
    int iterations = 0;

    do {
        f_x0 = f(x0);
        f_prime_x0 = (6*pow(x0,5)-1); // Derivative of the function

        if (f_prime_x0 == 0) {
            printf("Derivative is zero. Cannot continue.\n");
            return 0;
        }

        x1 = x0 - f_x0 / f_prime_x0;
        x0 = x1;
        iterations++;

    } while (fabs(f(x1)) > EPSILON);

    printf("Newton-Raphson Method: Root = %lf, Iterations = %d\n", x1, iterations);
    return x1;
}

// Secant Method
double secantMethod(double x0, double x1) {
    double x2, f_x0, f_x1;
    int iterations = 0;

    do {
        f_x0 = f(x0);
        f_x1 = f(x1);

        if (f_x1 - f_x0 == 0) {
            printf("Division by zero. Cannot continue.\n");
            return 0;
        }

        x2 = x1 - (f_x1 * (x1 - x0)) / (f_x1 - f_x0);
        x0 = x1;
        x1 = x2;
        iterations++;

    } while (fabs(f(x2)) > EPSILON);

    printf("Secant Method: Root = %lf, Iterations = %d\n", x2, iterations);
    return x2;
}

int main() {
    double a = 1, b = 3; // Initial interval for Bisection Method
    double x0 = 0; // Initial guess for Newton-Raphson Method
    double x1 = 1.5; // Second initial guess for Secant Method
    int input;
    printf( "1. bisection method\n" );
    printf( "2. newton method\n" );
    printf( "3. secant method\n" );
    printf( "4. Exit\n" );
    printf( "Selection: " );


    scanf( "%d", &input );
    switch ( input ) {
        case 1:            /* Note the colon, not a semicolon */
            bisectionMethod(a, b);
            break;
        case 2:          
            newtonRaphsonMethod(x0);
            break;
        case 3:         
            secantMethod(x0, x1);

            break;
        case 4:        
            printf( "Thanks for playing!\n" );
            break;
        default:            
            printf( "Bad input, quitting!\n" );
            break;
    }
    getchar();
 
}
  
