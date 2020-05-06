#include<stdio.h>

int main(int argc, char **argv)
{
    int i,j,k,n=0;

    FILE *fp;
    
    fp = fopen(argv[1],"r");

    fscanf(fp,"%d",&n);

    float A[n+1][n+1],c,x[n+1],sum=0.0;

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=(n+1); j++)
        {
            fscanf(fp, "%f",&A[i][j]);
        }
    }
fclose(fp);



    for(j=1; j<=n; j++) /* loop for the generation of upper triangular matrix*/
    {
        for(i=1; i<=n; i++)
        {
            if(i>j)
            {
		//Step 1:
                c=A[i][j]/A[j][j];

		//Step 2:
                for(k=1; k<=n+1; k++)
                {
                    A[i][k]=A[i][k]-c*A[j][k];
                }
            }
        }
    }
    x[n]=A[n][n+1]/A[n][n];
    /* this loop is for backward substitution*/
    for(i=n-1; i>=1; i--)
    {
        sum=0;
        for(j=i+1; j<=n; j++)
        {
            sum=sum+A[i][j]*x[j];
        }
        x[i]=(A[i][n+1]-sum)/A[i][i];
    }
    printf("\nThe solution is: \n");
    for(i=1; i<=n; i++)
    {
        printf("\nx%d=%f\t",i,x[i]); /* x1, x2, x3 are the solutions*/
    }
    return(0);
}
