=======================//BFS//===================================================================================
```
#include<stdio.h>
int q[20],f=-1,r=-1;
typedef struct{
    int col;
    int d;
    int pi;
}node;
int isEmpty()
{
    if(f==-1&&r==-1)
        return 1;
    else
        return 0;
}
void Enqueue(int k)
{
    if(f==-1&&r==-1)
    {
        f=r=0;
        q[f]=k;
    }
    else{
        r=(r+1)%10;
        q[r]=k;
    }
}
int Dequeue(){
    int ret;
    if(f==r){
        ret=q[f];
        f=r=-1;
    }
    else{
        ret=q[f];
        f=(f+1)%10;
    }
    return ret;
}
void bfs(int g[][30],int n,node *v,int start)
{
    for(int i=0;i<n;i++)
    {
        if(i!=start)
        {
            v[i].col=0;
            v[i].d=35555;
            v[i].pi=-1;
        }
    }
    v[start].col=1;
    v[start].d=0;
    v[start].pi=-1;
    Enqueue(start);
    while(!isEmpty())
    {
        int u=Dequeue();
        for(int i=0;i<n;i++)
        {
            if(i!=u)
            {
                if(g[u][i]==1&&v[i].col==0)
                {
                    v[i].col=1;
                    v[i].d=v[u].d+1;
                    v[i].pi=u;
                    Enqueue(i);
                }
            }
        }
        v[u].col=2;
    }
}
int main()
{
    int n,startnode;
    printf("Enter the number of vertices:\n");
    scanf("%d",&n);
    int g[30][30]={0};
    node v[n];
    printf("Enter the start node:\n");
    scanf("%d",&startnode);
    printf("Enter the adjacency matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&g[i][j]);
        }
    }
    bfs(g,n,v,startnode);
    printf("\nNode\t\tDistance from source: %d\t\t Parent\n",startnode);
    for(int i=0;i<n;i++)
    {
        printf("Node:\n%d\t\t\t%d\t\t%d\t\t\t\t\n",i,v[i].d,v[i].pi);
    }
}
```
=================================//0-1Knapsack//==========================================
```
#include<stdio.h>
#include<stdlib.h>

int max(int a,int b){
    if(a>b)
        return a;
    else
        return b;
}



void Knapsack(int w[],int p[],int n,int m){
     int rows = n+1;
     int col = m+1;

    int table[rows][col];

  
    for(int i=0;i<rows;i++){
        for(int j=0;j<col;j++)
          {
            table[i][j] = 0;
          }
     }


    for(int i = 1;i<rows;i++)
      {
        for(int j = 1;j<col ;j++ )
          {
            if(j>=w[i-1]){
              table[i][j] = max(table[i-1][(j-w[i-1])]+p[i-1],table[i-1][j]);
            }else {
              table[i][j] = table[i-1][j];
            }
          }
      }
  
  printf("\n");
 
    for(int i=0;i<rows;i++)
    {
      for(int j=0;j<col;j++)
        printf("%d ",table[i][j]);

      printf("\n");
    }

  rows-=1;
  col-=1;
  printf("Max Profit is %d -:" ,table[rows][col]);
  printf("\n");
 
  int arr[rows];
  int i=0;
  int k= rows;
   while(col>0)
     {
       if(table[rows][col] == table[rows-1][col])
       {
         rows-=1;
         arr[i] = 0;
         i++;
       }else{
         rows-=1;
         col -=1;
         arr[i] =1;
         i++;
       }
     }

  for(int i=k;i>0;i--)
    {
      printf("%d ",arr[i]);
    }
}





int main(){
    int n,m;
    printf("Enter the number of characters :");
    scanf("%d",&n);
    int w[n];
    int p[n];
    printf("Enter the bag capacity :");
    scanf("%d",&m);
    printf("Enter the weight :");
    for(int i=0;i<n;i++){
        scanf("%d",&w[i]);
    }
    printf("Enter the Price :");
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
    }

    Knapsack(w,p,n,m);
}
```
=============================================//HUFFMAN//==========================================
```
#include<stdio.h>
int size =0;
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void sort(int arr[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(arr[j]<arr[i])
			{
				swap(&arr[j],&arr[i]);
			}
		}
	}
}

void printarray(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n");
}
void minheapify(int arr[],int i)
{
	int min = i;
	int l = 2*i+1;
	int r= 2*i+2;
	
	if(l<size && arr[l]<arr[min])
	{
		min =l;
	}
	if(r<size && arr[r]<arr[min])
	{
		min =r;
	}
	if(min!=i)
	{
		swap(&arr[i],&arr[min]);
		minheapify(arr,min);
	}
}
void buildheap(int arr[])
{
	for(int i=(size/2)-1;i>=0;i--)
	{
		minheapify(arr,i);
	}
}
int extract(int arr[])
{
	int x = arr[0];
	swap(&arr[0],&arr[size-1]);
	size = size-1;
	for(int i=(size/2)-1;i>=0;i--)
		{
			minheapify(arr,i);
		}
	
	return x;
}
void insert(int arr[],int element)
{
	if(size==0)
	{
		arr[0]=element;
		size++;
	}
	else
	{
		arr[size]=element;
		size++;
		for(int i=(size/2)-1;i>=0;i--)
		{
			minheapify(arr,i);
		}
	}
}
void hufmann(int arr[])
{
	while(size>1)
	{
		int x= extract(arr);
		int y= extract(arr);
		insert(arr,x+y);
		sort(arr,size);
		printarray(arr,size);
		
	}
}
int main()
{
	int m,ele;
	printf("enter the number of frequencies\n");
	scanf("%d",&m);
	int arr[m];
	printf("enter the frequencies\n");
	for(int i=0;i<m;i++)
	
	{
	    scanf("%d",&ele);
	    insert(arr,ele);
	}
	sort(arr,size);
	printarray(arr,m);
	printf("\n");
	
	
	hufmann(arr);
}
```
================================//COIN EXCHANGE//=================================
```
#include<stdio.h>
int k=0;
void printarray(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}

void sort(int arr[],int n)
{
	int temp;
	int indexmin;
	
	for(int i=0;i<n-1;i++)
	{
		indexmin =i;
		
		for(int j=i+1;j<n;j++)
		{
			if(arr[j]<arr[indexmin])
			{
				indexmin =j;
			}
			
		}
		temp = arr[i];
		arr[i]=arr[indexmin];
		arr[indexmin]=temp;
	}
}
void coinexc(int D[],int m,int n)
{
	int S[100];
	
	sort(D,m);
	
	for(int i=m-1;i>=0;i--)
	{
		while(n>=D[i])
		{
			S[k]=D[i];
			k++;
			n= n-D[i];
		}
		
		if(n==0)
		{
			break;
		}
	}
	printarray(S,k);
}

int main()
{
	int m,n;
	printf("enter the number of coin denominations\n ");
	scanf("%d",&m);
	int D[m];
	printf("enter the denominations\n");
	for(int i=0;i<m;i++)
	{
		scanf("%d",&D[i]);
	}
	printf("enter the value\n");
	scanf("%d",&n);
	printf("the coins required are\n");
	coinexc(D,m,n);
printf("total coins is %d",k);

	
	
	return 0;
}
```
============================//GREEDY(KNAPSACK)/======================================
```
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

========================//MAX-HEAP//===================
#include<stdio.h>
#include<stdlib.h>
void printarray(int a[] ,int n)
{
for(int i=0;i<n;i++)
{
printf("%d ",a[i]);
}
}
void swap(int *a ,int *b)
{
int temp=*a;
*a=*b;
*b=temp;
}
void maxheapify(int a[], int i, int m)
{
int largest=i;
int l=2*i+1;
int r=2*i+2;
if(l<m && a[l]>a[largest])
{
largest=l;
}
if(r<m && a[r]>a[largest])
{
largest=r;
}
if(largest!=i)
{
swap(&a[largest],&a[i]);

maxheapify(a,largest,m);
}
}
void buildmaxheap(int a[],int m)
{
for(int i=(m/2)-1;i>=0;i--)
{
maxheapify(a,i,m);
}
}
int main()
{
int arr[100],n;
printf("enter size to create array : \n");
scanf("%d",&n);
printf(" enter elements in array :\n");
for(int i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
printf("\n before heapify");
printarray(arr,n);
printf("\n after heapify ");

buildmaxheap(arr,n);
printarray(arr,n);
}
```
//===============================HEAP SORT==============================
```
#include<stdio.h>
#include<stdlib.h>
void printarray(int a[] ,int n)
{
for(int i=0;i<n;i++)
{
printf("%d ",a[i]);
}
}
void swap(int *a ,int *b)
{
int temp=*a;
*a=*b;
*b=temp;
}
void maxheapify(int a[], int i, int m)
{
int largest=i;
int l=2*i+1;
int r=2*i+2;
if(l<m && a[l]>a[largest])
{
largest=l;
}
if(r<m && a[r]>a[largest])
{
largest=r;
}
if(largest!=i)
{
swap(&a[largest],&a[i]);

maxheapify(a,largest,m);
}
}
void buildmaxheap(int a[],int m)
{
for(int i=(m/2)-1;i>=0;i--)
{
maxheapify(a,i,m);
}
}
void heapsort(int a[],int m)
{
buildmaxheap(a,m);
for(int i=m;i>=2;i--)
{
swap(&a[0],&a[m-1]);
m--;
buildmaxheap(a,m);
}
}
int main()
{
int arr[100],n;
printf("\n enter size to create array : \n");
scanf("%d",&n);
printf("\n enter elements in array :\n");
for(int i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
printf("\n before heapify");
printarray(arr,n);
printf("\n after heapify ");

heapsort(arr,n);
printarray(arr,n);
}
```
===============================QUICK SORT================================
```
#include<stdio.h>
#include<stdlib.h>
void swap (int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}
int partition(int arr[], int low,int high) {
    int pivot = arr[low];
    int j = low + 1;
    for(int i = low + 1; i <= high; i++) {
        if(arr[i] < pivot) {
            if(i != j) { 
                swap(&arr[j], &arr[i]);
            }
            j++;
        }
    }
    arr[low] = arr[j - 1];
    arr[j - 1] = pivot;
    return j - 1;
}
int c = 0;
void quicksort(int arr[], int low, int high) {
    if(low < high) {
        int p_index = partition(arr, low, high);
        quicksort(arr, low, p_index-1);
        quicksort(arr, p_index+1, high);
    }
    c++;
}

int main() {
    printf("Enter Size of Array : ");
    int n; scanf("%d", &n);
    printf("Enter Array Elements : ");
	int *arr = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
	quicksort(arr, 0, n - 1);
	printf("Sorted array : ");
	for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\nCounter : %d",c);
	return 0;
}
```
=========================================MERGE SORT==========================================
```
#include <stdio.h>

int c[100]; int tc=0;
void merge(int a[], int l, int mid, int u){
    int sc=0;
    int k=l;
    int i=l;
    int j=mid+1;
    while(i<=mid && j<=u){
        if(a[i]<=a[j]){
            c[k]=a[i];
            i++;
        }
        else {
            c[k]=a[j];
            j++;
        }
        k++; sc++;
    }
    if(i>mid){
        while(j<=u){
            c[k]=a[j];
            k++; j++; sc++;
        }
    }
    else{
        while(i<=mid){
            c[k]=a[i];
            k++; i++; sc++;
        }
    }
    for(int i=l; i<=u; i++){
        a[i]=c[i];
    }
    printf("Step-count: %d,  lower: %d,  mid: %d,  upper: %d\n", sc, l, mid, u);
    tc+=sc;
}
void MergeSort(int a[], int l, int u){
    if(l<u){
        int mid = (l+u)/2;
        MergeSort(a, l, mid);
        MergeSort(a, mid+1, u);
        merge(a, l, mid, u);
    }
}
int main()
{
    int m;
    printf("Enter the size of the array: ");
    scanf("%d", &m);
    int a[m];
    printf("Enter the array elements: ");
    for(int i=0; i<m; i++)  
        scanf("%d", &a[i]);
    MergeSort(a, 0, m-1);
    printf("Sorted Array::\n");
    for(int i=0; i<m; i++)
        printf("%d ", a[i]);
    printf("\nTotal-count: %d", tc);
    printf("\n");
    return 0;
}
```

