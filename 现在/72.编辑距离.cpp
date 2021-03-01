/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */
#include "../common/debugger.h"

// @lc code=start

// 超时
class SolutionB {
public:
    int minDistance(string word1, string word2) {
        std::function<int(int, int)> dp;

        dp = [&](int i, int j) {

            if (i==-1) return j+1;
            if (j==-1) return i+1;

            if (word1[i] == word2[j]) {
                // ++i; ++j;
                return dp(i-1, j-1);
            } else {
                return min(
                    dp(i-1, j-1),
                    min(dp(i-1, j), dp(i, j-1))
                ) +1;
            }
        };

        return dp(word1.size()-1, word2.size()-1);
    }
};


// Your runtime beats 8.83 % of cpp submissions
// Your memory usage beats 5 % of cpp submissions (17.2 MB)
class Solution {
public:
    int minDistance(string word1, string word2) {
        std::function<int(int, int)> dp;
        map<pair<int,int>, int> memo;

        dp = [&](int i, int j) {
            if (memo.find({i,j}) != memo.end()) {
                return memo[{i,j}];
            }

            if (i==-1) return j+1;
            if (j==-1) return i+1;

            int res;
            if (word1[i] == word2[j]) {
                res = dp(i-1, j-1);
            } else {
                res =  min(
                    dp(i-1, j-1),
                    min(dp(i-1, j), dp(i, j-1))
                ) +1;
            }
            memo[{i,j}] = res;
            return res;
        };

        return dp(word1.size()-1, word2.size()-1);
    }
};
// @lc code=end

int main() {
    LOG_DEBUG <<Solution().minDistance("horse", "ros");
    LOG_DEBUG <<Solution().minDistance("horse", "rose");
    LOG_DEBUG <<Solution().minDistance("intention", "execution");
}
