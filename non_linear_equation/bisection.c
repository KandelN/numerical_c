// Program to implement Bisection method and find root of given polynomial.
// example function is f(x) = x^3+ x^2- 3x -3 = 0

#include <stdio.h>
#include <math.h>

float func(float x){
    return (pow(x, 3) + sin(x) + log(x));
}

int main(){
    float a, b, c, req_pr;
    int counter;

    //ask for input
    printf("f(x) = pow(x, 3) + sin(x) + log(x)\n");
    printf("Enter a, b and req_precision");
    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &req_pr);

    if (func(a) * func(b) > 0){
        printf("No Root Inside Interval");
        return 1;
    } 


    c = (a+b)/2;
    counter = 1;

    //loop starts here untill error is within precision
    while ( fabs(func(c)) > req_pr){
        //update a or b based on functional value. 
        if ( func(a) * func(c) > 0){
            a = c;
        }
        else{
            b = c;
        }
        //update c
        c = (a+b)/2;
        counter += 1;

    }

    //display result
    printf("\nThe root of the function is = %f\n", c);
    printf("Number of iteration:%d", counter);
    return 0;
}