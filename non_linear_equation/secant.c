// Program to implement Secant Method and find root of given polynomial.
#include <stdio.h>
#include <math.h>

float func(float x){
    return (pow(x, 3) + pow (sin(x), 2) - 5);   
}
    
int main(){
    float a, b, c, req_pr, temp, f_diff;
    int counter;

    //ask for input
    printf("f(x) = pow(x, 3) + pow (sin(x), 2) - 5\n");
    printf("Enter a, b and req_precision");
    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &req_pr);

    //swap a and b so that, b is nearer to root
    if ( fabs(func(a)) < fabs(func(b))){
        temp = a;
        a = b;
        b = temp;
    }

    counter = 0;
    while(1)
    {
        f_diff = func(a) - func(b);     //denominator term in secant formula
        //check for unexpected termination
        if (fabs(f_diff) < 0.0000001){
            printf("Horizontal Secant termination");
            return 1;
        }

        //update variables
        c = a - func(a) * ( a - b) / f_diff;        //secant formula
        a = b;
        b = c;
        counter +=1;

        //check for solution:
        if (fabs(func(c)) < req_pr)
            break;
    }

    //display result
    printf("\nThe root of the equation is: %f\n", c);
    printf("Number of interation = %d", counter);
    return 0;
}
