/*This code is the property of Ankit Choudhary*/
//Matrix Chain Multiplication Problem
//N is the number of elements in the array, so N-1 is the number of matrices.
//time complexity of this solution is O(N^3)
#include<iostream>
#include<limits.h>
using namespace std;
int main(void)
 {
	int t,n;
	scanf("%d", &t);

	while(t--)
	{
	    scanf("%d ", &n);
	    int arr[n];
	    for(int i = 0; i<n; i++)
	    {
	        scanf("%d", &arr[i]);
	    }
	    //number of arrays is n-1
	    int dp[n-1][n-1];

	    for(int i = 0; i < n-1; i++)
	        dp[i][i] = 0;

	    for(int l = 2; l <= n-1; l++)
	    {
	        for(int i = 0; i < n-1; i++)
	        {
	            int j = i + l - 1;
	            if(j < n-1)
	            {
	                int min = INT_MAX;
	                for(int k = i; k < j; k++)
	                {
	                    int temp = dp[i][k] + dp[k+1][j] + arr[i]*arr[k+1]*arr[j+1];
	                    if(temp < min)
	                        min = temp;
	                }
	                dp[i][j] = min;
	            }
	        }
	    }
	    /*for(int i = 0; i<n-1;i++)
	    {
	        for(int j = 0; j<n-1;j++)
	        {
	            printf("%d ", dp[i][j]);
	        }
	        printf("\n");
	    }*/
	    printf("%d\n", dp[0][n-2]);
	}
	return 0;
}
