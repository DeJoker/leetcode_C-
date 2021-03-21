/*
 * @lc app=leetcode.cn id=174 lang=cpp
 *
 * [174] 地下城游戏
 */

#include "../common/debugger.h"

// @lc code=start
class Solution {
public:
    // dp[i][j] =  max(min(dp[i+1][j],do[i][j+1]) - dungeon[i][j],  1)
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size(), m=dungeon[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, INT_MAX));

        dp[n][m-1] = dp[n-1][m] = 1;
        for(int i=n-1; i>=0; --i) {
            for(int j=m-1; j>=0; --j) {
                dp[i][j] = max(min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j], 1);
            }
        }
        return dp[0][0];
    }
};
// @lc code=end

