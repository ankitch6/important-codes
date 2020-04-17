/*This code is the property of Ankit Choudhary*/
#include<iostream>
using namespace std;
int main(void)
 {
	int t,n;
	scanf("%d", &t);

	while(t--)
	{
        scanf("%d", &n);
    	int arr[n];
    	for(int i=0; i<n; i++)
    	scanf("%d", &arr[i]);
    	int even=1, odd=0;
    	int sum=0, ans = 0;
    	for(int i=0; i<n; i++)
    	{
    	    sum+=arr[i];
    	    if(sum%2==0)
    	        even++;
    	    else
    	        odd++;
    	}
    	ans += even*(even-1);
    	ans += odd*(odd-1);
    	ans = ans/2;
    	cout<<ans<<endl;

	}
	return 0;
}
