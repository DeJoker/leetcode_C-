#include<iostream>
using namespace std;

class Base
{
public:
    Base()
    {
       Fuction();
    }

    virtual void Fuction()
    {
        cout << "Base::Fuction" << endl;
    }
};

class A : public Base
{
public:
    A()
    {
      Fuction();
    }

    virtual void Fuction()
    {
        cout << "A::Fuction" << endl;
    }
};

// 这样定义一个A的对象，会输出什么？
int main()
{
    A a;
}


