/*
 * @lc app=leetcode.cn id=87 lang=cpp
 *
 * [87] 扰乱字符串
 */
#include "../common/debugger.h"

// @lc code=start
class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n=s1.size(), m=s2.size();
        if (n!=m) return false;
        if (n==0) return true;

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(n+1)));
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                dp[i][j][1] = s1[i]==s2[j];
        

        for(int len=2; len<=n; ++len)
            for(int i=0; i<=n-len; i++)
                for(int j=0; j<=n-len; ++j)
                    for(int k=1; k<=len-1; ++k) {
                        if (dp[i][j][k] && dp[i+k][j+k][len-k]) {
                            dp[i][j][len] = true;
                            break;
                        }

                        if (dp[i][j+len-k][k] && dp[i+k][j][len-k]) {
                            dp[i][j][len] = true;
                            break;
                        }
                    }
        
        return dp[0][0][n];
    }
};
// @lc code=end

int main() {
    LOG_DEBUG << Solution().isScramble("great", "rgeat"); // true
    LOG_DEBUG << Solution().isScramble("abcde", "caebd"); // false
    LOG_DEBUG << Solution().isScramble("", "");
}
