
#include "concurrency.h"

// 010203040506070809010011012
class ZeroEvenOdd2 {
private:
    int n;
    std::condition_variable g_cv;
    std::mutex mt;
    bool ze,other;
public:
    ZeroEvenOdd2(int n) : g_cv(), mt(), ze(false), other(true) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(std::function<void(int)> printNumber) {
        for(int i = 1; i <= n; ++i){
            std::unique_lock<std::mutex> lk(mt);
            g_cv.wait(lk, [=](){return !ze && other;});
            printNumber(0);
            if(i&1)ze = true;
            else other = false;
            g_cv.notify_all();
        }
    }

    void even(std::function<void(int)> printNumber) {
        for(int i = 2; i <= n; i+=2){
            std::unique_lock<std::mutex> lk(mt);
            g_cv.wait(lk,[=](){return !ze && !other;});
            printNumber(i);
            ze = false;
            other = true;
            g_cv.notify_all();
        }
    }

    void odd(std::function<void(int)> printNumber) {
        for(int i = 1; i <= n; i+=2){
            std::unique_lock<std::mutex> lk(mt);
            g_cv.wait(lk, [=](){return ze && other;});
            printNumber(i);
            ze = false;
            g_cv.notify_all();
        }
    }
};


class ZeroEvenOdd {
private:
    int _n;
    std::condition_variable _cv;
    std::mutex _m;
    bool _zero, _odd;
public:
    ZeroEvenOdd(int n) {
        this->_n = n;
        _zero = true;
        _odd = true;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(std::function<void(int)> printNumber) {
        // 必须要for循环
        for(int i = 0; i < _n; ++i){
            std::unique_lock<std::mutex> lk(_m);
            _cv.wait(lk, [&](){ return _zero; });
            printNumber(0);
            _zero = false;
            _cv.notify_all();
        }
    }

    void even(std::function<void(int)> printNumber) {
        for(int i = 2; i <= _n; i+=2){
            std::unique_lock<std::mutex> lk(_m);
            _cv.wait(lk, [&](){ return !_zero && !_odd; });
            printNumber(i);
            _zero = true;
            _odd = true;
            _cv.notify_all();
        }
    }

    void odd(std::function<void(int)> printNumber) {
        for(int i = 1; i <= _n; i+=2){
            std::unique_lock<std::mutex> lk(_m);
            _cv.wait(lk, [&](){ return !_zero && _odd; });
            printNumber(i);
            _zero = true;
            _odd = false;
            _cv.notify_all();
        }
    }
};



class H2O {
    int _hydrSize;
    bool _oxy;
    std::mutex _m;
    std::condition_variable _cv;
public:
    H2O() {
        _hydrSize = 0;
        _oxy = false;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        std::unique_lock<std::mutex> lk(_m);
        ++_hydrSize;
        _cv.wait(lk, [&](){ return _oxy && _hydrSize==2; });
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        _oxy = false;
        _hydrSize = 0;
        _cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        std::unique_lock<std::mutex> lk(_m);
        _oxy = true;
        _cv.wait(lk, [&](){ return _oxy && _hydrSize==2; });
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        _oxy = false;
        _hydrSize = 0;
        _cv.notify_all();
    }
};

// 010203040506070809010011012
int main() {
    auto print = [](int i) { std::cout << i; };
    ZeroEvenOdd situation(12);

    // std::function<void(int)> aa = print;
    // 原型 thread(_Callable&& __f, _Args&&... __args)
    std::thread t1(&ZeroEvenOdd::even, &situation, print);
    std::thread t2(&ZeroEvenOdd::odd, &situation, print);
    std::thread t3(&ZeroEvenOdd::zero, &situation, print);
    t1.join();
    t2.join();
    t3.join();
    return 0;
}
