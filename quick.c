#include <stdio.h> 
int c= 0; 
void swap(int *a,int *b ) 
{ 
    int temp =*a; 
    *a= *b; 
    *b = temp; 
} 
int partition(int a[],int start,int end) 
{ 
    int j ; 
    int pivot = a[end]; 
    int i =(start-1); 
    for(j=start ; j<end ; j++) 
    { 
        if(a[j]<= pivot) 
        { 
            i++; 
            swap(&a[i],&a[j]); 
            c++; 
        } 
    } 
    swap(&a[i+1],&a[end]); 
    c++; 
    return i + 1;  
  
} 
void quicksort(int a[],int start, int end) 
{ 
    if(start < end) 
    { 
        int pi = partition(a,start,end); 
        quicksort(a,start,pi-1); 
        quicksort(a,pi+1,end); 
    } 
} 
void printarray(int a[],int n) 
{ 
    for(int i = 0 ; i< n ; i++) 
    { 
        printf("%d ",a[i]); 
    } 
} 
int main() 
{ 
    int size , arr[100]; 
    printf("enetr the size of an aray \n"); 
    scanf("%d",&size); 
    printf("enetr the elements of the array\n"); 
    for(int  i = 0 ; i<size ;i++) 
    { 
        scanf("%d",&arr[i]); 
    } 
    printf("sorted array is: "); 
    quicksort(arr,0,size-1); 
    printarray(arr,size); 
    printf("\nThe no. of iterations are : %d \n",c); 
} 
 
//(exp-4b-quicksort pivot start) 
 
#include <stdio.h> 
int c= 0; 
void swap(int *a,int *b ) 
{ 
    int temp =*a; 
    *a= *b; 
    *b = temp; 
} 
int partition(int a[],int start,int end) 
{ 
    int j ; 
    int pivot = a[start]; 
    int i =(end+1); 
    for(j=end ; j>start ; j--) 
    { 
        if(a[j]>= pivot) 
        { 
            i--; 
            swap(&a[i],&a[j]); 
            c++; 
        } 
    } 
    swap(&a[i-1],&a[start]); 
    c++; 
    return i - 1;  
  
} 
void quicksort(int a[],int start, int end) 
{ 
    if(start < end) 
    { 
        int pi = partition(a,start,end); 
        quicksort(a,start,pi-1); 
        quicksort(a,pi+1,end); 
    } 
} 
void printarray(int a[],int n) 
{ 
    for(int i = 0 ; i< n ; i++) 
    { 
        printf("%d ",a[i]); 
    } 
} 
int main() 
{ 
    int size , arr[100]; 
    printf("enetr the size of an aray \n"); 
    scanf("%d",&size); 
    printf("enetr the elements of the array\n"); 
    for(int  i = 0 ; i<size ;i++) 
    { 
        scanf("%d",&arr[i]); 
         
    } 
    printf("sorted array is: "); 
    quicksort(arr,0,size-1); 
    printarray(arr,size); 
    printf("\nThe no. of iterations arr : %d \n",c); 
}
