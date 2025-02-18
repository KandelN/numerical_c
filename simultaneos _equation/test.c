#include<stdio.h>
#include<conio.h>
#include<math.h>

void main()
{
    float m[50][50],x[50],r;
    int i,j,k,n;
    printf("Enter the number of unknown elements :\n");
    scanf("%d",&n);
    printf("Enter the elements of argument matrix \n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n+1;j++)
        {
            scanf("%f",&m[i][j]);
        }
    }
    for(i=1;i<=n;i++)
    {
        if((fabs(m[i][i]))<0.000005)
        {
            printf("pivotal element is nearly equal to zero so");
        }

        for(j=1;j<=n;j++)
        {
            for(i=1;i<=n;i++)
            {
                if(i!=j)
                {
                    r = m[i][j]/m[j][j];
                    for(k=1;k<=n+1;k++)
                    {
                        m[i][k]=m[i][k]-r*m[j][k];
                    }
                }
            }
        }
    }
    printf("the required values are :\n");
    for(i=1;i<=n;i++)
    {
        x[i]=m[i][n+1]/m[i][i];
        printf("x[%d]=%f\n",i,x[i]);
    }
    getch();
    
}
