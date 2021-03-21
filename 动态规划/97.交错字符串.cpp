/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 */
#include "../common/debugger.h"


// 定义f(i,j)表示s1的前i个元素和s2的前j个元素是否能交错组成s的前i+j个元素

// if (s1[i] == s3[k])
// dp[i][j] = dp[i][j] || dp[i-1][j]
// dp[i][j] = dp[i][j] || dp[i][j-1]

// @lc code=start
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size(), m=s2.size(), t=s3.size();
        if (n+m != t)
            return false;
        
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        dp[0][0] = true;

        for(int i=0; i<=n; ++i) {
            for(int j=0; j<=m; ++j) {
                int k=i+j-1;
                if (i>0) {
                    dp[i][j] = dp[i][j] || (s1[i-1]==s3[k] && dp[i-1][j]);
                }
                if (j>0) {
                    dp[i][j] = dp[i][j] || (s2[j-1]==s3[k] && dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};
// @lc code=end

// 使用滚动数组优化空间复杂度。 因为这里数组 f的第i行只和第i-1行相关，
// 所以我们可以用滚动数组优化这个动态规划，这样空间复杂度可以变成 O(m)
// 敲黑板：我们又遇到「滚动数组」优化啦！不会的同学一定要学习哟。

// 63. 不同路径 II
// 70. 爬楼梯
// 剑指 Offer 46. 把数字翻译成字符串

class SolutionOpt {
public:
    bool isInterleave(string s1, string s2, string s3) {
        auto f = vector <int> (s2.size() + 1, false);

        int n = s1.size(), m = s2.size(), t = s3.size();

        if (n + m != t) {
            return false;
        }

        f[0] = true;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                int p = i + j - 1;
                if (i > 0) {
                    f[j] &= (s1[i - 1] == s3[p]);
                }
                if (j > 0) {
                    f[j] |= (f[j - 1] && s2[j - 1] == s3[p]);
                }
            }
        }

        return f[m];
    }
};





// "a", "", "c" 会报错？？
class Solution333 {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size(), m=s2.size(), t=s3.size();
        if (n+m != t)
            return false;
        
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        for(int i=0; i<=n; ++i) {
            dp[i][0] = true;
        }
        for(int i=0; i<=m; ++i) {
            dp[0][i] = true;
        }

        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=m; ++j) {
                int k=i+j-1;
                dp[i][j] = dp[i][j] || (s1[i-1]==s3[k] && dp[i-1][j]);
                dp[i][j] = dp[i][j] || (s2[j-1]==s3[k] && dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};


int main() {
    LOG_DEBUG << Solution().isInterleave("", "", "");
    LOG_DEBUG << Solution().isInterleave("a", "", "c");
    LOG_DEBUG << Solution().isInterleave("aabcc", "dbbca", "aadbbcbcac");
    LOG_DEBUG << Solution().isInterleave("aabcc", "dbbca", "aadbbbaccc");
}
