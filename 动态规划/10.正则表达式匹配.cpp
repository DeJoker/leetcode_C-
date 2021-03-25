/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */
#include "../common/debugger.h"

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        auto match = [&](int i, int j) {
            if (i==-1 || p[j]=='.')
                return true;
            return s[i]==p[j];
        };

        int n=s.size(), m=p.size();
        vector<vector<bool>> dp(n+1, vector<int>(m+1));
        dp[0][0] = true;
        for(int i=0; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if (p[j-1]=='*') {
                    dp[i][j] |= dp[i][j-2];
                    if (match(i-1, j-2)) {
                        dp[i][j] |= dp[i-1][j];
                    }
                } else if (match(i-1, j-1)) {
                    dp[i][j] |= dp[i-1][j-1];
                }
            }
        }
        return dp[n][m];
    }
};
// @lc code=end

int main() {
    
}

