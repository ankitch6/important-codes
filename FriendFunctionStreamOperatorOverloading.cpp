#include<iostream>
using namespace std;

class Complex
{
private:
    int a,b;
public:
    void setData(int x,int y)
    {
        a=x;b=y;
    }
    void showData(){
    cout<<"a="<<a<<"  b="<<b<<endl;
    }
    friend istream& operator>>(istream&, Complex&);
    friend ostream& operator<<(ostream&, Complex);
};
istream& operator>>(istream& din, Complex &c)
{
    cin>>c.a>>c.b;
    return din;
}
ostream& operator<<(ostream& dout, Complex c)
{
    cout<<c.a<<" "<<c.b;
    return dout;
}
int main(void)
{
    Complex c;
    cout<<"Enter the complex number";
    cin>>c;
    cout<<"\nPrinting complex number:";
    cout<<c;
    return 0;
}
