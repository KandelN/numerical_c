//RK-4 to solve First order differential equation.

#include <stdio.h>
#include <math.h>

float f(float x, float y)
{   
    // f(x, y) = dy/dx
    return ( x*y*y + x*x*y);
}

int main()
{
    float x, y, h, xn, k1, k2, k3, k4, k;
    //input
    printf("dy/dx = x*y*y + x*x*y");
    printf("\nEnter x_o, y_o, x_n, h:\n");
    scanf("%f%f%f%f", &x, &y, &xn, &h); 
    
    printf("\n\tx \ty\n\n");
    while(x < xn)
    {
        printf("  %+.4f  |  %.4f\n", x, y);
        
        k1 = h * f(x, y);
        k2 = h * f(x + h/2, y + k1/2);
        k3 = h * f(x + h/2, y + k2/2);
        k4 = h * f(x + h, y + k3);
        k = (k1 + 2*k2 + 2*k3 + k4)/6;
        x = x + h;
        y = y + k;
    }
    printf("\n  %+.4f  |  %.4f\n", x, y);
    return 0;
}