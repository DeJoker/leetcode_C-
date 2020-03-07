#include <iostream>
#include <stack>
#include <queue>
#include <map>
using namespace std;

template<typename Ty1, typename Ty2>
void DebugMap(map<Ty1, Ty2>& mm)
{
    cout << "Debug Map ";
    for (auto data : mm)
    {
        cout << data.first << " : " << data.second << endl;
    }
    cout << "Debug end ---- " << endl;
}

template<typename Frist, typename Second>
void DebugPair(pair<Frist, Second>& data)
{
    cout << "Debug Pair ";
    cout << data.first << " : " << data.second << endl;
}


// 46 remove 0
// 868 remove 0
// 525 remove 0
// 871 remove 0
// 837 remove 0
// 866 ::::::: 1
// 866 remove 0
// 850 remove 0


class MaxQueue {
public:
    MaxQueue()  {
        max[-1] = 1;
    }
    
    int max_value() {
        auto iter = max.rbegin();
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
            auto iter = max.rbegin();
            DebugPair(*iter);
            cout << ret << " ::::::: " << iter->first << endl;
            if (ret == iter->first)
            {
                iter->second -= 1;
                if (iter->second == 0)
                {
                    max.erase(ret);
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
    sol.push_back(11);
    sol.push_back(4);
    // DebugMap(sol.max);
    sol.pop_front();
    // sol.pop_front();
    // DebugMap(sol.max);
    cout << sol.max_value() << endl;
    return 0;
}