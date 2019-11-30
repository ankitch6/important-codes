#include<iostream>
using namespace std;

namespace MySpace
{
    int a;
    int func();
    class A
    {
    public:
        void fun();
    };
}
using namespace MySpace;

//definition needs scope resolution operator
int MySpace:: func()
{
    cout<< "Hello from function"<<endl;
}
void MySpace::A::fun()
{
    cout<<"Hello World"<<endl;
}

int main(void)
{
    a = 5;
    func();
    A obj;
    obj.fun();
    return 0;
}
