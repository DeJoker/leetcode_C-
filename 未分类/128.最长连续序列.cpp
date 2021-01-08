/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */
#include "../common/debugger.h"

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        sort(nums.begin(), nums.end());
        int maxLen(1), from(nums[0]);
        int curLen(1);
        for(int i=1; i<nums.size(); ++i) {
            if (from+1 == nums[i]) {
                curLen++;
            } else {
                if (curLen > maxLen) {
                    maxLen = curLen;
                }
                curLen = 1;
            }
            from = nums[i];
        }

        return maxLen>curLen ? maxLen : curLen;
    }
};
// @lc code=end


int main() {
    // vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    // vector<int> nums = {9,1,4,7,3,-1,0,5,8,-1,6};
    vector<int> nums = {1,2,0,1};
    LOG_DEBUG << Solution().longestConsecutive(nums);
}
