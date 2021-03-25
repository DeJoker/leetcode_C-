/*
 * @lc app=leetcode.cn id=132 lang=cpp
 *
 * [132] 分割回文串 II
 */
#include "../common/debugger.h"

// 建立dp i..j状态转移，是否是回文
// dp2 0..i构成的最短回文子串
// https://leetcode-cn.com/problems/palindrome-partitioning-ii/solution/liang-ge-dong-tai-gui-hua-jie-jue-wen-ti-r6rs/

// @lc code=start
class Solution {
public:
    int minCut(string s) {
        int n=s.size();
        if (n==0) return 0;

        vector<vector<bool>> dp(n, vector<bool>(n));
        for(int len=0; len<n; len++) {
            for(int i=0; i+len<n; ++i) {
                int j=i+len;
                if (len==0) {
                    dp[i][j]=true;
                } else if (len==1)  {
                    dp[i][j] = s[i]==s[j];
                } else  {
                    dp[i][j] = dp[i+1][j-1] && s[i]==s[j];
                }
            }
        }

        // 可以被分为x个子串
        vector<int> dp2(n);
        dp2[0]=1;
        for(int i=1; i<n; i++) {
            if (dp[0][i]) {
                dp2[i] = 1;
            } else {
                int mini(INT_MAX);
                for(int j=1; j<=i; j++) {
                    if (dp[j][i]) {
                        mini = min(mini, dp2[j-1]);
                    }
                }
                dp2[i] = mini+1;
            }
        }

        return dp2[n-1]-1;
    }
};



// @lc code=end

int main() {
    LOG_DEBUG << Solution().minCut("aab");
    LOG_DEBUG << Solution().minCut("a");
    LOG_DEBUG << Solution().minCut("ab");
    return 0;
}

