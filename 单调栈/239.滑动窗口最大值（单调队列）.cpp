/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */
#include "../common/debugger.h"

// @lc code=start

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int> window;
        
        vector<int> res;
        for(int i=0; i<n; i++) {
            if (i<k-1) {
                while(!window.empty() && window.back() < nums[i])
                    window.pop_back();
                window.push_back(nums[i]);
            } else {
                // DebugDeque(window);

                while(!window.empty() && window.back() < nums[i])
                    window.pop_back();
                window.push_back(nums[i]);

                res.push_back(window.front());

                // 这里怎么会nums.front() == nums[i-k+1] 运行与代码完全不一致呢
                // 在这里应该是window.front() 。。。。
                if (!window.empty() && window.front() == nums[i-k+1]) {
                    window.pop_front();
                }
            }
        }

        return res;
    }
};

class SolutionXX {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left(0), right(0);
        deque<int> window;
        
        vector<int> res;
        while(right < nums.size()) {
            while (!window.empty() && window.back() > nums[right])
                window.pop_back();
            window.push_back(nums[right]);
            ++right;

            while (right-left >= k) {
                if (right >= k) {
                    res.push_back(window.front());
                }
                if (!window.empty() && window.front() == nums[left]) {
                    window.pop_front();
                }
                ++left;
            }
        }
        return res;
    }
};
// @lc code=end

int main() {
    vector<int> p, r;

    p={1,3,-1,-3,5,3,6,7};
    // r = Solution().maxSlidingWindow(p, 3);
    DebugVector(r);
    p={1,};
    // r = Solution().maxSlidingWindow(p, 1);
    DebugVector(r);


    p={1,3,1,2,0,5};
    r = Solution().maxSlidingWindow(p, 3); // [3,3,2,5]
    DebugVector(r);
}

// 同样解法

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

            window.push(nums[i]);
            res.push_back(window.max());
            window.pop(nums[i - k + 1]);
            // nums[i - k + 1] 就是窗口最后的元素
        }
    }
    return res;
}

