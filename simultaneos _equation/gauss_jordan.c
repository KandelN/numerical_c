//Implememtation of gauss jordan method
#include <stdio.h>
#include <math.h>
#define _ZERO 0.0000005
#define _N 20

int printmat(float mat[_N][_N],int  n){
    //prints a augmented matrix for n unknowns.
    int i,j;
    printf("\n");
    for(i=1; i<=n; i++){
        printf("[");
        for(j=1;j<=n;j++){
            printf("%+.4f    ", mat[i][j]);
        }
        printf(":  %+.4f  ]\n", mat[i][j]);
    }
    return 0;
}


int main()
{
    float A[_N][_N],x[_N],c,sum;
    int i,j,k,n;
  
    //Input Data:  
    printf("Enter number of unknowns\n");
    scanf("%d",&n);
    printf("Enter elements rowwise\n");     

    for (i=1; i<=n; i++){
        for(j=1; j<=n+1; j++){
            scanf("%f", &A[i][j]);
        }
    }   

    //Elimation
    printf("\nGaussian Elimination...\n");
    for(j=1;j<=n;j++)      //For each column
    {
        printf("\n=================== Column:%d===============", j);
        for(i=1;i<=n;i++)        //For each Element in column
        {
            if(i!=j)
            {
                //    pivot = A[j][j]   //jth row 
                //  check if pivot is zero
                if (fabs(A[j][j]) < _ZERO){
                    printf("\nDiagonal Element Zero!\nProgram Termination");
                    return 0;
                }   

                c = A[i][j]/A[j][j];  //constant factor

                //Row operation
                for(k=j;k<=n+1;k++)
                {
                A[i][k] = A[i][k] - c * A[j][k];
                }
            }
        }   
            printmat(A, n);    //Displaying matrix for debug
    }

    //Back Substitution
    printf("\nBackward Substitution...\n");    
    for(i=1; i<=n; i++)
    {    
        x[i]=A[i][n+1]/A[i][i];
    }
    
    //Displaying solution
    printf("\nRequired Solutions are:");
    for(i=1; i<=n; i++)
        printf("\nx%d =  %+.4f\t",i,x[i]);

    return 0;
}


/* Test Data:
3
4.23 -1.06 2.11 5.28
-2.53 6.77 0.98 5.22
1.85 -2.11 -2.32 -2.58

[1, 1, 1]
*/

/* Test Data:
4
2 1 1 0 5
4 3 3 1 8
8 7 9 5 1
6 7 9 8 7

[6.75, 4.5, -13, 6.5]
*/

/* Test Data:
5
14 14 9 3 5 -15
14 52 -15 2 -32 -100
9 15 36 5 16 106
3 2 5 47 49 329
5 32 16 49 79 463

[-5.6942, 1.4562, 2.0844, 4.6665, 2.3147]
*/
