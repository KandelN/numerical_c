// RK-4 method to solve system of first order ordinary differential equation.
#include <stdio.h>
#include <math.h>

float f(float x, float y, float z)
{   // f(x,y,z) = dy/dx
    return ( y*z + x );
}

float g(float x, float y, float z)
{   //g(x,y,z) = dz/dx
    return ( x*z + y );
}

int main()
{
    float x, y, z, h, xn, k[5], l[5];  
    printf("dy/dx = yz + x; dz/dx = xz + y \n");
    printf("Enter x_o, y_o, z_o, x_n, h:\n");
    scanf("%f%f%f%f%f", &x, &y, &z, &xn, &h);

    printf("\n\tx \ty \tz\n\n");
    while( x < xn)
    {
        printf("  %+.4f  |  %+.4f  |  %+.4f\n", x , y, z);
        
        k[1] = h * f(x, y, z);
        l[1] = h * g(x, y, z);
        
        k[2] = h * f(x + h/2, y + k[1]/2, z + l[1]/2);
        l[2] = h * g(x + h/2, y + k[1]/2, z + l[1]/2);

        k[3] = h * f(x + h/2, y + k[2]/2, z + l[2]/2);
        l[3] = h * g(x + h/2, y + k[2]/2, z + l[2]/2);

        k[4] = h * f(x + h, y + k[3], z + l[3]);
        l[4] = h * g(x + h, y + k[3], z + l[3]);

        k[0] = (k[1] + 2 * k[2] + 2 * k[3] + k[4])/6;
        l[0] = (l[1] + 2 * l[2] + 2 * l[3] + l[4])/6;

        x = x + h;
        y = y + k[0];  z = z + l[0];
    }
    printf("\n  %+.4f  |  %+.4f  |  %+.4f\n", x , y, z);
    return 0;
}

/* Test Case:
0 1 -1 0.1 0.01

*/
