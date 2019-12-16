/*Overloading of Operator as a Friend Function*/
#include<iostream>
using namespace std;

class Complex
{
private:
    int a,b;
public:
    void setData(int x, int y)
    {
        a=x;b=y;
    }
    void showData()
    {
        cout<<a<<"  "<< b<<endl;
    }
    friend Complex operator+(Complex, Complex);
};
Complex operator+(Complex one, Complex two)
{
    Complex temp;
    temp.a = one.a + two.a;
    temp.b = one.b + two.b;
    return temp;
}

int main(void)
{
    Complex c1, c2, c3;
    c1.setData(2,5);
    c2.setData(3,4);
    c3 = c1 + c2;
    //c3 = operator+(c1,c2);
    c3.showData();
    return 0;
}


