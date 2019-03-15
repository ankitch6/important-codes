#include<iostream>
using namespace std;

int ternary_search(int low, int high, int key)
{
    if(low<=high)
    {
        int mid1=low+(high-low)/3;
        int mid2=high-(high-low)/3;

        if(arr[mid1]==key)
            return mid1;
        if(arr[mid2]==key)
            return mid2;
        if(arr[mid1]> key)
            return ternary_search(low,mid1-1,key);
        else if(arr[mid2]>key)
            return ternary_search(mid1+1,mid2-1, key);
        else
            return ternary_search(mid2+1,high, key);

    }
    return -1;
}0
