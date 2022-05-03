#include <stdio.h>
#include <stdlib.h>
#include<time.h>
void InsertionSort(int number[],int count)
{
int i,j,temp;
int cnt=1;
for(i=1;i<count;i++){
temp=number[i];
j=i-1;
while((temp<number[j])&&(j>=0)){
number[j+1]=number[j];
j=j-1;
}
number[j+1]=temp;
}
}
int main(){
int n;
scanf("%d",&n);
int num[n];
srand(time(0));
for(int i = 0; i<n; i++)
num[i]=rand()%500;
for(int i = 0; i<n; i++)
printf("%d ",num[i]);
printf("\n\n");
InsertionSort(num,n);
for(int i = 0; i<n; i++)
printf("%d ",num[i]);
return 0;
}
