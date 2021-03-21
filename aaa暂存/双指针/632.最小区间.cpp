/*
 * @lc app=leetcode.cn id=632 lang=cpp
 *
 * [632] 最小区间
 */

#include "../common/debugger.h"
// @lc code=start
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> ordered; // (number, group)
        for (size_t k = 0; k < nums.size(); ++k)
            for (auto n: nums[k]) ordered.push_back({n, k});
        sort(ordered.begin(), ordered.end());

        int i = 0, k = 0;
        vector<int> ans;
        unordered_map<int, int> count;
        for (size_t j = 0; j < ordered.size(); ++j) {
            ++count[ordered[j].second];
            if (count[ordered[j].second]==1)
                ++k;
            if (k == nums.size()) { 
                while (count[ordered[i].second] > 1)
                    --count[ordered[i++].second]; // minialize range
                if (ans.empty() || ans[1] - ans[0] > ordered[j].first - ordered[i].first) {
                    ans = vector<int>{ordered[i].first, ordered[j].first};
                }
            }
        }

        return ans;
    }
};
// @lc code=end

int main() {
    vector<vector<int>> aa{{3,1,4,1,5}};
    auto res = Solution().smallestRange(aa);
    DebugVector(res);
}

