/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */
#include "../common/debugger.h"

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, n+1), nums;
        for(int i=1; i*i<=n; i++) {
            dp[i*i] = 1;
            nums.push_back(i*i);
        }
        dp[0] = 0; // 为什么要带这个情况

        for(int i=2; i<=n; i++) {
            int res=n+1;
            for(int j=0; j<nums.size(); j++) {
                if (nums[j] > i) break;
                res = min(res, dp[i-nums[j]]+1);
            }
            dp[i] = res;
        }

        return dp[n];
    }
};
// @lc code=end

int main() {
    LOG_DEBUG << Solution().numSquares(12);
    LOG_DEBUG << Solution().numSquares(15);
}
