#include<bits/stdc++.h>
using namespace std;

int binary_operation(int a, int b)
{
    return a*b;
}
int unary_operation(int x)
{
    return x+1;
}
int main(void)
{
    int arr1[] = {1,2,3,4};
    int arr2[] = {4,3,2,1};
    int res[4];
    transform(arr1, arr1+4, arr2, res, binary_operation);
    cout<<"binary operation"<<endl;

    for(int i=0; i<4; i++)
        cout<<res[i]<<" ";
    cout<<endl;

    cout<<"unary operation"<<endl;
    transform(arr1, arr1+4, res, unary_operation);
    for(int i=0; i<4; i++)
        cout<<res[i]<<" ";
    cout<<endl;

    return 0;
}
