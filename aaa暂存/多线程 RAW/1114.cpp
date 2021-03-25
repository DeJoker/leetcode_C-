#include "concurrency.h"

class Foo {
    std::mutex _m;
    std::condition_variable _cv;
    int _cur;
public:
    Foo() {
        _cur = 1;
    }

    void first(function<void()> printFirst) {
        std::unique_lock<std::mutex> lk(_m);
        _cv.wait(lk, [&]() { return _cur == 1; });
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        ++_cur;
        _cv.notify_all();
    }

    void second(function<void()> printSecond) {
        std::unique_lock<std::mutex> lk(_m);
        _cv.wait(lk, [&]() { return _cur == 2; });        
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        ++_cur;
        _cv.notify_all();
    }

    void third(function<void()> printThird) {
        std::unique_lock<std::mutex> lk(_m);
        _cv.wait(lk, [&]() { return _cur == 3; });        
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        ++_cur;
        _cv.notify_all();
    }
};

int main() {
    Foo a;
    std::thread t3(&Foo::third, &a, [](){ cout << 3 << endl; });
    std::thread t2(&Foo::second, &a, [](){ cout << 2 << endl; });
    std::thread t1(&Foo::first, &a, [](){ cout << 1 << endl; });
    t1.join();
    t2.join();
    t3.join();
}