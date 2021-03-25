#ifndef __CONCURRENCY_H_
#define __CONCURRENCY_H_

#include <mutex>
#include <condition_variable>
#include <memory>
#include <thread>

#include <atomic>

#include <functional>
#include <iostream>

using namespace std;


class Semaphore {
private:
    std::mutex _m;
    std::condition_variable _cv;
    int count_;
public:
    Semaphore(int count = 0) : count_(count)
    {}

    
    void Signal() {
        std::unique_lock<std::mutex> lock(_m);
        ++count_;
        _cv.notify_one();
    }

    void Wait() {
        std::unique_lock<std::mutex> lock(_m);
        while(count_ <= 0){
            _cv.wait(lock);
        }
        --count_;
    }
};


#endif
