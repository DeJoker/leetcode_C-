/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */
#include "../common/debugger.h"

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;

        std::function<void(vector<int>& path, int sum, int idx)> dfs;
        dfs = [&](vector<int>& path, int sum, int idx) {
            if (sum==n && path.size()==k) {
                ans.push_back(path);
                return;
            }
            if (path.size() > k) {
                return;
            }

            for(int i=idx; i<=9; i++) {
                path.push_back(i);
                dfs(path, sum+i, i+1);
                path.pop_back();
            }


        };

        vector<int> p;
        dfs(p, 0, 1);
        return ans;
    }
};
// @lc code=end

int main() {
    vector<vector<int>> r;
    r = Solution().combinationSum3(3, 7);
    DebugPlanarVector(r);
    r = Solution().combinationSum3(3, 9);
    DebugPlanarVector(r);
}

