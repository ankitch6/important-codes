#include<bits/stdc++.h>
using namespace std;

int findPivot(int arr[], int low, int high)
{
    if(high<low)
        return -1;
    if(low==high)
        return low;

    int mid=low+(high-low)/2;

    if(mid<high && arr[mid]>arr[mid+1])
        return mid;
    else if(mid>low && arr[mid]>arr[low])
        return findPivot(arr, mid+1, high);
    else if(mid<high && arr[mid]<arr[high])
        return findPivot(arr, low, mid-1);

}

int binarySearch(int arr[], int low, int high, int key)
{
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(arr[mid]==key)
            return mid;
        else if(key< arr[mid])
            high=mid-1;
        else
            low=mid+1;
    }
    return -1;
}
int PivotedBinarySearch(int arr[], int n, int key)
{
    int pivot=findPivot(arr,0,n-1);
    if(pivot==-1)
        return binarySearch(arr,0,n-1,key);

    if(arr[pivot]==key)
        return pivot;
    else if(key<arr[0])
        return binarySearch(arr, pivot+1, n-1, key);
    return binarySearch(arr,0, pivot-1, key);
}

int main(void)
{

    int n;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    int arr[n+1];
    printf("Enter the elements one by one...\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nEnter the element to be searched:");
    int x;
    scanf("%d",&x);
    int index=PivotedBinarySearch(arr,n,x);
    if(index==-1)
        printf("Element not found :(\n");
    else
        printf("The element was found at index %d",index);
    return 0;
}
