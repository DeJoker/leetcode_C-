/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */
#include "../common/debugger.h"

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;

        std::function<void(int, int, string&)> dfs;
        dfs = [&](int lf, int rg, string& path) {
            if (rg<lf) { // 当前右括号更多，非法字符
                return;
            }
            if (rg==0 && lf==0) {
                res.push_back(path);
            }

            if (lf>0) {
                path.push_back('(');
                dfs(lf-1, rg, path);
                path.pop_back();
            }

            if (rg>0) {
                path.push_back(')');
                dfs(lf, rg-1, path);
                path.pop_back();
            }
        };

        string p;
        dfs(n, n, p);
        return res;
    }
};
// @lc code=end

int main() {
    vector<string> r;
    r = Solution().generateParenthesis(3);
    DebugVector(r);
    r = Solution().generateParenthesis(1);
    DebugVector(r);
}

