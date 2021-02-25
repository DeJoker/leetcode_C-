/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */
#include "../common/debugger.h"

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        if (n<2) return 0;

        if (k*2>n) {
            vector<vector<int>> dp(n, vector<int>(2));
            dp[0][0] = 0; dp[0][1] = -prices[0];
            for(int i=1; i<n; i++) {
                dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
                dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]);
            }
            return dp[n-1][0];
        } 


        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k+1, vector<int>(2)));
        for(int i=0; i<n; i++) {
            dp[i][0][0] = 0;
            dp[i][0][1] = INT_MIN;
        }
        for(int j=1; j<k+1; ++j) {
            dp[0][j][0] = 0;
            dp[0][j][1] = -prices[0];
        }

        for(int i=1; i<n; i++) {
            for(int j=1; j<k+1; ++j) {
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]+prices[i]);
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0]-prices[i]);
            }
        }
        return dp[n-1][k][0];
    }
};
// @lc code=end

int main() {
    vector<int> p;
    // p = {};
    // LOG_DEBUG << Solution().maxProfit(p);
    // p = {5};
    // LOG_DEBUG << Solution().maxProfit(p);
    p = {2,4,1};
    LOG_DEBUG << Solution().maxProfit(2, p);
    p = {3,2,6,5,0,3};
    LOG_DEBUG << Solution().maxProfit(1, p);
    LOG_DEBUG << Solution().maxProfit(7, p);

}

