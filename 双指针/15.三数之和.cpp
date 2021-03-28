/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include "../common/debugger.h"


// 三个数字a+b+c=0




// 先排序！！！

// 三个指针left、mid、right
// 外层循环left
// 内层循环 mid和right凑 -nums[left] 
// 需要考虑去重

// @lc code=start

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        int n=nums.size();
        for(int left=0; left<n-2; ++left) {
            int target = 0-nums[left];
            // 去重
            if (left>0 && nums[left-1]==nums[left]) continue;

            int mid=left+1, right=n-1;
            while (mid < right) {
                int cur = nums[mid]+nums[right];
                if (cur == target) {
                    res.push_back({nums[left], nums[mid], nums[right]});

                    // 去重
                    while (mid < right && nums[mid] == nums[mid+1]) ++mid;
                    while (mid < right && nums[right] == nums[right-1]) -- right;
                    ++mid; --right;
                } else if (nums[mid]+nums[right] > target) {
                    --right;
                } else {
                    ++mid;
                }
            }
        }

        return res;
    }
};

// @lc code=end


int main() {
    vector<int> p; vector<vector<int>> r;
    p = {-1,0,1,2,-1,-4,};
    r = Solution().threeSum(p);
    DebugPlanarVector(r);


}

