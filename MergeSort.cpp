#include<iostream>

void merge(int arr[], int low, int mid, int high)
{
    int len1 = mid-low+1;
    int len2 = high-(mid+1)+1;
    int temp1[len1], temp2[len2];

    int k = low;
    for(int i=0;i<len1;i++)
        temp1[i]=arr[k++];
    k=mid+1;
    for(int i=0;i<len2;i++)
        temp2[i]=arr[k++];

    int a=0,b=0;
    k=low;

    while(a<len1 && b<len2)
    {
        if(temp1[a]<temp2[b])
            arr[k++]=temp1[a++];
        else
            arr[k++]=temp2[b++];
    }
    while(a<len1)
        arr[k++]=temp1[a++];
    while(b<len2)
        arr[k++]=temp2[b++];
}
void mergesort(int arr[], int low, int high)
{
    if(low<high)
    {
        int mid = low + (high-low)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}
int main(void)
{
    int arr[]= {10,9,8,7,6,5,4,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    mergesort(arr, 0, n-1);
    printf("Sorted List is: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
