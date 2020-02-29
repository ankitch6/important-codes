/*This code is the property of Ankit Choudhary*/
//Program to count the number of Valid Triangles in an array of Positive integers
#include<iostream>
#include<algorithm>
using namespace std;

long long int arr[10000001];
int main(void)
 {
	int t;
	scanf("%d", &t);
	while(t--)
	{
	    int n;
	    scanf("%d", &n);
	    for(int i=0;i<n;i++)
	        scanf("%d", &arr[i]);

        sort(arr, arr+n);
	    long long int i,j,k;
	    long long int count = 0;
	    for(k=n-1; k>=0; k--)
	    {
	        i=0;j=k-1;
	        while(i<j)
	        {
	            if(arr[i]+arr[j] > arr[k])
	            {
	                count+=(j-i);
	                j--;
	            }
	            else
	                i++;
	        }
	    }
	    printf("%lld\n", count);
	}
	return 0;
}
