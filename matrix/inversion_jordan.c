//Implememtation of gauss jordan method
#include <stdio.h>
#include <math.h>
#define _ZERO 0.0000005
#define _M 20
#define _N 40

int printmat(float mat[_M][_N],int n, int  res){
    //prints a augmented matrix for sq matrix of order n.
    // res = 1 represents result matrix. || res = 0 represents augmented matrix. 
    
    int i,j;
    printf("\n");
    for(i=1; i<=n; i++){
        printf("[  ");
        for(j= 1 + res * n;j<=2*n;j++){
            printf("%+.4f    ", mat[i][j]);
        }
        printf("]\n");
    }
    return 0;
}


int main()
{
    float A[_M][_N],c;
    int i,j,k,n;
  
    //Input Data:  
    printf("Enter order of matrix\n");
    scanf("%d",&n);
    printf("Enter elements rowwise\n");     

    for (i=1; i<=n; i++){
        for(j=1; j<=2*n; j++){
            if (j<=n)
                scanf("%f", &A[i][j]);
            else if ( j == n+i)
                A[i][j] = 1;    //Initialization of identity matrix.
            else
                A[i][j] = 0;
        }
    }

    //Elimation
    for(j=1;j<=n;j++)      //For each column
    {
        for(i=1;i<=n;i++)        //For each Element in column
        {
            //    pivot = A[j][j]   //jth row 
            //  check if pivot is zero
            if (fabs(A[j][j]) < _ZERO){
                printf("\nDiagonal Element Zero!\nProgram Termination");
                return 1;
            } 
            if(i!=j)
            {
                c = A[i][j]/A[j][j];  //constant factor

                //Row operation
                for(k=j;k<=2*n;k++)
                {
                A[i][k] = A[i][k] - c * A[j][k];
                }
            }
        }   
    }

    //Making Diagonal Element Unity   
    for(i=1; i<=n; i++)
    {   
        //Row Opearation
        for(k=n+1; k<=2*n; k++)
            A[i][k]=A[i][k]/A[i][i];
    }
    
    //Displaying solution
    printf("\nInverse Matrix is:\n");
    printmat(A, n, 1);
    return 0;
}


/* Test Data:
3
4.23 -1.06 2.11
-2.53 6.77 0.98
1.85 -2.11 -2.32

*/

/* Test Data:
4
2 1 1 0
4 3 3 1
8 7 9 0
6 7 9 8

*/

/* Test Data:
5
14 14 9 3 5
14 52 -15 2 -32
9 15 36 5 16
3 2 5 47 49
5 32 16 49 79

*/
