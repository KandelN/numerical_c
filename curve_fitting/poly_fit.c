//Curve fitting data into polynomial of degree 'd'.
// nelson
#include <stdio.h>
#include <math.h>
#define N 20
#define ZERO 0.0000005

int printmat(float mat[N][N],int r,int c)
{
    int i,j;
    printf("\n");
    for(i=0;i<r; i++)
    {
        printf(" [");
        for(j=0; j<c; j++)
            printf("  %+15.1f",mat[i][j]);
        printf(" ]\n");
    }
}

int main(){
    int n, d, i, j, k;
    float A[N][N], x[N], y[N], c, coeff[N];

    printf("Enter degree of polynomial and no. of data:\n");
    scanf("%d %d", &d, &n);
    printf("Enter data pairwise:\n");
    for (i=0; i<n; i++)
        scanf("%f%f", &x[i], &y[i]);
    
    if (n<=d)
    {  
        printf("Insufficient data for desired degree.\n");
        printf("Proceeding with degree as %d\n", d= n-1);
    }

    //Augmented matrix of coefficient of polynomial
    for (i=0; i<=d; i++)
    {   
        for(j=0; j<=d; j++)
        {
            A[i][j] = 0;
            for(k=0; k<n; k++)  //spans data set
                A[i][j] += pow(x[k], i+j);
        }
        A[i][d+1] = 0;
        for(k=0; k<n; k++)
            A[i][d+1] += pow(x[k], i) * y[k];
    }


    //Gauss Jordan Method
    n = d+1; //number of unknowns
    printmat(A, n, n+1);
    for(j=0; j<n; j++)
    {
        for(i=0; i<n; i++)
        {
            if(i!=j)
            {
                if (fabs(A[j][j]) < ZERO){
                    printf("\nDiagonal Element Zero");
                    return 1;
                }
                c = A[i][j]/A[j][j]; //pivot ratio

                for(k=j; k<=n; k++)
                    A[i][k] -= c*A[j][k];
            
            printmat(A, n, n+1);
            }
        }
    }
    
    printf("\n Polynomial of degree %d is:\n y(x) = ", d);
    for(i=0; i<n; i++)
    {
        coeff[i] = A[i][n]/A[i][i];
        printf(" %+.4f x^(%d)", coeff[i], i);
    }
    return 0;
}


/* Test Data:
2 5
5 150
7 392
11 1452
13 2366
17 5202

*/

/* Test Data:
2 5
5 150
7 392
11 1452
13 2366
17 5202

*/
/* Test Data:
5 6
21 36
32 15
52 78
62 45
64 76
98 75

*/