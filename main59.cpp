#include <iostream>
#include <stack>
#include <queue>
#include <map>
using namespace std;

template<typename Ty1, typename Ty2>
void DebugMap(map<Ty1, Ty2>& data)
{
    for (auto [key, value] : data)
    {
        cout << key << " : " << value << endl;
    }
}

class MaxQueue {
public:
    MaxQueue()  {
        max[-1] = 1;
    }
    
    int max_value() {
        auto iter = --max.end();
        return iter->first;
    }
    
    void push_back(int value) {
        max[value] += 1;
        q.push(value);
    }
    
    int pop_front() {
        if (q.empty())
            return -1;
        else {
            int ret = q.front();
            q.pop();
            auto iter = --max.end();
            if (ret == iter->first)
            {
                iter->second -= 1;
                if (iter->second == 0)
                {
                    max.erase(iter);
                }
            }
            return ret;
        }
    }
    queue<int> q;
    map<int, int> max;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */


int main() {
    MaxQueue sol;
    sol.push_back(1);
    sol.push_back(2);
    DebugMap(sol.max);
    cout << sol.max_value() << endl;
    sol.pop_front();
    DebugMap(sol.max);
    cout << sol.max_value() << endl;
    return 0;
}