============================BINARY=======================
```
#include<stdio.h>
int count= 0;

int binarysearch(int arr[],int key, int low , int high)
{
	int mid;
	 while(low<=high)
	 {
	 	mid = (low+high)/2;
	 	
	 	if( arr[mid]==key)
	 	{
	 		count ++;
	 		return mid;
	 		
		 }
		 else if(arr[mid]<key)
		 {
		 	low = mid +1;
		 	count ++;
		 }
		 else
		 {
		 	high = mid -1;
		 	count ++;
		 }
	 }
}
int main()
{
	int arr[20];int n;
	int u;
	printf("enetr the size of array\n");
	scanf("%d",&u);
	
	printf("enter the elements of the array\n");
	for(int i =0;i<u;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("enter element to be searched\n");
	scanf("%d",&n);
	int index = binarysearch(arr,n,0,u-1);
	printf("element found at index %d\n",index);
	printf("no of comparisons are  %d \n",count);
	return  0;
}
```
		
=================================INSERTION===========================
```
#include<stdio.h>
int count = 0;

void printarray(int arr[],int n)
{
	for(int i=n-1;i>=0;i--)
	{
		printf("%d ",arr[i]);
	}
}
void printarray1(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}

void insertionsort(int arr[],int n,int m)
{
	int key;int j;
	for(int i=1;i<n;i++)
	{
		if(i==m)
		{
			printf("array sorted till %d index\n",m);
			printarray1(arr,n);
			printf("\n");
		}
		key = arr[i];
		j= i-1;
		
		while(j>=0 && arr[j]>key)
		{
			arr[j+1]=arr[j];
			j--;
			count ++;
		}
		
		arr[j+1]=key;
	}
}
int main()
{
	int arr[20];
	int n,m;
	printf("enter the size of array\n");
	scanf("%d",&n);
	printf("enter the array elements\n");
	for(int k=0;k<n;k++)
	{
	    scanf("%d",&arr[k]);	
	}
	printf("enter the number of passes\n");
	scanf("%d",&m);
	
	insertionsort(arr,n,m);
	printf("array after sorting\n");
	printarray1(arr,n);
	printf("\n");
	printf("no of step counts are %d\n",count);
	
	
}
```
