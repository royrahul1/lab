#include<stdio.h>

int main()
{
    int i,j,k,pass,n;
    int m[20][20],s[10][10],p[10],result;
    printf("Enter the elements:");
    scanf("%d",&n);
    printf("Enter the value of P:");
    for(i=0;i<=n;i++)
    {
        scanf("%d",&p[i]);
    }
    for(i=1;i<=n;i++)
    {
        m[i][i]=0;
    }
    for(pass=2;pass<=n;pass++)
    {
        for(i=1;i<=n-pass+1;i++)
        {
            j=pass+i-1;
            m[i][j]=9999;
            for(k=i;k<j;k++)
            {
                result=m[i][k]+m[k+1][j]+(p[i-1]*p[k]*p[j]);
                if(result<m[i][j])
                {
                    m[i][j]=result;
                    s[i][j]=k;


                }
            }
            printf("\nM[%d][%d]=%d\t",i,j,m[i][j]);
            printf("S[%d][%d]=%d\n",i,j,s[i][j]);
        }
    }
