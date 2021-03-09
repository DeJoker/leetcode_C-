/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */
#include "../common/debugger.h"

// @lc code=start



class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;

        std::function<void(vector<int>& path, int sum, int idx)> dfs;
        dfs = [&](vector<int>& path, int sum, int idx) {
            if (sum==target) {
                ans.push_back(path);
                return;
            }

            if (idx==candidates.size()) { // 不用加这句或者说应该放在sum==target后面
                return;
            }

            for(int i=idx; i<candidates.size(); i++) {
                if (sum+candidates[i] > target) {  // 提前排除过大的解
                    break;
                }

                // 通过递归过程中i==idx首项，所以只是迭代时非首项被过滤
                if (i>idx && candidates[i]==candidates[i-1]) {
                    continue;
                }
                path.push_back(candidates[i]);
                dfs(path, sum+candidates[i], i+1);
                path.pop_back();
            }
        };

        // 排序，跳过重复组合的解
        sort(candidates.begin(), candidates.end());

        vector<int> p;
        dfs(p, 0, 0);
        return ans;
    }
};


class SolutionRawWrong {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;

        std::function<void(vector<int>& path, int sum, int idx)> dfs;
        dfs = [&](vector<int>& path, int sum, int idx) {
            if (idx==candidates.size() || sum>target) {
                return;
            }
            if (sum==target) {
                ans.push_back(path);
            }

            // if () {
            //     return;
            // }

            for(int i=idx; i<candidates.size(); i++) {
                path.push_back(candidates[i]);
                dfs(path, sum+candidates[i], i+1);
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
    vector<int> p; vector<vector<int>> r;
    // p = {10,1,2,7,6,1,5};
    // r = Solution().combinationSum2(p, 8);
    // DebugPlanarVector(r);
    // p = {2,5,2,1,2};
    // r = Solution().combinationSum2(p, 5);
    // DebugPlanarVector(r);

    p = {1,1,2,1};
    r = Solution().combinationSum2(p, 3);
    DebugPlanarVector(r);
}

