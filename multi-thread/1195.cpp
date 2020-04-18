#include "concurrency.h"

class FizzBuzz {
private:
    int n, _i;
    std::condition_variable _cv3, _cv5, _cv15;
    std::mutex _m;
public:
    FizzBuzz(int n) {
        this->n = n;
        _i=0;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while(_i <= n) {
            std::unique_lock<std::mutex> lk(_m);
            _cv3.wait(lk, [&](){ return _i>n || _i%3==0; });
            if (_i>n) break;
            printFizz();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while(_i < n) {
            std::unique_lock<std::mutex> lk(_m);
            _cv5.wait(lk, [&](){ return _i>n || _i%5==0; });
            if (_i>n) break;
            printBuzz();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while(_i <= n) {
            std::unique_lock<std::mutex> lk(_m);
            // 如果_i不发生自增，那么本线程就会一直打印下去
            _cv15.wait(lk, [&](){ return _i>n || _i%15==0; });
            if (_i>n) break;
            printFizzBuzz();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        for(_i=1; _i<=n; ++_i) {
            std::unique_lock<std::mutex> lk(_m);
            if (_i%15 == 0) {
                _cv15.notify_all();
            } else if(_i%3 == 0) {
                _cv3.notify_all();
            } else if(_i%5 == 0) {
                _cv5.notify_all();
            } else {
                printNumber(_i);
            }
        }
        _cv3.notify_one();
        _cv5.notify_one();
        _cv15.notify_one();
    }
};


int main() {
    FizzBuzz b(20);
    auto p1 = [](int i){ cout << i << " "; };
    auto p2 = [](){ cout << "fizz" << " "; };
    auto p3 = [](){ cout << "buzz" << " "; };
    auto p4 = [](){ cout << "fizzbuzz" << " "; };

    // 按照当前模式先启动其实会先让线程跑完打印，后面线程while直接退出了
    // thread t4(&FizzBuzz::number, &b, p1);
    thread t1(&FizzBuzz::buzz, &b, p2);
    thread t2(&FizzBuzz::fizz, &b, p3);
    thread t3(&FizzBuzz::fizzbuzz, &b, p4);
    thread t4(&FizzBuzz::number, &b, p1);
    t1.join(); t2.join(); t3.join(); t4.join();

}