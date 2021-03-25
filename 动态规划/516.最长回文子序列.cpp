/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */
#include "../common/debugger.h"


// 既然是子序列，并且最长，那么必然是越往后越长（会传到至少不低于当前值）


// @lc code=start
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>> dp(n, vector<int>(n));

        for(int len=0; len<n; ++len) {
            for(int i=0; i+len<n; i++) {
                if (len==0) {
                    dp[i][i] = 1;
                } else {
                    int j=i+len;
                    if (s[i]==s[j]) {
                        // if (len==1) {
                        //     dp[i][j] = 2;
                        // } else {
                        //     dp[i][j] += 2;
                        // }
                        dp[i][j] = dp[i+1][j-1]+2;
                    } else {
                        dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                    }
                }
            }
        }

        return dp[0][n-1];
    }
};
// @lc code=end


int main() {
    LOG_DEBUG << Solution().longestPalindromeSubseq("babbb");
}
