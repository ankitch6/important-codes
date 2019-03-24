//Program to find the median of two sorted arrays of same size
#include<bits/stdc++.h>
using namespace std;

double FindMedian(int arr[], int low, int high)
{
    int cnt=high-low+1;//cnt stands for count
    double median=0;
    if(cnt%2==0)//the number of elements in the array segment is even
    {
        int index1= low-1 + cnt/2;
        int index2= low-1 + (cnt/2 + 1);
        median= ((double)arr[index1]+(double)arr[index2])/2;
    }
    else
    {
        int index=  low-1 + (cnt+1)/2;
        median= arr[index];
    }
    return median;
}

double MedianOfTwoSortedArrays(int arr1[], int low1, int high1, int arr2[], int low2, int high2)
{
    int cnt1=high1-low1+1;
    int cnt2=high2-low2+1;
    double m1=FindMedian(arr1, low1, high1);
    double m2=FindMedian(arr2, low2, high2);

    if(cnt1==2 && cnt2==2)
    {
        double median=(max(arr1[low1],arr2[low2])+ min(arr1[high1],arr2[high2]))/2;
        return median;
    }
    if(m1==m2)
        return m1;
    else if(m1>m2)
    {
        //first half of arr1 and second half of second array
        //we need the indexes from where to divide these arrays

        int index1, index2;

        if(cnt1%2==0)
            index1 = low1-1 + (cnt1/2 + 1);
        else
            index1 = low1-1 + (cnt1+1)/2;

        if(cnt2%2==0)
            index2= low2-1 + (cnt2/2);
        else
            index2= low2-1 + (cnt2+1)/2;

        return MedianOfTwoSortedArrays(arr1, low1, index1, arr2, index2, high2);

    }
    else
    {
        //first half of arr2 and second half of arr1
        int index1, index2;
        if(cnt1%2==0)
            index1= low1-1 + (cnt1/2);
        else
            index1= low1-1 + (cnt1+1)/2;

        if(cnt2%2==0)
            index2= low2-1 + (cnt2/2 +1);
        else
            index2= low2-1 + (cnt2+1)/2;

        return MedianOfTwoSortedArrays(arr1, index1, high1, arr2, low2, index2);
    }
}

int main(void)
{
    printf("Enter the size of the array:");
    int n;
    scanf("%d", &n);
    printf("Enter the two arrays:\n");
    int arr1[n],arr2[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr1[i]);
    }
    for(int i=0;i<n;i++)
        scanf("%d", &arr2[i]);

    double median = MedianOfTwoSortedArrays(arr1, 0, n-1, arr2, 0, n-1);
    printf("Median of the Two arrays are: %0.1lf", median);

    return 0;
}
