#include<iostream>
using namespace std;

class Complex
{
private:
    int a, b;
public:
    void setData(int x, int y)
    {
        a=x;
        b=y;
    }
    void showData()
    {
        cout<<"a="<<a<<" & b="<<b<<endl;
    }
    Complex operator+(Complex c)
    {
        Complex temp;
        temp.a = a+c.a;
        temp.b = b+c.b;
        return temp;
    }
    Complex operator-()
    {
        Complex temp;
        temp.a = -a;
        temp.b = -b;
        return temp;
    }
};

int main(void)
{
    Complex c1,c2,c3;
    c1.setData(4,5);
    c2.setData(5,4);
    c3 = c1 + c2;
    c3.showData();
    c3 = -c1;
    c3.showData();
    return 0;
}
