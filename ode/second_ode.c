// RK-4 method to solve second order ordinary differential equation.
#include <stdio.h>
#include <math.h>

float g(float x, float y, float z)
{   //g(x,y,z) = dz/dx = d2y/dx2 
    return ( 4*sin(2*M_PI*x) + x* z );
}

int main()
{
    float x, y, z, h, xn, k[5], l[5];
    printf("d2y/dx2 = 4*sin(2*M_PI*x) + x* z;   z = dy/dx \n");
    printf("Enter x_o, y_o, y'_o, x_n, h:\n");
    scanf("%f%f%f%f%f", &x, &y, &z, &xn, &h);

    printf("\n\tx \ty \tdy/dx\n\n");
    while( x < xn)
    {
        printf("  %+.4f  |  %+.4f  |  %+.4f\n", x , y, z);
        
        k[1] = h * z;
        l[1] = h * g(x, y, z);
        
        k[2] = h * (z + l[1]/2);
        l[2] = h * g(x + h/2, y + k[1]/2, z + l[1]/2);

        k[3] = h * (z + l[2]/2);
        l[3] = h * g(x + h/2, y + k[2]/2, z + l[2]/2);

        k[4] = h * (z + l[3]);
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
0 1 0 0.4 0.2

*/