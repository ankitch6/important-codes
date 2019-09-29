//LCS
#include<iostream>
#include<cstring>
using namespace std;


int max(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int lcs_recursive(char *X, char *Y, int m, int n)
{
    if(m==0 || n==0)
        return 0;
    else if(X[m-1]==Y[n-1])
        return 1+lcs_recursive(X, Y, m-1, n-1);
    else
        return max(lcs_recursive(X, Y, m, n-1), lcs_recursive(X, Y, m-1, n));
}
int DP[100][100];
void lcs_dynamic(char A[], char B[], int a, int b)
{
    for(int i=0;i<100;i++)
        for(int j=0;j<100;j++)
            DP[i][j]=0;
    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=b;j++)
        {
            if(A[i-1]==B[j-1])
                DP[i][j]=DP[i-1][j-1]+1;
            else
                DP[i][j]=max(DP[i-1][j], DP[i][j-1]);
        }
    }
    cout<<"The length of dynamic lcs is="<<DP[a][b]<<endl;
}
int main(void)
{
    char A[]="abcdefg";
    char B[]="abxdfg";

    int m=strlen(A);
    int n=strlen(B);

    cout<<"Length of recursive LCS is ="<<lcs_recursive(A,B,m,n)<<endl;
    lcs_dynamic(A,B,m,n);
    return 0;
}
