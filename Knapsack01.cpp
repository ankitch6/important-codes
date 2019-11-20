/*This code is the property of Ankit Choudhary*/
#include<iostream>
using namespace std;

int weight[1005];
int val[1005];
int DP[1005][1005];
int main(void)
 {
	int t, N, W;
	scanf("%d", &t);

	while(t--)
	{
	    scanf("%d", &N);//no of items
	    scanf("%d", &W);//total allowed weight in the knapsack

	    for(int i = 1; i <= N; i++)
	        scanf("%d", &val[i]);
	    for(int i = 1; i <= N; i++)
	        scanf("%d", &weight[i]);

	    //when no of items is 0
	    for(int i=0;i<=W;i++)
	        DP[0][i] = 0;
	    //when the maximum weight is 0
	    for(int i=0;i<=N;i++)
	        DP[i][0] = 0;

	    for(int i = 1; i <= N; i++)
	    {
	        for(int j = 1; j <= W; j++)
	        {
	            //if weight of current item is greater than current weight
	            if(weight[i] > j)
	                DP[i][j] = DP[i-1][j];
	            else
	            {
	                DP[i][j] = max(DP[i-1][j], val[i]+DP[i-1][j-weight[i]]);
	            }

	        }
	    }
	    printf("%d\n", DP[N][W]);
	}
	return 0;
}
