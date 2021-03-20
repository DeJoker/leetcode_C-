/*
 * @lc app=leetcode.cn id=1195 lang=cpp
 *
 * [1195] 交替打印字符串
 */
#include "../common/debugger.h"

// @lc code=start

// 究竟是一个条件变量唤醒所有，引起群惊  64 ms
// 还是多个多个条件变量唤醒对应线程好呢
// 但是后者，明显就把唤醒固定线程的任务量交给了当前执行线程


class FizzBuzzOneCV {
private:
    int n;
    int _cur;
    mutex _m;
    condition_variable _cv;

public:
    FizzBuzzOneCV(int n) {
        this->n = n;
        _cur = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (true) {
            unique_lock<mutex> lk(_m);
            _cv.wait(lk, [&](){ return (_cur>n) || (_cur%3==0&&_cur%5!=0); });
            if (_cur > n) break;
            printFizz();
            ++_cur;
            _cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (true) {
            unique_lock<mutex> lk(_m);
            _cv.wait(lk, [&](){ return (_cur>n) || (_cur%3!=0&&_cur%5==0); });
            if (_cur > n) break;
            printBuzz();
            ++_cur;
            _cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while (true) {
            unique_lock<mutex> lk(_m);
            _cv.wait(lk, [&](){ return (_cur>n) || (_cur%15==0); });
            if (_cur > n) break;
            printFizzBuzz();
            ++_cur;
            _cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (true) {
            unique_lock<mutex> lk(_m);
            _cv.wait(lk, [&](){ return (_cur>n) || (_cur%3!=0&&_cur%5!=0); });
            if (_cur > n) break;
            printNumber(_cur);
            ++_cur;
            _cv.notify_all();
        }
    }
};



// 互斥锁+原子变量 解法，没有必要使用条件变量唤醒
// 这里必须要加锁，因为print函数是每个线程执行，他需要保护
// 1620 ms  果然只加锁速度更慢了。。。。
class FizzBuzz {
private:
	int n;
	atomic<int> i;//x效率提高了一点点
	mutex m;
public:
	FizzBuzz(int n) {
		this->n = n;
		this->i = 1;
	}

	// printFizz() outputs "fizz".
	void fizz(function<void()> printFizz) {
		while (i <= n)
		{
			std::lock_guard<std::mutex> lk(m);
			if (i % 3 == 0 && i % 15 != 0 && i <= n) {
				printFizz();
				i++;
			}
		}
	}

	// printBuzz() outputs "buzz".
	void buzz(function<void()> printBuzz) {
		while (i <= n)
		{
			std::lock_guard<std::mutex> lk(m);
			if (i % 5 == 0 && i % 15 != 0 && i <= n) {
				printBuzz();
				i++;
			}
		}
	}

	// printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
		while (i <= n)
		{
			std::lock_guard<std::mutex> lk(m);
			if (i % 15 == 0 && i <= n) { //i<=n 不能省略
				printFizzBuzz();
				i++;
			}
		}
	}

	// printNumber(x) outputs "x", where x is an integer.
	void number(function<void(int)> printNumber) {
		while (i <= n)
		{
			std::lock_guard<std::mutex> lk(m);
			if (i % 3 != 0 && i % 5 != 0&&i<=n) {
				printNumber(i);
				i++;
			}
		}
	}
};




// 错误 这个与奇偶输出最大的不同在于
// for的退出条件，最后一次循环进入但是因为没有到下一个输出位导致没有办法退出
class FizzBuzzWrong {
private:
    int n;
    int _cur;
    mutex _m;
    condition_variable _cv;

public:
    FizzBuzzWrong(int n) {
        this->n = n;
        _cur = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        for(int i=1; i<=n/3; i++) {
            unique_lock<mutex> lk(_m);
            _cv.wait(lk, [&](){ return _cur%3==0&&_cur%5!=0; });
            ++_cur;
            printFizz();
            _cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        for(int i=1; i<=n/5; i++) {
            unique_lock<mutex> lk(_m);
            _cv.wait(lk, [&](){ return _cur%3!=0&&_cur%5==0; });
            ++_cur;
            printBuzz();
            _cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        for(int i=1; i<=n/15; i++) {
            unique_lock<mutex> lk(_m);
            _cv.wait(lk, [&](){ return _cur%15==0; });
            ++_cur;
            printFizzBuzz();
            _cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (true) {
            unique_lock<mutex> lk(_m);
            _cv.wait(lk, [&](){ return _cur%3!=0&&_cur%5!=0; });
            printNumber(_cur);
            ++_cur;
            if (_cur > n) break;
            _cv.notify_all();
        }
    }
};
// @lc code=end


int main() {

    // for(int i=1; i<=15/15; i++) {
    //     LOG_DEBUG << "nima";
    // }
    // return 0;

    FizzBuzzWrong fz(15);

    function<void()> pf = [](){ cout << "fizz" << endl; };
    function<void()> pb = [](){ cout << "buzz" << endl; };
    function<void()> pfb = [](){ cout << "fizzbuzz" << endl; };
    function<void(int)> pn = [](int i){ cout << i << endl; };

    thread t1(bind(&FizzBuzzWrong::fizz, &fz, pf));
    thread t2(bind(&FizzBuzzWrong::buzz, &fz, pb));
    thread t3(bind(&FizzBuzzWrong::fizzbuzz, &fz, pfb));
    thread t4(bind(&FizzBuzzWrong::number, &fz, pn));

    t1.join(); t2.join(); t3.join(); t4.join();

    cout << endl;
}
