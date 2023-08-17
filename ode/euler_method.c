//Euler Method to solve First order differential equation.

#include <stdio.h>
#include <math.h>

float f(float x, float y)
{   
    // f(x, y) = dy/dx
    return ( x*y*y + x*x*y);
}

int main()
{
    float x, y, h, xn;
    printf("dy/dx = x*y*y + x*x*y");
    printf("\nEnter x_o, y_o, x_n, h:\n");
    scanf("%f%f%f%f", &x, &y, &xn, &h); 
    
    printf("\n\tx \ty\n\n");
    while(x < xn)
    {
        printf("  %+.4f  |  %.4f\n", x, y);
        x = x + h;
        y = y + h * f(x, y);
    }
    printf("\n  %+.4f  |  %.4f\n", x, y);
    return 0;
}