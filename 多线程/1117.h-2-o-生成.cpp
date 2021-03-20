/*
 * @lc app=leetcode.cn id=1117 lang=cpp
 *
 * [1117] H2O 生成
 */
#include "../common/debugger.h"

// @lc code=start

class H2O {
    int _oCnt;
    int _hCnt;
    mutex _m;
    condition_variable _cv;

    void Clean() {
        if (_hCnt == 2 && _oCnt==1) {
            _hCnt = 0;
            _oCnt = 0;
        }
    }
public:
    H2O() {
        _oCnt = 0;
        _hCnt = 0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lk(_m);
        _cv.wait(lk, [&](){ return _hCnt<2; });
        ++_hCnt;
        Clean();
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        _cv.notify_one();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lk(_m);
        _cv.wait(lk, [&](){ return _oCnt<1; });
        ++_oCnt;
        Clean();
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        _cv.notify_one();
    }
};



class H2OXX {
    int _odist;
    int _hcont;
    mutex _m;
    condition_variable _cv;
public:
    H2OXX() {
        _odist = 0;
        _hcont = 0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lk(_m);
        _cv.wait(lk, [&](){ return _hcont<2; });
        ++_hcont;
        ++_odist;
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        _cv.notify_one();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lk(_m);
        _cv.wait(lk, [&](){ return _odist<=4; });
        _odist = 0;
        _hcont = 0;
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        _cv.notify_one();
    }
};
// @lc code=end


int main() {

}
