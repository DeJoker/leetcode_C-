/*
 * @lc app=leetcode.cn id=1114 lang=cpp
 *
 * [1114] 按序打印
 */
#include "../common/debugger.h"

// @lc code=start

// 如果只想控制执行顺序那么一个互斥量和变量即可；加一个普通变量告知当前步骤该谁执行

// 条件变量参数是：互斥锁（不是互斥量）、谓词函数

// thread需要可调对象  【成员函数地址、this指针、参数】才能构成合法可调对象
// 前两者都需要是指针（普通函数是可调对象、但成员变量需要取地址）

class Foo {
    int _pos = 1;
    mutex _m;
    condition_variable _cv;
public:
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        std::unique_lock<mutex> lLock(_m);
        _cv.wait(lLock, [&](){ return _pos==1; });
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        ++_pos;
        _cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lLock(_m);
        _cv.wait(lLock, [&](){ return _pos==2; });
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        ++_pos;
        _cv.notify_one();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lLock(_m);
        _cv.wait(lLock, [&](){ return _pos==3; });
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};
// @lc code=end

int main() {
    function<void()> a=[]() { cout << "first"; };
    function<void()> b=[]() { cout << "second"; };
    function<void()> c=[]() { cout << "third"; };

    Foo f;
    std::thread t1(std::bind(&Foo::first, &f, a));
    std::thread t2(std::bind(&Foo::second, &f, b));
    std::thread t3(std::bind(&Foo::third, &f, c));

    t1.join(); t2.join(); t3.join();
    cout << endl; // 记得cout最后要\n才会刷新缓冲区
}

