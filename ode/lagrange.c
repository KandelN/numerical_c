//Implementation of Langrange Interpolation technique.
#include <stdio.h>
#include <math.h>
#define N 200

int main()
{
    float x[N], y[N], x_req, sum, prod;
    int i, j, n;

    //input
    printf("Enter Number of data set:\n");
    scanf("%d", &n);
    printf("Input x and y pairwise:\n");
    for (i=1; i<=n; i++)
        scanf("%f%f", &x[i], &y[i]);
    printf("Enter vaule of x:\n");
    scanf("%f",&x_req);

    // y = sum_i_0_n(  y_i * prod_j_1_n( [x - x_j]/[x_i - x_j] if i !=j  )  )
    sum = 0;    //holds value of y
    for (i=1; i<=n; i++)
    {   
        prod = 1;
        for (j=1; j<=n; j++)
        {  
            if (i!=j)
                prod *= (x_req- x[j])/(x[i] - x[j]);
        }
        sum += prod * y[i];
    }

    printf(" y(%+.4f) = %+.4f", x_req, sum);
    return 0;
}

/* Test Data:
5
5 150
7 392
11 1452
13 2366
17 5202
9

[810]
*/
/*
5
0.4 150
0.3 392
0.2 1452
0.1 2366
0.0 5202
-4.5

*/
/*
5
1 10
2 32
3 42
4 47
5 49
3.25

*/