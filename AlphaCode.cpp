//Dynamic Programming
//Alpha Code
#include<iostream>
using namespace std;

char input[5001];
int DP[5005];
int findDP(int length)
{
    if(length==1)
        return 1;
    DP[0]=1;
    DP[1]=1;

    for(int i=2;i<=length; i++)
    {
        int x = (input[i-2]-'0')*10 + (input[i-1]-'0');

        if(x < 10)
            DP[i]= DP[i-1];
        else if(x%10 == 0)
            DP[i]= DP[i-2];
        else if(x <= 26)
        {
            DP[i]= DP[i-1] + DP[i-2];
        }
        else
        {
            DP[i]= DP[i-1];
        }
    }
    return DP[length];
}

int main(void)
{
    scanf("%s", input);
    while(input[0] != '0')
    {
        int len=0;
        for(int i=0;input[i]!='\0'; i++)
            len++;
        int ans = findDP(len);
        cout<<ans<<endl;
        scanf("%s", input);
    }
    return 0;
}
