#include<iostream>
using namespace std;

#include "common/debugger.h"


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

class C {
public:
    C(int k) {}
    bool operator<(const C& n) const {
        return false;
    }

    bool fwerf() {
        return true;
    }
};


// 这样定义一个A的对象，会输出什么？
int main()
{
    A a;
    C b(2);
    C ll = b;

    map<int, C> kk;

    set<C> pp;
    pp.insert(ll);
    pp

    // kk[2] = ll;
    // ll.fwerf();
    // kk[2].fwerf();

}


