#include "concurrency.h"


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
        _cv.wait(lk, [&](){ return _oxy && _hydrSize<2; });
        ++_hydrSize;
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        if (_hydrSize==2 && _oxy) {
            _oxy = false;
            _hydrSize = 0;
        }
        _cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        std::unique_lock<std::mutex> lk(_m);
        _cv.wait(lk, [&](){ return !_oxy; });
        _oxy = true;
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        if (_hydrSize==2 && _oxy) {
            _oxy = false;
            _hydrSize = 0;
        }

        _cv.notify_all();
    }
};


class H2O2 {
private:
    std::atomic<int> hy_count_;
    std::atomic<int> ox_count_;
public:
    H2O2() : hy_count_(0), ox_count_(0) {}

    void hydrogen(std::function<void()> releaseHydrogen) {
        int expected1 = 0;
        int expected2 = 1;

        while (!hy_count_.compare_exchange_weak(expected1, 1) &&
            !hy_count_.compare_exchange_weak(expected2, 2)) {
            expected1 = 0;
            expected2 = 1;
            std::this_thread::yield();
        }
        releaseHydrogen();

        if (hy_count_== 2 && ox_count_ == 1) {
            hy_count_ = 0;
            ox_count_ = 0;
        }
    }

    void oxygen(std::function<void()> releaseOxygen) {
        int expected = 0;
        while (!ox_count_.compare_exchange_weak(expected, 1)) {
            expected = 0;
            std::this_thread::yield();
        }
        releaseOxygen();

        if (hy_count_ == 2) {
            hy_count_ = 0;
            ox_count_ = 0;
        }
    }


};



const int now(6);
int main() {
    auto f1 = [](){ cout << "H"; };
    auto f2 = [](){ cout << "O"; };
    H2O o;
    
    auto execute = [&]() {
        thread t3(&H2O::oxygen, &o, f2);
        thread t1(&H2O::hydrogen, &o, f1);
        thread t2(&H2O::hydrogen, &o, f1);
        t1.join(); t2.join(); t3.join();
    };
    
    execute();
}