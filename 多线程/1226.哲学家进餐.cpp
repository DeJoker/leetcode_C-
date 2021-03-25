/*
 * @lc app=leetcode.cn id=1226 lang=cpp
 *
 * [1226] 哲学家进餐
 */
#include "../common/debugger.h"

// @lc code=start

// 五个叉子，五个需要保护的资源
// 五个哲学家，五个执行单位


// 限定哲学家就餐数量（信号量PV操作，最多4人申请，这样一定有一个人可以进食）
// 同时抬起左右拿叉子（有人拿餐具其他人都不能拿，一次同事拿起左右）
// 限定就餐策略（偶数先拿右，奇数先拿左）


class semaphore2 { // debugger文件有实现这里要改名
    int waits;
    int n;
    mutex m;
    condition_variable cv;

public:
    semaphore2() {}
    semaphore2(int n) {
        this->n = n;
        waits = 0;
    }

    // void Set(int n) {
    //     this->n = n;
    //     waits = 0;
    // }

    void Wait() {
        unique_lock<mutex> lk(m);
        --n;
        if (n < 0) {  // 资源量不够进入休眠
            cv.wait(lk, [&](){ return waits>0; });
            --waits; // 已被唤醒
        }
    }

    void Signal() {
        unique_lock<mutex> lk(m);
        ++n;
        if (n <= 0) { // 还有线程在睡眠？
            ++waits;
            cv.notify_one();
        }
    }
};

// 204 ms
class DiningPhilosophers {
    mutex m[5];
    semaphore2 sem;
public:
    DiningPhilosophers() : sem(4) {
        // sem.Set(4);
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        
        sem.Wait();
        int& i=philosopher;

        {
            unique_lock<mutex> llk(m[i%5]);
            pickLeftFork();
            unique_lock<mutex> rlk(m[(i+1)%5]);
            pickRightFork();
            eat();
        }
        putLeftFork();
        putRightFork();

        sem.Signal();
    }
};

// 356 ms
class DiningPhilosophersStratrhy {
    mutex m[5];
public:
    DiningPhilosophersStratrhy() {
        
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        
        int& i=philosopher;
        int left = i;
        int right = (i+1)%5;

        // 不同人不同拿取策略
        if (i%2==0) {
            m[left].lock();
            m[right].lock();
        } else {
            m[right].lock();
            m[left].lock();
        }

        pickLeftFork();
        pickRightFork();
        eat();
        
        putLeftFork();
        putRightFork();

        // 解锁
        m[left].unlock();
        m[right].unlock();
    }
};

// 156 ms
class DiningPhilosophersGlobal {
    mutex m[5];
    mutex mg;
public:
    DiningPhilosophersGlobal() {
        
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        
        int& i=philosopher;
        {
            // 吃完之前都加锁，强制只有一个人能吃
            unique_lock<mutex> gk(mg);
            unique_lock<mutex> llk(m[i%5]);
            pickLeftFork();
            unique_lock<mutex> rlk(m[(i+1)%5]);
            pickRightFork();
            eat();
        }
        
        putLeftFork();
        putRightFork();

    }
};
// @lc code=end


int main() {

}
