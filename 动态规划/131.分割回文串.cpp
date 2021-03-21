/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */
#include "../common/debugger.h"

// @lc code=start



//     public List<List<String>> partition(String s) {
//         int len = s.length();
//         List<List<String>> res = new ArrayList<>();
//         if (len == 0) {
//             return res;
//         }

//         char[] charArray = s.toCharArray();
//         // 预处理
//         // 状态：dp[i][j] 表示 s[i][j] 是否是回文
//         boolean[][] dp = new boolean[len][len];
//         // 状态转移方程：在 s[i] == s[j] 的时候，dp[i][j] 参考 dp[i + 1][j - 1]
//         for (int right = 0; right < len; right++) {
//             // 注意：left <= right 取等号表示 1 个字符的时候也需要判断
//             for (int left = 0; left <= right; left++) {
//                 if (charArray[left] == charArray[right] && (right - left <= 2 || dp[left + 1][right - 1])) {
//                     dp[left][right] = true;
//                 }
//             }
//         }

//         Deque<String> stack = new ArrayDeque<>();
//         dfs(s, 0, len, dp, stack, res);
//         return res;
//     }

//     private void dfs(String s, int index, int len, boolean[][] dp, Deque<String> path, List<List<String>> res) {
//         if (index == len) {
//             res.add(new ArrayList<>(path));
//             return;
//         }

//         for (int i = index; i < len; i++) {
//             if (dp[index][i]) {
//                 path.addLast(s.substring(index, i + 1));
//                 dfs(s, i + 1, len, dp, path, res);
//                 path.removeLast();
//             }
//         }
//     }
// }

class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<string>> res;
        if (n==0) return {{}};
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

        std::function<void(vector<string>&, int)> dfs;
        dfs = [&](vector<string>& path, int idx) {
            if (idx == n) {
                res.push_back(path);
                return;
            }

            for(int i=idx; i<n; i++) {
                if (dp[idx][i]) {
                    path.push_back(s.substr(idx, i-idx+1));
                    dfs(path, i+1);
                    path.pop_back();
                }
            }
        };
        vector<string> p;
        dfs(p, 0);
        return res;
    }
};
// @lc code=end

int main() {
    vector<vector<string>> r;
    r = Solution().partition("aab");
    DebugPlanarVector(r);
}

