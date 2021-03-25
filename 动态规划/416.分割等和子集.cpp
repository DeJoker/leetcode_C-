/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

#include "../common/debugger.h"

// @lc code=start

// dp[i][j] 前i个元祖能够凑成j
// dp[i][j] = dp[i][j] || dp[i-1][j-nums[i]]

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum(0);
        for(auto c : nums) sum+=c;
        if (sum%2==1) return false;
        int n=nums.size();

        int target = sum/2;
        vector<bool> dp(target+1, false);
        dp[0] = true;

        for(int i=0; i<n; i++) {
            for (int j=target; j>=nums[i]; --j) {
            // for (int j=target; j>=0; --j) {
            //     if (j<nums[i]) continue;
                dp[j] = dp[j] || dp[j-nums[i]];
            }
        }

        return dp[target];
    }
};
// @lc code=end


int main() {
    vector<int> p;
    p={1,5,11,5,};
    LOG_DEBUG << Solution().canPartition(p);
    p={1,2,3,5};
    LOG_DEBUG << Solution().canPartition(p);
}
