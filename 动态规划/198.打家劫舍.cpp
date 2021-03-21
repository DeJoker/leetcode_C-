/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */
#include "../common/debugger.h"

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        map<int, int> memo;

        std::function<int(int)> dp;
        dp = [&](int s) {
            if (s<0) {
                return 0;
            }
            if (memo.find(s) != memo.end()) {
                return memo[s];
            }

            int res = max(
                    dp(s-1),  // 不抢，去下家
                    dp(s-2) + nums[s]   // 抢，去下下家
                );
            memo[s] = res;
            return res;
        };
        return dp(nums.size()-1);
    }
};
// @lc code=end

int main() {
    vector<int> p;
    p={1,2,3,1};
    LOG_DEBUG << Solution().rob(p);
    p={2,7,9,3,1};
    LOG_DEBUG << Solution().rob(p);
    p={104,209,137,52,158,67,213,86,141,110,151,127,238,147,169,138,240,185,246,225,147,203,83,83,131,227,54,78,165,180,214,151,111,161,233,147,124,143};
    LOG_DEBUG << Solution().rob(p);
}

