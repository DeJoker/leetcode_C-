/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */
#include "../common/debugger.h"

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if (n<2) {
            return 0;
        }

        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = 0; dp[0][1] = -prices[0];

        dp[1][0] = max(dp[0][0], dp[0][1]+prices[1]);
        dp[1][1] = max(dp[0][1], dp[0][0]-prices[1]);

        for(int i=2; i<n; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-2][0]-prices[i]);
        }
        return dp[n-1][0];
    }
};
// @lc code=end


int main() {
    vector<int> p;
    // p = {7,1,5,3,6,4};
    // LOG_DEBUG << Solution().maxProfit(p);
    // p = {1,2,3,0,2};
    // LOG_DEBUG << Solution().maxProfit(p);
    // p = {};
    // LOG_DEBUG << Solution().maxProfit(p);
    // p = {5};
    // LOG_DEBUG << Solution().maxProfit(p);
    p = {1,4,2,7};
    LOG_DEBUG << Solution().maxProfit(p);

}
