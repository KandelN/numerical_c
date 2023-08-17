#include <stdio.h>
#include <math.h>
#define N 20
#define MAX_ITR 500

int printvect(float vect[N], int n){
    //Prints a column vecotr of size n
    int i;
    printf("\n");
    for(i=1; i<=n; i++)
        printf(" [  %+.4f  ]\n", vect[i]);
    return 0;
}

float maxabs(float vect[N], int n){
    //returns largest absolute value from a vector.
    int i;
    float mm = fabs(vect[1]), temp;

    for(i=1; i<=n; i++){
        temp = fabs(vect[i]);
        if (temp> mm)
            mm = temp;
    }
    return mm;
}

int main()
{
    float A[N][N], X[N], Z[N], D[N], tol, temp, lambda;
    int n, i, j, k, count;

    //Input Data
    printf("Enter order of matrix and tolorable error:\n");
    scanf("%d%f",&n, &tol);
    printf("Enter elemts of matrix rowise:\n");
    for (i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            scanf("%f", &A[i][j]);
        }
        X[i] = 1;   //initialize unit vector
    } 

    // printf("\n Initial Guess");
    // printvect(X, n);
    count = 1;
    do
    {   
        // [Z] = [A].[X]
        for (i=1; i<=n; i++)
        {
            temp =0;
            for(k=1; k<=n; k++)
                temp += A[i][k] * X[k];
            Z[i] = temp;
        }

        // [Z] = [Z]/lambda   ::reduced [Z]
        lambda = maxabs(Z, n);
        for(i=1; i<=n; i++)
            Z[i] /= lambda;

        // [D] =  [ ( |Z| - |X| ) ]
        for(i =1; i<=n; i++)
            D[i] = fabs(Z[i]) - fabs(X[i]);

        //[X] = [Z]
        for(i=1; i<=n; i++)     
            X[i] = Z[i];    

        //print process
        // printf("\n Step: %d\n Lambda: %+.4f", count, lambda); 
        // printvect(Z, n);

        count ++;
        if (count > MAX_ITR)
        {
            printf("No Eigen Value Found!");
            return 1;
        }

    } while(maxabs(D, n) > tol);
    
    //print result
    printf("\nDominant Eigen Value = %+.4f\n", lambda);
    printf("Corresponding Eigen Vector is:\n");
    printvect(Z, n);
    return 0;
}

/*  Test Data:
3 0.0005
2 3 2
3 4 1
2 1 7

*/

/* Test Data:
3 0.00005
4.23 -1.06 2.11
-2.53 6.77 0.98
1.85 -2.11 -2.32

*/

/* Test Data:
5 0.00005
14 14 9 3 5
14 52 -15 2 -32
9 15 36 5 16
3 2 5 47 49
5 32 16 49 79

*/

