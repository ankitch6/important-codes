#include<bits/stdc++.h>
using namespace std;

int longestPalindromeSubseq(string s)
{
        int len = s.length();
        int dp[len][len];
        int max_len=1;
        for(int i=0; i<len; i++)
            dp[i][i] = 1;

        for(int k=2;k<=len;k++)
        {
            for(int i=0;i+k<=len;i++)
            {
                int j=i+k-1;

                if(k==2 && s[i]==s[j])
                {
                    dp[i][j]=2;
                }
                else
                {
                    if(s[i]==s[j])
                    {
                        dp[i][j] = 2+ dp[i+1][j-1];
                    }
                    else
                        dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][len-1];
}

int main(void)
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        printf("Enter a string: ");
        string st;
        cin>>st;
        cout<<"Result: "<<longestPalindromeSubseq(st)<<endl;
    }
    return 0;
}
