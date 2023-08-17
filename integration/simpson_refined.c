// Simpson's 3/8th part
#include <stdio.h>
#include <math.h>

float f(float x)
{
    //function to return functional value
    return (1/(1 + x*x));
}

int main()
{
    float a, b, h, x, trape, simp_1_3, simp_3_8;
    int n, i;

    //input required variables
    printf("Integral = 1/(1 + x*x) \n");
    printf("Enter a, b and num of interval n:\n");
    scanf("%f%f%d", &a, &b, &n);

    h = (b-a)/n;
    //Initialize all
    trape = f(a) + f(b);
    simp_1_3 = trape;
    simp_3_8 = trape;

    for(i=1; i<n; i++)
    {
        x = a + h*i;

        //trapezoidal
        trape += 2 * f(x); 

        //simpson's 1/3rd
        if(i%2 == 0)     //multiple of 2
            simp_1_3 += 2 * f(x);
        else
            simp_1_3 += 4 * f(x);
        
        //simpson's 3/8th 
        if(i%3 == 0)    //multiple of 3
            simp_3_8 += 2 * f(x);
        else
            simp_3_8 += 3 * f(x);
    }

    trape = h/2 * trape;
    simp_1_3 = h/3 * simp_1_3;
    simp_3_8 = 3*h/8 * simp_3_8;
    printf("\nApproximate Value of Integral is:");

    printf("\nTrapezoidal Method\t: ");
    printf("%+.4f", trape);

    printf("\nSimpson's 1/3rd Method\t: ");
    if (n%2)
        printf("Error! n not divisible by 2.");
    else
        printf("%+.4f", simp_1_3);
    
    printf("\nSimpson's 3/8th Method\t: ");
    if (n%3)
        printf("Error! n not divisible by 3.");
    else
        printf("%+.4f", simp_3_8);
        
    return 0;
}
