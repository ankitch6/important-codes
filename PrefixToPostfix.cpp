#include<iostream>
#include<string>
#include<stack>
using namespace std;


bool isOperand(char c)
{
    if((c>='a' && c<='z')||(c>='A' && c<='Z'))
        return true;
    return false;
}
int main(void)
{
    string prefix;
    cin>>prefix;
    int l = prefix.length();
    stack<string> st;

    for(int i=l-1; i>=0; i--)
    {
        if(isOperand(prefix[i]))
        {
            st.push(prefix.substr(i,1));
        }
        else
        {
            string a = st.top();st.pop();
            string b = st.top();st.pop();
            string res = a+b+prefix[i];
            st.push(res);
        }
    }
    cout<<st.top()<<endl;
    return 0;
}
