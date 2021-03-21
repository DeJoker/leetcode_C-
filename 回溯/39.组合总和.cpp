/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */
#include "../common/debugger.h"

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;

        std::function<void(vector<int>&, int, int)> dfs;
        dfs = [&](vector<int>& path, int sum, int idx) {
            if (sum == target) {
                ans.push_back(path);
                return;
            }
            if (idx == candidates.size()) {
                return;
            }

            // 跳过
            dfs(path, sum, idx+1);

            // 选择当前值
            if (sum+candidates[idx] <= target) {
                path.push_back(candidates[idx]);
                dfs(path, sum+candidates[idx], idx); // 为什么这里不idx+1呢
                path.pop_back();
            }
        };

        vector<int> p;
        dfs(p, 0, 0);
        return ans;
    }
};
// @lc code=end

int main() {
    vector<int> k; vector<vector<int>> r;
    k = {2,3,6,7};
    r = Solution().combinationSum(k, 7);
    DebugPlanarVector(r);
}


