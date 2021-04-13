/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */
#include "../common/debugger.h"

// 输入: n = 4, k = 2
// 输出:
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]

// @lc code=start


// 44ms  8.9MB
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;

        std::function<void(vector<int>&, int)> backtrack;
        backtrack = [&](vector<int>& path, int idx) {
            if (path.size() == k) {
                res.push_back(path);
                return;
            }

            for(int i=idx; i<=n; i++) {
                path.push_back(i);
                backtrack(path, i+1);
                path.pop_back();
            }
        };

        vector<int> path;
        backtrack(path, 1);
        return res;
    }
};
// @lc code=end

int main() {
    vector<vector<int>> res;
    res = Solution().combine(4, 2);
    DebugPlanarVector(res);
}

