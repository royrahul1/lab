#include<stdio.h>
int main(){
  int c=0;
    int n,m,j=0;
    printf("Enter the value to CHANGE: ");
    scanf("%d",&n);
    printf("Enter the number of Denominations: ");
    scanf("%d",&m);
    int D[m],s[50];
    printf("Enter the Denominations: ");
    for (int i = 0; i < m; i++)
    {
        scanf("%d",&D[i]);
    }
    for (int i = m-1; i>=0; i--)
    {
        while(n>=D[i])
        {
            s[j]=D[i];
            j++;
            n=n-D[i];
            c++;
        }
        if(n==0)
            break;
    }
    printf("The optimal solution is:\n");
    for (int i = 0; i < j; i++)
    {
        printf("%d\t",s[i]);
    }
    printf("\n");
    printf("Total used coins are %d.\n",c);
    return 0;
}
