// Program to implement NR method and find root of given polynomial.
#include <stdio.h>
#include <math.h>
#define MAX_ITR 200    // maximum iteratin to check oscillation

float func(float x){
    return (pow(x, 3) + pow(x, 2) - 3* x - 3);
    // return (pow(x, 3) + sin(x) + log(x));
    // return (pow(x, 3) + pow (sin(x), 2) - 5);
}

float dfunc(float x){
    return (3*pow(x,2) +  2*x - 3);
    // return (3 * pow(x, 2) + cos(x) + 1.0/x);
    // return (3 * pow(x, 2) + 2 * sin(x) * cos(x));
}

int main(){
    float a, b, req_pr;
    int counter;

    //ask for input
    printf("f(x) = pow(x, 3) + pow(x, 2) - 3* x - 3\n");
    printf("Enter inital guess and req_precision\n");
    scanf("%f", &a);
    scanf("%f", &req_pr);

    counter = 0;
    while(1){
        //check for unexpected conditions
        if (dfunc(a) == 0){
            printf("Zero derivative Termination");
            return 1;
        }
        if (counter > MAX_ITR){
            printf("Root Oscillation termination");
            return 1;
        }
        
        //update variables
        b = a - func(a) / dfunc(a);
        a = b;
        counter +=1;

        //check for solution
        if (fabs(func(b)) < req_pr)
            break;

    }
    //print results
    printf("\nThe root of the eqution is: %+f\n", a);
    printf("Number of iteratin = %d", counter);
    return 0;
}





