/*
 * @lc app=leetcode.cn id=1116 lang=cpp
 *
 * [1116] 打印零与奇偶数
 */
#include "../common/debugger.h"

// @lc code=start
class ZeroEvenOdd {
private:
    int n;
    mutex _m;
    condition_variable _cv1, _cv2;
    bool _zero;
    bool _odd;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        _odd = true;
        _zero = true;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i=1; i<=n; i++) {
            unique_lock<mutex> lk(_m);
            _cv1.wait(lk, [&](){ return _zero; });

            printNumber(0);
            _zero = false;
            _cv2.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i=2; i<=n; i+=2) {
            unique_lock<mutex> lk(_m);
            _cv2.wait(lk, [&](){ return !_odd; });

            printNumber(i);
            _odd = true;
            _zero = true;
            _cv1.notify_one();
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i=1; i<=n; i+=2) {
            unique_lock<mutex> lk(_m);
            _cv2.wait(lk, [&](){ return _odd; });

            printNumber(i);
            _odd = false;
            _zero = true;
            _cv1.notify_one();
        }
    }
};

// 没有保护_cur。
// 一开始还没加退出条件，也没写循环
class ZeroEvenOdd222 {
private:
    int n;
    mutex _m;
    condition_variable _cv1, _cv2;
    bool _zero;
    int _cur;
public:
    ZeroEvenOdd222(int n) {
        this->n = n;
        _cur = 1;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while(_cur<=n) {
            unique_lock<mutex> lk(_m);
            _cv1.wait(lk, [&](){ return _zero; });

            printNumber(0);
            _zero = false;
            _cv2.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        while(_cur<=n) {
            unique_lock<mutex> lk(_m);
            _cv2.wait(lk, [&](){ return _cur%2==0; });

            printNumber(_cur);
            ++_cur;
            _zero = true;
            _cv1.notify_one();
        }
    }

    void odd(function<void(int)> printNumber) {
        while(_cur<=n) {
            unique_lock<mutex> lk(_m);
            _cv2.wait(lk, [&](){ return _cur%2==1; });

            printNumber(_cur);
            ++_cur;
            _zero = true;
            _cv1.notify_one();
        }
    }
};
// @lc code=end

int main() {
    function<void(int)> p=[](int i) {cout << i;};

    ZeroEvenOdd zeo(5);
    thread t1(std::bind(&ZeroEvenOdd::zero, &zeo, p));
    thread t2(std::bind(&ZeroEvenOdd::odd, &zeo, p));
    thread t3(std::bind(&ZeroEvenOdd::even, &zeo, p));
    t2.join(); t1.join(); t3.join();

    cout << endl;
}

