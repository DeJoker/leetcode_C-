/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 排列序列
 */
#include "../common/debugger.h"

// @lc code=start
class Solution {
public:
    string getPermutation(int n, int k) {
        string s, res;
        for(int i=1; i<=n; ++i) {
            s += '0'+i;
        }
        int cur=0;

        std::function<void(int, string&)> dfs;
        dfs = [&](int start, string& path) {
            if (start==n) {
                ++cur;
                if (cur == k) {
                    res = path;
                }
                return;
            }
            
            for(int i=start; i<n && res.empty(); i++) {
                swap(s[start], s[i]);
                dfs(start+1, path);
                swap(s[start], s[i]);
            }
        };

        dfs(0, s);
        return res;
    }
};
// @lc code=end


int main() {
    LOG_DEBUG << Solution().getPermutation(8, 3); // "12345768"
    LOG_DEBUG << Solution().getPermutation(3, 3); // "213"
    LOG_DEBUG << Solution().getPermutation(4, 9); // "2314"
    LOG_DEBUG << Solution().getPermutation(3, 1); // "123"

    LOG_DEBUG << Solution().getPermutation(3, 4); // "231"
    LOG_DEBUG << Solution().getPermutation(3, 5); // "312"
}
