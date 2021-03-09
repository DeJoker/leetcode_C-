/*
 * @lc app=leetcode.cn id=877 lang=cpp
 *
 * [877] 石子游戏
 */
#include "../common/debugger.h"

// dp[i][j].fir = max(选择最左边的石头堆     ,     选择最右边的石头堆)
// dp[i][j].fir = max(piles[i] + dp[i+1][j].sec, piles[j] + dp[i][j-1].sec)

// if 先手选择左边:
//     dp[i][j].sec = dp[i+1][j].fir
// elif 先手选择右边:
//     dp[i][j].sec = dp[i][j-1].fir


// BaseCase
// dp[i][j].fir = piles[i]
// dp[i][j].sec = 0
// 其中 0 <= i == j < n

// @lc code=start
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n));
        for(int i=0; i<n; i++) {
            dp[i][i].first = piles[i];
            dp[i][i].second = 0;
        }

        // 记得是闭区间，2是开始，n是最终的总长
        for(int len=2; len<=n; ++len) {
            for (int i=0; i<=n-len; i++) {
                int j=i+len-1;
                int lPick = piles[i] + dp[i+1][j].second;
                int rPick = piles[j] + dp[i][j-1].second;

                if (lPick > rPick) {
                    dp[i][j].first = lPick;
                    dp[i][j].second = dp[i+1][j].first;
                } else {
                    dp[i][j].first = rPick;
                    dp[i][j].second = dp[i][j-1].first;
                }
            }
        }

        return dp[0][n-1].first > dp[0][n-1].second;
    }
};
// @lc code=end


int main() {
    vector<int> p;
    p = {5,3,4,5};
    LOG_DEBUG << (Solution().stoneGame(p) ? "true" : "false" );
    p = {3, 9, 1, 2};
    LOG_DEBUG << (Solution().stoneGame(p) ? "true" : "false" );
}
