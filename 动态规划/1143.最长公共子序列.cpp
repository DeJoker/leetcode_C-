/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */
#include "../common/debugger.h"

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(), m=text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if (text1[i-1] == text2[j-1]) { // 这里是i-1
                    dp[i][j] = dp[i-1][j-1]+1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[n][m];
    }
};
// @lc code=end

int main() {
    // LOG_DEBUG << Solution().longestCommonSubsequence("abcde", "ace" );
    // LOG_DEBUG << Solution().longestCommonSubsequence("abc", "abc" );
    LOG_DEBUG << Solution().longestCommonSubsequence("abc", "def" );
}

