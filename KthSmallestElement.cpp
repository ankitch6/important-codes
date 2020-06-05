/* Using QuickSelect Method
   Worst Case is O(n^2) when random selects the last element every time.
   Expected Time Complexity is O(n)
*/
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;


void swap(int *a, int *b)

{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}
void random_check(int arr[], int low, int high, int n)
{
    int r = rand()%n;
    int idx = r + low;
    //swap index with high
    swap(arr[idx], arr[high]);
    return;
}
int partition_index(int arr[], int low, int high)
{
    random_check(arr, low, high, high-low+1);
    int num = arr[high];
    int it = low;
    for(int i=low; i<high; i++)
    {
        if(arr[i] <= num)
        {
            swap(arr[i], arr[it]);
            it++;
        }
    }
    swap(arr[it], arr[high]);
    return it;
}
void quicksort(int arr[], int low, int high, int k)
{
    if(low<high)
    {
        int p = partition_index(arr, low, high);
        if(p == k-1){
            return;
        }
        else if(p > k-1)
            quicksort(arr, low, p-1, k);
        else
            quicksort(arr, p+1, high, k);
    }
}

int main(void)
{
    int n,k;
    cin>>n;
    int arr[n];
    srand(time(NULL));
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cin>>k;
    quicksort(arr, 0, n-1,k);
    cout<<arr[k-1]<<endl;
    return 0;
}
