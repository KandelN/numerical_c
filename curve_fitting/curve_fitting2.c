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
        scanf("%f %f", &x[i], &y[i]);
        //transfer x and y value.
        x[i] = log(x[i]);
        y[i] = log(y[i]);
    }
    printf("LOG:\n");
    for (i=0; i<n; i++)
    {
        
        printf("%.4f  ,  %.4f\n",x[i],y[i]);
    }

    //compute sum
    for (i=0; i<n; i++)
    {
        sumx += x[i];
        sumxy += x[i] * y[i];
        sumxx += x[i] * x[i];
        sumy += y[i];
    }
    printf("\nsumx= %f\nsumy=%f\nsumxy=%f\nsymxx=%f\n",sumx, sumy, sumxy, sumxx);

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
1 2
2 5
3 8
4 12
5 14
6 18
7 19
8 28
*/

/*
TEST DATA:
1 4
2 6
3 12
4 19
5 25
6 31
7 33
8 38
*/


/*
TEST DATA:
2 4
5 6
8 12
12 19
14 25
18 31
19 33
*/


/*
special dta

6
1.5 4.52
1.9 3.24
2.3 2.7
2.7 1.97
3.1 1.66
3.5 1.36

*/