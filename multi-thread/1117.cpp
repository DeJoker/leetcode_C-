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




const int now(6);
int main() {
    auto f1 = [](){ cout << "H"; };
    auto f2 = [](){ cout << "O"; };
    H2O o;
    thread t1(&H2O::hydrogen, &o, f1);
    thread t2(&H2O::hydrogen, &o, f1);
    thread t3(&H2O::hydrogen, &o, f1);
    thread t4(&H2O::hydrogen, &o, f1);
    thread t5(&H2O::hydrogen, &o, f2);
    thread t6(&H2O::hydrogen, &o, f2);

    std::this_thread::sleep_for(std::chrono::microseconds(1000));
    
}