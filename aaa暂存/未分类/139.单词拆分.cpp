/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */
#include "../common/debugger.h"


// const wordBreak = (s, wordDict) => {
//   const wordSet = new Set(wordDict);
//   const len = s.length;
//   const dp = new Array(len + 1).fill(false);
//   dp[0] = true;

//   for (let i = 1; i <= len; i++) {
//     for (let j = i - 1; j >= 0; j--) {    // j去划分成两部分
//       const suffix = s.slice(j, i);       // 后缀部分 s[j: i-1]
//       if (wordSet.has(suffix) && dp[j]) { // 后缀部分是单词，且左侧子串[0,j-1]的dp[j]为真
//         dp[i] = true;
//         break;  // dp[i] = true了，i长度的子串已经可以拆成单词了，不需要j继续划分子串了
//       }
//     }
//   }
//   return dp[len];
// };

// https://leetcode-cn.com/problems/word-break/solution/shou-hui-tu-jie-san-chong-fang-fa-dfs-bfs-dong-tai/


// @lc code=start
class Solution {
public:
    bool wordBreak(string s, const vector<string>& wordDict) {
        int len = s.size();
        vector<bool> dp(len+1, false);
        map<string, bool> dict;
        for(auto& word : wordDict) {
            dict[word] = true;
        }
        dp[0] = true;

        for(int i=1; i<=len; i++) {
            for(int j=i-1; j>=0; --j) {
                if (dp[i]) break;
                if (!dp[j]) continue;

                string suffix = s.substr(j, i-j);
                if (dict.end() != dict.find(suffix) && dp[j]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[len];
    }
};
// @lc code=end

int main() {
    LOG_DEBUG << Solution().wordBreak("leetcode", {"leet", "code"});
    LOG_DEBUG << Solution().wordBreak("applepenapple", {"apple", "pen"});
    LOG_DEBUG << Solution().wordBreak("catsandog", {"cats", "dog", "sand", "and", "cat"});
}
