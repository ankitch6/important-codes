#include<iostream>

void swap(int arr[], int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
int partition_index(int arr[], int low, int high)
{
    int pivot = high;
    int sIndex = low;
    for(int i=low; i<pivot; i++)
    {
        if(arr[i] < arr[pivot])
        {
            //swap sIndex with i index
            swap(arr, sIndex, i);
            sIndex++;
        }
    }
    swap(arr, sIndex, pivot);
    return sIndex;
}
void quicksort(int arr[], int low, int high)
{
    if(low<high)
    {
        int pi = partition_index(arr, low, high);
        quicksort(arr, low, pi-1);
        quicksort(arr, pi+1, high);
    }
}
int main(void)
{
    int len = 6;
    int arr[] = {4, 3, 1, 10, 22, 6};
    quicksort(arr, 0, len-1);
    for(int i = 0; i<len;i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
    return 0;
}
