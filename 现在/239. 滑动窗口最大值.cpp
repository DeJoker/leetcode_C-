#include "common/debugger.h"


class MonotonicQueue {
private:
public:
    deque<int> data;

    void push(int n) {
        // 队尾添加元素，但是要把前面比新元素小的元素都删掉
        // 小的可以入，因此是递减
        while (!data.empty() && data.back() < n) 
            data.pop_back();
        data.push_back(n);
    }

    int max() { return data.front(); }

    void pop(int n) {
        // 
        if (!data.empty() && data.front() == n)
            data.pop_front();
    }
};

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    MonotonicQueue window;
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
        if (i < k - 1) { //先把窗口的前 k - 1 填满
            window.push(nums[i]);
        } else { // 窗口开始向前滑动
            DebugDeque(window.data);
            // for (auto it = window.data.begin(); it != window.data.end(); ++it) {
            //     LOG_DEBUG << *it << " ";
            // }
            // LOG_DEBUG << endl;

            window.push(nums[i]);
            res.push_back(window.max());
            window.pop(nums[i - k + 1]);
            // nums[i - k + 1] 就是窗口最后的元素
        }
    }
    return res;
}


int main()
{
    vector<int> xx{1,3,-1,-3,5,3,6,7};
    LOG_DEBUG << "fdwefwef";
    auto kk = maxSlidingWindow(xx, 3);
    DebugVector(kk);
}

