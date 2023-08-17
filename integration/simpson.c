// Simpson's 3/8th part
#include <stdio.h>
#include <math.h>

float f(float x)
{
    //function to return functional value
    return (1/(1 + x*x));
}

float trapezoidal(float a, float b, int n)
{
    //Computes integral  based on trapezoidal strips.
    float h, sum, integral, x;
    int i;
    
    h = (b-a)/n;
    sum = f(a) + f(b);
    for(i=1;i<n; i++)
    {   
        x = a + h* i;
        sum += 2 * f(x);
    };
    integral = h/2 * sum;
    printf("%+.4f", integral);
}

float simpson_1_3(float a, float b, int n)
{
    //Computes integral using Simpson's 1/3rd formula.
    float h, sum, integral, x;
    int i;

    if (n%2) //odd
    {
        printf("Error! n not divisible by 2.");
        return 1;
    }

    //calculate interval and initialize sums
    h = (b-a)/n;
    sum = f(a) + f(b);
    for (i = 1; i<n; i++) 
    {
        //compute x
        x = a + h*i;
        //check whether i is odd or even and update accordingly
        if (i%2 == 1)   //odd
            sum += 4 *f(x);
        else
            sum += 2 * f(x);
    }   

    //apply Simpson's 1/3rd formula
    integral = h/3 * sum;
    printf("%+.4f", integral);
    return 0;
}

float simpson_3_8(float a, float b, int n)
{
    //Computes integral using Simpson's 1/3rd formula.
    float h, sum, integral, x;
    int i;

    if (n%3) //non-zero modulus
    {
        printf("Error! n not divisible by 3.");
        return 1;
    }

    h = (b-a)/n;
    sum = f(a) + f(b);
    for (i = 1; i<n; i++)
    {
        x = a + h*i;
        if (i%3 == 0)   //multiple of 3
            sum +=  2 *f(x);
        else
            sum += 3 * f(x);
    }   
    
    integral = 3*h/8 * sum;
    printf("%+.4f", integral);
    return 0;
}


int main()
{
    float a, b;
    int n, i;

    //input required variables
    printf("Integral = 1/(1 + x*x) \n");
    printf("Enter a, b and num of interval n:\n");
    scanf("%f%f%d", &a, &b, &n);

    
    printf("\nApproximate Value of Integral is:");
    printf("\nTrapezoidal Method\t: ");
    trapezoidal(a, b, n);
    printf("\nSimpson's 1/3rd Method\t: ");
    simpson_1_3(a, b, n);
    printf("\nSimpson's 3/8th Method\t: ");
    simpson_3_8(a, b, n);
    return 0;
}
