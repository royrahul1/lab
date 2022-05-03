# 1
```
#include<stdio.h>
int main(){

   /* Here i & j for loop counters, temp for swapping,
    * count for total number of elements, number[] to
    * store the input numbers in array. You can increase
    * or decrease the size of number array as per requirement
    */
   int i, j, count, temp, number[25];

   printf("How many numbers u are going to enter?: ");
   scanf("%d",&count);

   printf("Enter %d elements: ", count);
   // This loop would store the input numbers in array
   for(i=0;i<count;i++)
      scanf("%d",&number[i]);

   // Implementation of insertion sort algorithm
   for(i=1;i<count;i++){
      temp=number[i];
      j=i-1;
      while((temp<number[j])&&(j>=0)){
         number[j+1]=number[j];
         j=j-1;
      }
      number[j+1]=temp;
   }

   printf("Order of Sorted elements: ");
   for(i=0;i<count;i++)
      printf(" %d",number[i]);

   return 0;
}
```
# 2
```
#include<stdio.h>
int main(){
   /* Here i & j for loop counters, temp for swapping,
    * count for total number of elements, number[] to
    * store the input numbers in array. You can increase
    * or decrease the size of number array as per requirement
    */
   int i, j, count, temp, number[25];

   printf("How many numbers u are going to enter: ");
   scanf("%d",&count);

   printf("Enter %d elements: ", count);
   // Loop to get the elements stored in array
   for(i=0;i<count;i++)
      scanf("%d",&number[i]);
 
   // Logic of selection sort algorithm
   for(i=0;i<count;i++){
      for(j=i+1;j<count;j++){
         if(number[i]>number[j]){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }
   }

   printf("Sorted elements: ");
   for(i=0;i<count;i++)
      printf("%d,",number[i]);

   return 0;
}
```
# 3
```
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
```
