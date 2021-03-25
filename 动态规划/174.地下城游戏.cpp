/*
 * @lc app=leetcode.cn id=174 lang=cpp
 *
 * [174] 地下城游戏
 */

#include "../common/debugger.h"

// （K）最初被安置在左上角
// （P）在地下城的右下角

// 骑士的初始健康点数为一个正整数，必须保持正数
// 每经过房间会 +、-、或者0不变

// 返回能到右下角最低值

// @lc code=start

// 计算是反的。如果当前格子是负数，那我们dp要加意味着需要更多血；如果是正的我们减，不需要那么多血
// dp[i][j] =  max(min(dp[i+1][j],dp[i][j+1]) - dungeon[i][j],  1)

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size(), m=dungeon[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, INT_MAX));

        dp[n][m-1] = dp[n-1][m] = 1;
        for(int i=n-1; i>=0; --i) {
            for(int j=m-1; j>=0; --j) {
                int minHP = min(dp[i+1][j], dp[i][j+1]);
                dp[i][j] = max(minHP-dungeon[i][j], 1);
            }
        }
        return dp[0][0];
    }
};


// @lc code=end

int main() {
    vector<vector<int>> dungeon;
    dungeon = {
        {-2,3,3},
        {-5,-10,1},
        {10,30,-5},
    };
    // 样例输出值有误
    // LOG_DEBUG << Solution().calculateMinimumHP(dungeon); // 3

    dungeon = {
        {-2,3},
        {-5,-10},
    };
    LOG_DEBUG << Solution().calculateMinimumHP(dungeon); // 3
}

