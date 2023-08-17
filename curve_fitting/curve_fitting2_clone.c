//  y = a x^b
// Y = A + bX   //captial letter indicate logarithm of corresponding small letter     


#include <stdio.h>
#include <math.h>

int main()
{
    int i, n;
    float x[100], y[100], sumx=0, sumy=0, sumxx =0, sumxy =0, a, b, A;

    printf("Enter no of data set:");
    scanf("%d", &n);

    printf("Input x and y:\n");
    for (i=0; i<n; i++)
    {
        scanf("%f", &x[i]);
        //transfer x and y value.
        x[i] = log(x[i]);
    }
    for (i=0; i<n; i++)
    {
        scanf("%f", &y[i]);
        //transfer x and y value.
        y[i] = log(y[i]);
    }

    //compute sum
    for (i=0; i<n; i++)
    {
        sumx += x[i];
        sumxy += x[i] * y[i];
        sumxx += x[i] * x[i];
        sumy += y[i];
    }

    //Normal equation:
    //  A n +  b sumx = sumy
    //  A sumx + b sumxx = sumxy
    //---analytical formula for 2 var simultaneous equation.
    A = (sumy * sumxx - sumxy * sumx) / (n * sumxx - sumx * sumx);
    b = ( sumy * sumx - sumxy * n) / ( sumx * sumx - n * sumxx);
    a = exp(A);

    //display result
    printf("The regression eqution is:\n");
    printf("y = %f x^(%f)", a , b);

    return 0;
}

/*
TEST DATA:
14
0.15 
0.20 
0.27 
0.30 
0.40 
0.41 
0.58 
0.98 
1.48 
1.80 
2.00 
3.00 
3.60 
4.20 
15 
30 
57 
39 
60 
100 
150 
170 
400 
600 
800 
1500 
2000
2400
*/
