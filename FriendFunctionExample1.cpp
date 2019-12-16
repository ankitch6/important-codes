#include<iostream>
using namespace std;

class B;

class A
{
private:
    int a;
public:
    void setData(int x){a=x;}
    friend void sum(A,B);
};
class B
{
private:
    int b;
public:
    void setData(int x){b=x;}
    friend void sum(A,B);
};
void sum(A obj1, B obj2)
{
    cout<<"sum is="<<obj1.a + obj2.b<<endl;
}
int main(void)
{
    A o1;
    o1.setData(44);
    B o2;
    o2.setData(55);
    sum(o1, o2);
    return 0;
}
