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
