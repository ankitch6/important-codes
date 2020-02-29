//Time complexity: O(N^2) Space Complexity: O(1)
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    printf("Please enter the string: ");
    string st;
    cin>>st;
    int max_len = 1;
    int start_index = 0;
    int len = st.length();
    int low, high;

    for(int i=1; i<len; i++)
    {
        //check for even length palindrome
        low = i-1;
        high = i;

        while(low>=0 && high<len && st[low]==st[high])
        {
            if(high-low+1 > max_len)
            {
                max_len = high-low+1;
                start_index = low;
            }
            --low;
            ++high;
        }
        //keeping this I as center for the Palindrome
        low = i-1;
        high = i+1;

        while(low>=0 && high<len && st[low]==st[high])
        {
            if(high-low+1 > max_len)
            {
                max_len = high-low+1;
                start_index = low;
            }
            --low;
            ++high;
        }
    }
    cout<<st.substr(start_index, max_len)<<endl;
    return 0;
}
