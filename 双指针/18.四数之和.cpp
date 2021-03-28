/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */
#include "../common/debugger.h"

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        int n=nums.size();
        for (int i=0; i<n-3; i++) {
            if (i>0 && nums[i]==nums[i-1]) continue;

            for(int left=i+1; left<n-2; ++left) {
                // 去重
                if (left>i+1 && nums[left-1]==nums[left]) continue;

                int need = target-nums[left]-nums[i];
                int mid=left+1, right=n-1;

                while (mid < right) {
                    int cur = nums[mid]+nums[right];
                    if (cur == need) {
                        res.push_back({nums[i], nums[left], nums[mid], nums[right]});

                        // 去重
                        while (mid < right && nums[mid] == nums[mid+1]) ++mid;
                        while (mid < right && nums[right] == nums[right-1]) -- right;
                        ++mid; --right;
                    } else if (nums[mid]+nums[right] > need) {
                        --right;
                    } else {
                        ++mid;
                    }
                }
            }
        }

        return res;
    }
};



// @lc code=end

int main() {
    vector<int> p; vector<vector<int>> r;
    p = {1,0,-1,0,-2,2};
    r = Solution().fourSum(p, 0);
    DebugPlanarVector(r);

    p = {0,0,0,0,};
    r = Solution().fourSum(p, 0);
    DebugPlanarVector(r);
}
