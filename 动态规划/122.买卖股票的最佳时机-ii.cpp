/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

#include "../common/debugger.h"
// @lc code=start


// 4 ms   12.7 MB
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();

        int hold(-prices[0]), unhold(0);
        for(int i=1; i<n; i++) {
            unhold = max(unhold, hold+prices[i]);
            hold = max(hold, unhold-prices[i]);
        }
        return unhold;
    }
};

class Solution33 {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = 0; dp[0][1] = -prices[0];
        for(int i=1; i<n; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]);
        }
        return dp[n-1][0];
    }
};
// @lc code=end

int main() {
    vector<int> p;
    p = {7,1,5,3,6,4};
    LOG_DEBUG << Solution().maxProfit(p); // 7
    p = {1,2,3,4,5};
    LOG_DEBUG << Solution().maxProfit(p); // 4
    p = {7,6,4,3,1};
    LOG_DEBUG << Solution().maxProfit(p); // 0
}
