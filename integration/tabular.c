#include <stdio.h>
#define N 200

int main()
{
    int i,n;
    float a, b, Y[N], sum;

    printf("Enter x1, xn and number of data:\n");
    scanf("%f%f%d", &a, &b, &n);
    printf("Enter y values in a row:\n");
    for(i=1; i<=n; i++)
        scanf("%f", &Y[i]);
    
    //Trapezoidal Method
    sum = Y[1] + Y[n];
    for(i=2; i<n; i++)
        sum += 2 * Y[2];
    
    sum = (b-a)/(2*n) * sum;
    
    printf("Area Under the curve is\t: %+.4f", sum);
    return 0;
}

/* Test Data:
0 10 5
8 6 5 4 2.3

*/

/* Test Data:
0 102 18
0 19.8 77.2 105 91.8 74.2 60 47.8 36.2 27.5 19.8 14.2 9.5 5.3 2.7 0 0 0

*/
