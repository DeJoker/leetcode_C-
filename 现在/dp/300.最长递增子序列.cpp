/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */
#include "../common/debugger.h"

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(nums.size(), 1);
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        int res(1);
        for(int len : dp) {
            res = max(res, len);
        }
        return res;
    }
};
// @lc code=end

int main() {
    vector<int> p;
    p = {10,9,2,5,3,7,101,18};
    LOG_DEBUG << Solution().lengthOfLIS(p);
    p = {0,1,0,3,2,3};
    LOG_DEBUG << Solution().lengthOfLIS(p);
    p = {7,7,7,7,7,7,7};
    LOG_DEBUG << Solution().lengthOfLIS(p);
}
