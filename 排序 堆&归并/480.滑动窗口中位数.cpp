/*
 * @lc app=leetcode.cn id=480 lang=cpp
 *
 * [480] 滑动窗口中位数
 */
#include "../common/debugger.h"

// @lc code=start

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ret;
        multiset<int> window(nums.begin(), nums.begin() + k); // 初始化set,将前k个数存入set
        auto mid = std::next(window.begin(), k / 2); // 基数：获取中数的位置，偶数：获取中数计数参数的后一个数的位置
        for (int idx = k; ; idx++) {
            // 1、计数每组窗口中数组的中数，并存入ret中
            auto midValue = ((double)(*mid) + (double)*next(mid, k % 2 - 1)) / 2;
            ret.push_back(midValue);
            
            // 遍历完了，退出
            if (idx == nums.size()) {
                break;
            }

            // 窗口后移
            window.insert(nums[idx]);
            if (nums[idx] < *mid)
                mid--;                  // same as mid = prev(mid)
            // Remove outgoing element
            if (nums[idx - k] <= *mid)
                mid++;                  // same as mid = next(mid)
            
            // 删除一个元素
            window.erase(window.lower_bound(nums[idx-k]));
        }
        // advance没有返回值并且用的是引用，所以一般还是next和prev是值语义
        // prev(mid, 10); 
        // advance(mid, 10);
        return ret;
    }
};
// @lc code=end


int main() {
    vector<int> p;
    vector<double> r;
    p={1,3,-1,-3,5,3,6,7};
    r = Solution().medianSlidingWindow(p, 3);
    DebugVector(r);
}
