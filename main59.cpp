#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class MaxQueue {
public:
    MaxQueue()  {
        max.push(-1);
    }
    
    int max_value() {
        return max.top();
    }
    
    void push_back(int value) {
        if (value > max.top())
            max.push(value);
        q.push(value);
    }
    
    int pop_front() {
        if (q.empty())
            return -1;
        else {
            int ret = q.front();
            q.pop();
            if (ret == max.top())
                max.pop();
            return ret;
        }
    }
    queue<int> q;
    stack<int> max;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */