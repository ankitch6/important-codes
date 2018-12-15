#include<iostream>
using namespace std;


int arr[1000];//test array for search



//code for iterative binary search
int Binary_Search_I(int low, int high, int key)
{
    while(low<=high)
    {
        int mid= low+ (high-low)/2;
        if(key==arr[mid])
        {
            return mid;
        }
        else if(key< arr[mid])
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return -1;//if no match is found
}

//code for recursive binary search
int Binary_Search(int low, int high, int key)
{
    if(low<=high)
    {
        int mid=low+ (high-low)/2;

        if(arr[mid]==key)return mid;
        else if(arr[mid]>key)return Binary_Search(low,mid-1,key);
        else
        {
            return Binary_Search(mid+1, high, key);
        }
    }
    //we reach here when the element is not present in the array.
    return -1;
}

int main(void)
{
    int n;
    printf("Enter the total no of elements:");
    scanf("%d",&n);
    printf("Enter the array list you want to search");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    //find an element by calling the functions!
    return 0;
}
