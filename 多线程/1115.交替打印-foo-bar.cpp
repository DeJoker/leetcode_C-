/*
 * @lc app=leetcode.cn id=1115 lang=cpp
 *
 * [1115] 交替打印FooBar
 */

#include "../common/debugger.h"

// @lc code=start
class FooBar {
private:
    int n;
    mutex _m;
    condition_variable _cv;
    bool _pos;
public:
    FooBar(int n) {
        this->n = n;
        _pos = false;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lk(_m);
            _cv.wait(lk, [&](){ return !_pos; });
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            _pos = true;
            _cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lk(_m);
            _cv.wait(lk, [&](){ return _pos; });
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            _pos = false;
            _cv.notify_one();
        }
    }
};
// @lc code=end

int main() {
    FooBar f(3);
    function<void()> a =[](){ cout << "foo"; };
    function<void()> b =[](){ cout << "bar"; };

    thread t1(std::bind(&FooBar::foo, &f, a));
    thread t2(std::bind(&FooBar::bar, &f, b));

    t2.join(); t1.join();
    cout << endl;
}

