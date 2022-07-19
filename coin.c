#include <stdio.h>

void main(void){
    int n;
    printf("Enter the no. of denominaitons: ");
    scanf("%d", &n);
    int d[n],i,j;
    printf("Enter the denominations::\n");
    for( i=0; i<n; i++){
            scanf("%d", &d[i]);
    }
    //sorting the denominations
    for( i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++){
            if(d[j]<d[j+1]){
                int t=d[j];
                d[j]=d[j+1];
                d[j+1]=t;
            }
        }
    }
    int v;
    printf("\nEnter the value you want to achieve: ");
    scanf("%d", &v);
    int used[n]; j=0; int total=0, cc=0;
    for(i=0; i<n; i++){
            if(d[i]<=v && v>0){
                used[j]=d[i];
                j++;
                v-=d[i];
                total+=d[i];
                cc++;
            }
    }
    printf("\nTotal value achieved: %d\n", total);
    printf("\nNo. of coins used: %d\n", cc);
    printf("\nUsed coins::\n");
    for(i=0; i<j; i++){
        printf("%d ", used[i]);
    }
    printf("\n");
}
