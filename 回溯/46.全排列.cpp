/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
#include "../common/debugger.h"

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int n=nums.size();

        std::function<void(int, vector<int>&)> backtack;
        backtack = [&](int start, vector<int>& path) {
            if (start==n) {
                res.push_back(path);
                return;
            }

            for(int i=start; i<n; i++) {
                swap(path[start], path[i]);
                backtack(start+1, path); // 这里是first+1
                swap(path[start], path[i]);
            }
        };

        backtack(0, nums);
        return res;
    }
};
// @lc code=end

int main() {
    vector<vector<int>> r;
    vector<int> num;
    num = {1,2,3};
    r = Solution().permute(num);
    DebugPlanarVector(r);

    return 0;
}

