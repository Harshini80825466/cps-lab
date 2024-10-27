#include <stdio.h>
#include <math.h>
/*
x^6-x-1=0
f(x)=x^6-x-1
*/
//secant
//tol and max_iter globally using #DEFINE 
double f(double x){


  return (pow(x,6) - x - 1.0  );
}
//newton
double dfdx(double x){


  return (6.0*pow(x,5)  - 1.0  );
}




double bisection_method(double a, double b, double tol, int max_iter) {
    if (f(a) * f(b) >= 0) {
        printf("The function must have opposite signs at the endpoints a and b.\n");
        return -1; // Indicate that bisection cannot proceed
    }

    double c;
    for (int i = 0; i < max_iter; i++) {
        c = (a + b) / 2;
        double f_c = f(c);

        // Check if the midpoint is close enough to the root
        if (fabs(f_c) < tol || fabs(b - a) < tol) {
            printf("Converged to root: %.8f after %d iterations\n", c, i + 1);
            return c;
        }

        // Update the interval based on the sign of f(c)
        if (f(a) * f_c < 0) {
            b = c;
        } else {
            a = c;
        }
    }

    printf("Did not converge within the maximum number of iterations.\n");
    return c;
}











double newton( double initial_guess, double tol, int max_iter){
    printf( "Solving using Newton method \n" );
   double x = initial_guess;
    for (int i = 0; i < max_iter; i++) {
        double fx = f(x);
        double fx_prime = dfdx(x);
        
        // Check if the derivative is zero to avoid division by zero
        if (fx_prime == 0) {
            printf("Derivative is zero. No solution found.\n");
            return x;
        }
        
        double x_new = x - fx / fx_prime;

        // Check if the error is within the specified tolerance
        if (fabs(x_new - x) < tol) {
            printf("Converged to root: %.8f after %d iterations\n", x_new, i + 1);
            return x_new;
        }
        
        x = x_new;
    }
    
    printf("Did not converge within the maximum number of iterations.\n");
    return x;
}







void secant(double x0, double x1, double tol, int max_iter ){
int counter= 0;
double x2 = -100;   
do
    {
        if(f(x0)==f(x1))
            {
                printf("f(%lf)=f(%lf) choose different x0 and x1 \n" , x0, x1);
                break;
            }
        x2 = x1 - (((x1-x0)*f(x1))/(f(x1)-f(x0)));
        printf("x2= %lf \n ", x2);
        counter=counter + 1; //counter++;
        printf("at iteration = %d of maxiterations= %d |f(x2)| = %lf  \n ", counter, max_iter, fabs(f(x2)));
        if( counter == max_iter)
            {
                printf("Max iterations reached no convergence \n");
                break;
            }
        x0=x1;
        x1=x2;
    
    } while(fabs(f(x2))> tol);

}


int main()
{
        int input;
    double tol =1e-8;
    int max_iter=100;
        //int option=3;
        double x0 = 50;
        double x1 = 10.82;
        double a = 1;
        double b = 2 ;
        double x2=90.0 ; 
        double initial_guess = 1.1;

        printf( "1. bisection\n" );
        printf( "2. Newton\n" );
        printf( "3. Secant\n" );
        printf( "4. Exit\n" );
        printf( "Selection: " );
        scanf( "%d", &input );
        switch ( input ) {
            case 1:            /* Note the colon, not a semicolon */
                bisection_method(a, b, tol, max_iter);
                break;
            case 2:          
                newton( initial_guess, tol, max_iter);
                break;
            case 3:         
                secant(x0, x1, tol, max_iter);
                break;
            case 4:        
                printf( "Thanks for playing!\n" );
                break;
            default:            
                printf( "Bad input, quitting!\n" );
                break;
        }//end of switch
        getchar();

}
