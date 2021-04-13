/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */
#include "../common/debugger.h"


// @lc code=start
// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>> ans;
//         return ans;
//     }
// };



// 0ms 7MB
class Solution {
public:
    vector<int> t;
    vector<vector<int>> ans;

    void dfs(int cur, vector<int>& nums) {
        if (cur == nums.size()) {
            ans.push_back(t);
            return;
        }

        t.push_back(nums[cur]);
        dfs(cur + 1, nums);
        t.pop_back();
        dfs(cur + 1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return ans;
    }
};


// 4 ms   6.8 MB
class Solution44 {
public:
    vector<vector<int>> subsets(vector<int> nums) {
        vector<vector<int>> res;
        int n = nums.size();

        std::function<void(vector<int>&, int)> backtrack;
        backtrack = [&](vector<int>& path, int start) {
            res.push_back(path);

            for(int i=start; i<n; i++) {
                path.push_back(nums[i]);
                backtrack(path, i+1);
                path.pop_back();
            }
        };

        vector<int> path;
        backtrack(path, 0);
        return res;
    }
};

// @lc code=end

int main() {
    vector<int> a{1,2,3};
    vector<vector<int>> pp;

    pp = Solution33().subsets(a);
    DebugPlanarVector(pp);

    pp = Solution44().subsets(a);
    DebugPlanarVector(pp);
}
