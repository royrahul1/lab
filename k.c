#include <stdio.h>

int max(int a,int b){
	return a>b ? a : b;
}

int knapsack_dp(int w[],int p[],int n,int m){
    int dp[n+1][m+1];

    for(int i=0;i<=n;i++)
        dp[i][0]=0;

    for(int i=0;i<=m;i++)
        dp[0][i]=0;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(j >= w[i-1])
              dp[i][j] = max(p[i-1]+dp[i-1][j-w[i-1]],dp[i-1][j]);
        else 
            dp[i][j] = dp[i-1][j];
        }
    
    printf("\n");
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++)
            printf("%d ",dp[i][j]);
        printf("\n");    
    }
    return dp[n][m];
}

int main() {
    int n,max,m;
    printf("Enter the no of objects: ");
    scanf("%d",&n);
    int w[n],p[n];
  
    printf("Enter the profit of objects: \n");
    for(int i=0;i<n;i++)
        scanf("%d",&p[i]);

    printf("Enter the weight of objects: \n");
    for(int i=0;i<n;i++)
        scanf("%d",&w[i]);
    
    printf("Enter the knapsack capacity: ");
    scanf("%d",&m);
    
    max=knapsack_dp(w,p,n,m);
    printf("\nThe Maximum profit: %d\n",max);
    
    return 0;
}
