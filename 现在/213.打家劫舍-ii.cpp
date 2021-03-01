/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */
#include "../common/debugger.h"


// 首尾房间不能同时被抢，那么只可能有三种不同情况：1、要么都不被抢；
// 2、要么第一间房子被抢最后一间不抢 3、要么最后一间房子被抢第一间不抢
// 但是实际后只考虑两种情况，因为第一种情况一定没有后两者大

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n==1) return nums[0];

        std::function<int(int, int)> dp;
        dp = [&](int s, int e) {
            int dpi1=0, dpi2=0;
            int dpi=0;
            for(int i=e; i>= s; i--) {
                dpi = max(dpi1, nums[i]+dpi2);
                dpi2 = dpi1;
                dpi1 = dpi;
            }
            return dpi;
        };

        return max(dp(0, n-2), dp(1, n-1));

    }
};
// @lc code=end

int main() {
    vector<int> p;
    p = {2,3,2}; // 3
    LOG_DEBUG << Solution().rob(p);
}

