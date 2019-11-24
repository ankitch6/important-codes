#include<bits/stdc++.h>
using namespace std;
/**  Recursive Solution
int S;//desired sum
bool subset_sum(int arr[], int index, int sum)
{
    if(sum > S || index < 0)
        return false;
    if(index == 0)
    {
        if(sum == S)
            return true;
        else if(sum + arr[0] == S)
            return true;
        else
            return false;
    }
    if(sum == S) return true;

    return subset_sum(arr, index-1, sum+arr[index]) || subset_sum(arr, index-1, sum);

}

int main(void)
{
    int arr[] = {3, 34, 4, 12, 5, 2};
    int len = sizeof(arr)/sizeof(arr[0]);
    S = 11;
    bool ans = subset_sum(arr, len-1, 0);
    if(ans)
        printf("true");
    else
        printf("false");

    return 0;
}
**/
/*This code is the property of Ankit Choudhary*/
/* https://practice.geeksforgeeks.org/problems/subset-sum-problem/0 */
int arr[101];
bool DP[101][100001];

int main(void)
 {
	int t;
	scanf("%d", &t);
	int N;
	while(t--)
	{
	    scanf("%d", &N);
	    int sum = 0;

	    for(int i=0; i<N; i++)
	    {
	        scanf("%d", &arr[i]);
	        sum+= arr[i];
	    }
	    if(sum%2 == 1)
	    {
	        printf("NO\n");
	        continue;
	    }
	    sum = sum/2;

	    for(int i = 0; i <= N; i++)
	        DP[i][0] = true;

	    for(int i = 0; i < N; i++)//the elements of the set
	    {
	        for(int j = 1; j <= sum; j++)//the sum required
	        {
	             if(i == 0)
	             {
	                 if(j == arr[0])
	                    DP[i][j] = true;
	                 else
	                    DP[i][j] = false;
	             }
	             else
	             {
	                 if(j < arr[i])
	                 {
	                     DP[i][j] = DP[i-1][j];
	                 }
	                 else
	                 {
	                     DP[i][j] = DP[i-1][j] || DP[i-1][j-arr[i]];
	                 }
	             }
	        }
	    }
	    if(DP[N-1][sum])
	        printf("YES\n");
	    else
	        printf("NO\n");
	}
	return 0;
}
