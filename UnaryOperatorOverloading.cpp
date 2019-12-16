#include<bits/stdc++.h>
using namespace std;

class Integer
{
private:
    int x;
public:
    void setData(int d)
    {
        x = d;
    }
    void showData()
    {
        cout<<"x="<<x<<endl;
    }
    Integer operator++(int)
    {
        //for compiler to differentiate between prefix and postfix
        //we have to write int in the formal arguments of postfix operator
        Integer i;
        i.x = x;
        x++;
        return i;
    }
    Integer operator++()
    {
        Integer i;
        i.x = ++x;
        return i;
    }
};
int main(void)
{
    Integer a;
    a.setData(3);
    //a.showData();
    Integer b,c;
    b = a++;
    c = ++a;

    a.showData();
    b.showData();
    c.showData();
    return 0;
}
