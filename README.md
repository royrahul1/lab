```
/*
//Mergesort
#include <stdio.h>
void Merge(int a[],int l,int m,int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
  
    int L[n1], R[n2];
  
    for (i = 0; i < n1; i++)
        L[i] = a[l+i];
    for (j = 0; j < n2; j++)
        R[j] = a[m+1+j];
  
    i = 0; 
    j = 0;
    k = l;
    while (i<n1 && j<n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        }
        else{
            a[k] = R[j];
            j++;
        }
        k++;
    }
  
    while(i<n1){
        a[k] = L[i];
        i++;
        k++;
    }
    
    while(j<n2){
        a[k]=R[j];
        j++;
        k++;
    }
}
void MergeSort(int a[],int l,int r){
    if(l<r){
        int m=(l+r)/2;
        
        MergeSort(a,l,m);
        MergeSort(a,m+1,r);
        
        Merge(a,l,m,r);
    }
}
int main(){
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements:\n");
    for(int i=0;i<n;i++){
        printf("A[%d]: ",i);
        scanf("%d",&a[i]);
    }

    MergeSort(a,0,n-1);
    printf("The Sorted Array:\n");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");}

    return 0;
}
*/

/*
//Mergesort array
#include <stdio.h>
void MergeSort(int a[],int m,int b[],int n,int c[],int s){
    int i=0,j=0,k=0;
    while(i<m && j<n){
        if(a[i]<b[j]){
            c[k]=a[i];
            i++;
            k++;
        }
        else{
            c[k]=b[j];
            j++;
            k++; 
        }
    }
    while(i<m){
        c[k]=a[i];
        i++; 
        k++;
    }
    while(j<n){
        c[k]=b[j];
        j++; 
        k++;
    }
}
int main(){
    int m,n,s;
    printf("Enter the size of first array: ");
    scanf("%d",&m);
    int a[m];
    printf("Enter the elements:\n");
    for(int i=0;i<m;i++){
        printf("A[%d]: ",i);
        scanf("%d",&a[i]);
    }

    printf("Enter the size of second array: ");
    scanf("%d",&n);
    int b[n];
    printf("Enter the elements:\n");
    for(int i=0;i<n;i++){
        printf("B[%d]: ",i);
        scanf("%d",&b[i]);
    }

    s=m+n;
    int c[s];
    MergeSort(a,m,b,n,c,s);
    printf("The elements of the third array are:\n");
    for(int i=0;i<s;i++){
        printf("%d ",c[i]);
    }
    printf("\n");}
*/


/*
//Selection sort
#include<stdio.h>
int count = 0;
void printarray(int arr[],int n)
{
	for(int i=n-1;i>=0;i--)
	{
		printf("%d ",arr[i]);
	}
  printf("\n");
}
void printarray1(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}printf("\n");
}
void selectionsort(int arr[],int n,int m)
{
	int indexmin,temp;
	for(int i=0; i<n-1;i++)// for passes
	{
		indexmin =i;
		if(i==m)
		{
		printf("array sorted till given pass is \n");
		printarray1(arr,n);	
		printf("\n");
		}
			for(int j= i+1;j<n;j++)
			{
				if(arr[j]<arr[indexmin])
				{
					indexmin =j;
					count ++;
				}
			}
			temp = arr[i];
			arr[i]= arr[indexmin];
			arr[indexmin]=temp;
    }
}
int main()
{
	int n,m;
	printf("enter the size of array\n");
	scanf("%d",&n);
  int arr[n];
	printf("enter the elements of array\n");
	for(int k=0;k<n;k++)
	{
		scanf("%d",&arr[k]);
	}
	printf("enter no of passes\n");
	scanf("%d",&m);
	selectionsort(arr,n,m);
	printf("sorted array in descending order is \n");
	printarray(arr,n);
	//printf("\n");
	printf("number of comparisons are %d\n",count);
}*/

/*
//heapsort
#include <stdio.h>
void swap(int *a, int *b) {

int temp = *a;

*a = *b;

*b = temp;

}

void heapify(int arr[], int n, int i) {
int largest = i;
int left = 2 * i + 1;
int right = 2 * i + 2;
if (left < n && arr[left] > arr[largest])

	largest = left;
if (right < n && arr[right] > arr[largest])

	largest = right;

if (largest != i) {

	swap(&arr[i], &arr[largest]);

	heapify(arr, n, largest);

}

}

void heapSort(int arr[], int n) {
for (int i = n / 2 - 1; i >= 0; i--)

	heapify(arr, n, i);
  for (int i = n - 1; i >= 0; i--) {
  
  	swap(&arr[0], &arr[i]);
  
  	heapify(arr, i, 0);

}

}

void printArray(int arr[], int n)
{
for (int i = 0; i < n; i++)
	printf("%d ", arr[i]);
printf("\n");

}

int main(){
  int n;
  printf("Enter the size of the array: ");
  scanf("%d",&n);
  int a[n];
  printf("Enter data: ");
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  printf("Max heap: \n");
  heapSort(a,n);
  printArray(a,n);
  return 0;
}*/

/*
//Huffman
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
}*/

/*

//Insertionsort
#include<stdio.h>
int count = 0;
void printArray(int array[],int n){
  for(int i=0;i<n;i++){
    printf("%d\t",array[i]);
  }
  printf("\n");
}

void Insertion(int arr[], int n, int k){
  int temp;
  int  j;
  for(int i=0;i<n;i++){
    if(k==n){
      printf("Array is sorted till %d",k);
      printArray(arr,k);
    }
    temp=arr[i];
    j=i-1;
    while( temp<arr[j] && j>=0){
      arr[j+1]=arr[j];
      --j;
      count++;
    }
    arr[j+1]=temp;
  }
  
}

int main(){
  int n,k;
  printf("Enter the size of the array: ");
  scanf("%d",&n);
  int arr[n];
  printf("Enter the elements in the array\n");
  for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }
  printf("Enter the value of k: ");
  scanf("%d",&k);
  printf("Array is sort till given number\n");
  Insertion(arr,n,k);
  printArray(arr,n);
  printf("Number of steps required is %d\n",count);
  return 0;
}*/

/*
//Fractional Knapsack
#include <stdio.h>

void main()
{
    int capacity, no_items, cur_weight, item;
    int used[10];
    float total_profit;
    int i;
    int weight[10];
    int value[10];

    printf("Enter the capacity of knapsack:\n");
    scanf("%d", &capacity);

    printf("Enter the number of items:\n");
    scanf("%d", &no_items);

    printf("Enter the weight and value of %d item:\n", no_items);
    for (i = 0; i < no_items; i++)
    {
        printf("Weight[%d]:\t", i);
        scanf("%d", &weight[i]);
        printf("Value[%d]:\t", i);
        scanf("%d", &value[i]);
    }

    for (i = 0; i < no_items; ++i)
        used[i] = 0;

    cur_weight = capacity;
    while (cur_weight > 0)
    {
        item = -1;
        for (i = 0; i < no_items; ++i)
            if ((used[i] == 0) &&
                ((item == -1) || ((float) value[i] / weight[i] > (float) value[item] / weight[item])))
                item = i;

        used[item] = 1;
        cur_weight -= weight[item];
        total_profit += value[item];
        if (cur_weight >= 0)
            printf("Added object %d (%d Rs., %dKg) completely in the bag. Space left: %d.\n", item + 1, value[item], weight[item], cur_weight);
        else
        {
            int item_percent = (int) ((1 + (float) cur_weight / weight[item]) * 100);
            printf("Added %d%% (%d Rs., %dKg) of object %d in the bag.\n", item_percent, value[item], weight[item], item + 1);
            total_profit -= value[item];
            total_profit += (1 + (float)cur_weight / weight[item]) * value[item];
        }
    }

    printf("Filled the bag with objects worth %.2f Rs.\n", total_profit);
}*/

/*
// 0/1 Knapsack

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
*/

/*
//Countingsort

#include <stdio.h>
void counting_sort(int A[], int k, int n)
{

    int i, j;
    int B[15], C[100];
    for (i = 0; i <= k; i++)
        C[i] = 0;
    for (j = 1; j <= n; j++)
        C[A[j]] = C[A[j]] + 1;
    for (i = 1; i <= k; i++)
        C[i] = C[i] + C[i-1];
    for (j = n; j >= 1; j--)
    {
        B[C[A[j]]] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }
    printf("The Sorted array is : ");
    for (i = 1; i <= n; i++)
        printf("%d ", B[i]);
}
int main()
{
    int n, k = 0, A[15], i;
    printf("Enter the number of input : ");
    scanf("%d", &n);
    printf("\nEnter the elements to be sorted :\n");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &A[i]);
        if (A[i] > k) {
            k = A[i];
        }
    }
    counting_sort(A, k, n);
    printf("\n");
    return 0;
}
*/

/*
//CoinChange

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
*/
/*
//Recursive BSearch
#include<stdio.h>
int count = 0;

int recursive(int arr[],int key,int low, int high)
{
	int mid;
	mid = (low+high)/2;
	if(arr[mid]== key)
	{
		count ++;
		return mid;
		
	}
	else if(arr[mid]<key)
	{
		count ++;
		return recursive(arr,key,mid+1,high);
	}
	else if(arr[mid]>key)
	{
		count++;
		return recursive(arr,key,low,mid-1);
	}
  return -1;
}
int main()
{
	int arr[20];
	int n,u;
	printf("enter size of array\n");
	scanf("%d",&u);
	printf("enter the elements of the array\n");
	for(int i=0;i<u;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("enter element to be searched \n");
	scanf("%d",&n);
	int index = recursive(arr,n,0,u-1);
	
	printf("element found at index %d \n",index);
	printf("no of comparisons are  %d \n",count);
}
*/

/*
//Iterative BSearch
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
  return key;
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
*/
/*
//bfs
#include <stdio.h>

int Q[30];
int f=-1,r=-1;

typedef struct node {
  int col;
  int dist;
  int par;

}node;

int isEmpty(int Q[]){
  if(f==-1)
    return 1;

  else
    return 0;
}

void enQueue(int Q[], int k){
  if(f==-1){
    f++;
    r++;
    Q[r]=k;
  }

  else{

    if((r+1)%30==f)
      printf("Queue is Full\n");

    else{
      r=(r+1)%30;
      Q[r]=k;
    }

  }

}


int deQueue(int Q[]){
  if(f==-1){
    printf("Queue is Empty\n");
    return -1;
  } else {
      if(f==r){
        int temp = Q[f];
        f=-1;
        r=-1;
        return temp;
      } else {
        int temp = Q[f];
        f = (f+1)%30;
        return temp;
      }

  }

}

void PrintPath(int g[][10], node *n, int s, int u)
{
  if(s==u)
    printf("%d ",s);
  else if(n[u].par==-1)
    printf("No Path from %d to %d",s,u);
  else
  {
    PrintPath(g,n,s,n[u].par);
    printf("%d ",u);
  }
}

void bfs(int g[][10], struct node *v, int s){
  int i,j,k;
  for(i=0;i<10;i++){
    if(i!=s){
      v[i].col=0;
      v[i].dist=55555;
      v[i].par=-1;
    }

  }

  v[s].col=1;
  v[s].dist=0;
  v[s].par=-1;
  enQueue(Q, s);

  while(!isEmpty(Q)){

    int u = deQueue(Q);
    for(i=0;i<10;i++){

      if(i!=u){

        if(g[u][i]==1 && v[i].col==0){

          v[i].col=1;
          v[i].dist=v[u].dist+1;
          v[i].par=u;
          enQueue(Q, i);
        }
      }
    }
    v[u].col=2;
  }
}

int main(void) {
  int i,j,g[10][10]={0};
  int src;
  printf("Source node: ");
  scanf("%d", &src);
  node v[10]={0};
  for(i=0;i<10;i++)
    for(j=0;j<10;j++)
      scanf("%d", &g[i][j]);
  bfs(g, v, src);
  printf("Path from Source:%d to all other nodesn\n", src);
  for(i=0;i<10;i++)
  {
    PrintPath(g,v,src,i);
    printf("\n");
  }
  return 0;
}
*/
```
