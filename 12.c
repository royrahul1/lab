#include<stdio.h>
int max(int a,int b) {
   if(a>b){
      return a;
   } 
   else{
      return b;
   }
}
int knapsack(int W,int wt[],int p[],int n){
   int i, w;
   int knap[n+1][W+1];
   for (i = 0; i <= n; i++) {
      for (w = 0; w <= W; w++) {
         if (i==0 || w==0)
            knap[i][w] = 0;
         else if (wt[i-1] <= w)
            knap[i][w] = max(p[i-1] + knap[i-1][w-wt[i-1]], knap[i-1][w]);
         else
            knap[i][w] = knap[i-1][w];
      }
   }
   return knap[n][W];
}
int main() {
    int n,W;
    printf("Enter the no. of items: ");
    scanf("%d",&n);
    int p[n],w[n];
    printf("Enter the price of items:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
    printf("Enter the weight of items:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&w[i]);
    }
    printf("Enter the capacity of bag: ");
    scanf("%d",&W);
   printf("\nTotal Max. Profit: %d\n",knapsack(W,w,p,n));
   return 0;
}
