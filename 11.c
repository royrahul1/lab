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

	
	
	return 0;
}
