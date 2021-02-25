/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

#include "../common/debugger.h"
// @lc code=start
class Solution {
public:
    //dp[i][0] 未持有
    //dp[i][1] 持有
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<pair<int, int>> dp(n+1);
        dp[0].first = 0; dp[0].second = -prices[0];
        for(int i=1; i<=n; i++) {
            dp[i].first = max(dp[i-1].first, dp[i-1].second+prices[i-1]);
            dp[i].second = max(dp[i-1].second, -prices[i-1]);
        }
        return dp[n].first;
    }
};
// @lc code=end

int main() {
    vector<int> p;
    p = {7,1,5,3,6,4};
    LOG_DEBUG << Solution().maxProfit(p);
    p = {7,6,4,3,1};
    LOG_DEBUG << Solution().maxProfit(p);
}

