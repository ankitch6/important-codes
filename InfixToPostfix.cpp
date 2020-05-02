/*This code is the property of Ankit Choudhary*/
#include<iostream>
#include<string.h>
#include<stack>
using namespace std;


bool isOperand(char c)
{
    if((c>='a' && c<='z')||(c>='A' && c<='Z'))
        return true;
    return false;
}
int precedence(char c)
{
    if(c=='(')
        return -1;
    if(c=='^')
        return 4;
    if(c=='*' || c=='/')
        return 3;
    if(c=='+' || c=='-')
        return 1;
}
int main(void)
 {
	int t;
	cin>>t;
	char str[1005];
	while(t--)
	{
	    scanf("%s", str);
	    int len = strlen(str);
	    stack<char> s;
	    string res = "";

	    for(int i=0; i<len; i++)
	    {
	        if(isOperand(str[i]))
	        {
	            res.push_back(str[i]);
	        }
	        else if(str[i] == ')')
	        {
	            while(s.top() != '(')
	            {
	                res.push_back(s.top());
	                s.pop();
	            }
	            s.pop();
	        }
	        else if(str[i] == '(')
	            s.push(str[i]);
	        else
	        {
	            while(s.empty()==false &&
	                  precedence(s.top()) >= precedence(str[i]))
	            {
	                res.push_back(s.top());
	                s.pop();
	            }
	            s.push(str[i]);
	        }
	    }
	    while(!s.empty())
	    {
	        res.push_back(s.top());
	        s.pop();
	    }
	    cout<<res<<endl;
	}
	return 0;
}
