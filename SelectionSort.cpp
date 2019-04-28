#include<iostream>
using namespace std;

void selectionSort(int A[], int n)
{
    for(int i=0;i<=n-2;i++)
    {
        int i_min=i;
        for(int j=i+1;j<n;j++)
        {
            if(A[j] < A[i_min])
                i_min = j;
        }
        int temp = A[i];
        A[i] = A[i_min];
        A[i_min] = temp;
    }
}
int main(void)
{
    int n;
    printf("*******Selection Sort*******\n");
    printf("Time complexity: O(n^2).\n");
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("\nEnter the array elements: ");
    for(int i=0;i<n;i++)
        scanf("%d", &arr[i]);
    selectionSort(arr, n);
    printf("The sorted array is:\n");
    for(int i=0;i<n;i++)
        printf("%d  ", arr[i]);
    return 0;
}
