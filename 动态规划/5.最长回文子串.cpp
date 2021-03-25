/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
#include "../common/debugger.h"

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>> dp(n, vector<int>(n));

        string res;
        // 长度0到n-1 
        // len==0相当于初始化
        // len==1是base case
        // len+1是真字符长度

        // 为什么dp[i+1][j-1] 这个部分可以使用呢？？
        // 因为是斜着遍历，初始会使用初始为false这一右斜列，而通过len规避就可以使用到全为true，len=0这斜列了
        for(int len=0; len<n; len++) {
            for(int i=0; i+len<n; i++) {
                int j=i+len;
                if (len==0) {
                    dp[i][j] = true;
                } else if (len==1) { // 这个是单个字符
                    dp[i][j] = s[i]==s[j];
                } else { // 长度大于等于2就需要比较了
                    dp[i][j] = s[i]==s[j]&&dp[i+1][j-1];
                }

                if (dp[i][j] && len+1>res.size()) {
                    res = s.substr(i, len+1);
                }
            }
        }
        return res;
    }
};


class Solution2 {
public:
    pair<int, int> expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        // 从循环弹出的是不满足回文的，返回时要回退一个
        return {left + 1, right - 1};
    }

    string longestPalindrome(string s) {
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); ++i) {
            auto [left1, right1] = expandAroundCenter(s, i, i);
            auto [left2, right2] = expandAroundCenter(s, i, i + 1);
            if (right1 - left1 > end - start) {
                start = left1;
                end = right1;
            }
            if (right2 - left2 > end - start) {
                start = left2;
                end = right2;
            }
        }
        return s.substr(start, end - start + 1);
    }

};


// @lc code=end

int main() {
    LOG_DEBUG << Solution().longestPalindrome("babad");
    LOG_DEBUG << Solution().longestPalindrome("cbbd");
    LOG_DEBUG << Solution().longestPalindrome("a");
    LOG_DEBUG << Solution().longestPalindrome("ac");
}

