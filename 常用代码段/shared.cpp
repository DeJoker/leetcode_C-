#include <memory>
#include <iostream>
using namespace std;

class A
{
public:
    int a;
};

class B : public A
{
public:
    int b;
};

void change(shared_ptr<A>& p, int g)
{
    B b;
    b.a = 2; b.b =3;
    A a;
    a.a = 1;
    if (g == 1)
        p = make_shared<A>(a);
    else
        p = make_shared<A>(b);
}

int main()
{
    shared_ptr<A> nn;
    change(nn, 2);
    cout << sizeof(nn) << endl;
    change(nn, 1);
    cout << sizeof(nn) << endl;
}
