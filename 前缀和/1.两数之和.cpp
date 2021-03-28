/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include "../common/debugger.h"

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp; // nums[i] -> i

        for (int i=0; i<nums.size(); i++) {
            if (mp.find(target-nums[i]) != mp.end()) {
                return {mp[target-nums[i]], i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end


int main() {
    vector<int> p, r;
    p={2,7,11,15};
    r = Solution().twoSum(p, 9);
    DebugVector(r);

    p={3,2,4};
    r = Solution().twoSum(p, 6);
    DebugVector(r);

    p={3,3,};
    r = Solution().twoSum(p, 6);
    DebugVector(r);
}
