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
            _cv3.wait(lk, [&](){ return _i%3==0; });
            printFizz();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while(_i < n) {
            std::unique_lock<std::mutex> lk(_m);
            _cv5.wait(lk, [&](){ return _i%5==0; });
            printBuzz();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while(_i <= n) {
            std::unique_lock<std::mutex> lk(_m);
            _cv15.wait(lk, [&](){ return _i%15==0; });
            printFizzBuzz();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        for(_i=1; _i<=n; ++_i) {
            std::unique_lock<std::mutex> lk(_m);
            if (_i%15 == 0) {
                _cv15.notify_one();
            } else if(_i%3 == 0) {
                _cv3.notify_one();
            } else if(_i%5 == 0) {
                _cv5.notify_one();
            } else {
                printNumber(_i);
            }
        }
        // _cv3.notify_one();
        // _cv5.notify_one();
        // _cv15.notify_one();
    }
};


int main() {
    FizzBuzz b(20);
    auto p1 = [](int i){ cout << i << " "; };
    auto p2 = [](){ cout << "fizz" << " "; };
    auto p3 = [](){ cout << "buzz" << " "; };
    auto p4 = [](){ cout << "fizzbuzz" << " "; };

    thread t4(&FizzBuzz::number, &b, p1);
    thread t1(&FizzBuzz::buzz, &b, p2);
    thread t2(&FizzBuzz::fizz, &b, p3);
    thread t3(&FizzBuzz::fizzbuzz, &b, p4);
    t1.join(); t2.join(); t3.join(); t4.join();

}