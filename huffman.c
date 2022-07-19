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
