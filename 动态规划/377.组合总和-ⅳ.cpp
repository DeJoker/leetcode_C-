/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */
#include "../common/debugger.h"

// @lc code=start
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        const int mod = 1e9+7;
        int n=nums.size();
        vector<int> dp(target+1);
        dp[0]=1;
        for (int i=0; i<=target; i++) {
            for (int num : nums) {
                if (i-num>=0)
                    dp[i] = (dp[i]+dp[i-num])%mod;
            }
        }

        return dp[target];
        



        // int ans(0);
        // std::function<void(int sum, int idx)> dfs;
        // dfs = [&](int sum, int idx) {
        //     if (sum==target) {
        //         ++ans;
        //         return;
        //     }
        //     if (sum>target) {
        //         break;
        //     }

        //     for(int i=idx; i<nums.size(); i++) {
        //         sum += nums[i];
        //         dfs(sum, i);
        //         sum -= nums[i];
        //     }
        // };
        // dfs(0, 0);
        // return ans;


        
    }
};
// https://leetcode-cn.com/problems/combination-sum-iv/solution/dong-tai-gui-hua-python-dai-ma-by-liweiwei1419/

// 1、如果给定的数组中含有负数会怎么样？问题会产生什么变化？

// 如果有负数，相当于给定数组中的元素有了更多的组合，特别是出现了一对相反数的时候，例如题目中的示例 [-4, 1, 2, 3, 4]，target = 4 的时候，-4 和 4 可以无限次地、成对添加到题目中的示例中，成为新的组合，那么这道问题就没有什么意义了。

// 仔细思考，负数我只要不选它就行了。但由于这道问题的问法是“组合”，因此我们要保证有负数参与进来，不能够与已有的正数的组合之和为 0 即可。

// 2、我们需要在题目中添加什么限制来允许负数的出现？

// 如果有负数参与进来，不能够与已有的正数的组合之和为 0 ；
// 或者限制负数的使用次数，设计成类似 0-1 背包问题的样子。

// @lc code=end





int main() {
    vector<int> p;
    p={1,2,3};
    LOG_DEBUG << Solution().combinationSum4(p, 4);

    p={3,33,333};
    LOG_DEBUG << Solution().combinationSum4(p, 10000);
}

