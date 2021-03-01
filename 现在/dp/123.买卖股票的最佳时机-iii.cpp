/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */
#include "../common/debugger.h"

// dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j-1][1]+prices[i])
// dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j][0]-prices[i])

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if (n<2) {
            return 0;
        }

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(2)));
        for(int i=0; i<n; ++i) {
            dp[i][0][0] = 0;
            dp[i][0][1] = INT_MIN;
        }
        for(int j=0; j<=2; ++j) {
            dp[0][j][0] = 0;
            dp[0][j][1] = -prices[0];
        }

        for(int i=1; i<n; ++i) {
            for (int j=1; j<=2; ++j) {
                // 应该在买的时候就限制j-1超过固定次数不能买；一旦允许买将结果带到后续计算中
                // dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j-1][1]+prices[i]);
                // dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j][0]-prices[i]);
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]+prices[i]);
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0]-prices[i]);
            }
        }
        // return max(dp[n-1][1][0], dp[n-1][2][0]);
        return dp[n-1][2][0];
    }
};
// @lc code=end


int main() {
    vector<int> p;
    p = {3,3,5,0,0,3,1,4};
    // LOG_DEBUG << Solution().maxProfit(p);
    p = {3,3,5,0,0,3,1,4};
    LOG_DEBUG << Solution().maxProfit(p);
}
