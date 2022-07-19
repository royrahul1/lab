#include <stdio.h>
int count=0;
int partition(int a[],int p,int r)
{
  
  int temp;
  int x=a[p];
  int i=r+1;
  for(int j=r;j>=p+1;j--)
    {
       count++;
      if(a[j]>=x)
      {
        count++; 
        i=i-1;
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        
      }
      
    }
  temp=a[i-1];
  a[i-1]=a[p];
  a[p]=temp;
return (i-1);
}
void quicksort(int a[],int p,int r)
{
  int pivot=p;
  int high=r;
  if(p<r)
  {
     
    int q=partition(a,p,r);
    quicksort(a,p,q-1);
    quicksort(a,q+1,r);
    count++;
  }
}
int main()
{
  int a[30],k,n;
  printf("enter the no. of elements:");
  scanf("%d",&n);
  printf("enter the elements:\n");
  for(k=0;k<n;k++)
    {
      scanf("%d",&a[k]);
    }
  quicksort(a,0,n-1);
  printf("sorted array is:");
  for(k=0;k<n;k++)
    {
      printf("%d ",a[k]);
    }
  printf("\n number of comparisons:%d",count);
  
  return 0;
}
