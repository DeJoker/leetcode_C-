
#include <iostream>
#include <memory>
using namespace std;
 
class B;
class A
{
public:
    A(){cout<<"A()"<<endl;}
    ~A(){cout<<"~A()"<<endl;}
    weak_ptr<B> _ptrb; //其他地方持有对象的弱智能指针
};



class B
{
public:
    B(){cout<<"B()"<<endl;}
    ~B(){cout<<"~B()"<<endl;}
    weak_ptr<A> _ptra; //其他地方持有对象的弱智能指针
};



int main(int argc, char* argv[])
{
    shared_ptr<A> ptra(new A()); //创建对象时持有强智能指针
    shared_ptr<B> ptrb(new B()); //创建对象时持有强智能指针

    ptra->_ptrb = ptrb;
    ptrb->_ptra = ptra;

    return 0;
}
