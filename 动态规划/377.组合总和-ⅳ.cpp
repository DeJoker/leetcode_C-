/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */
#include "../common/debugger.h"

// @lc code=start


// 一些恶心的用例过不了
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // const int mod = 1e9+7;
        int n=nums.size();
        vector<int64_t> dp(target+1);
        dp[0]=1;
        for (int i=0; i<=target; i++) {
            for (int num : nums) {
                if (i-num>=0)
                    dp[i] = dp[i]+dp[i-num];
                    // dp[i] = (dp[i]+dp[i-num])%mod;
            }
        }

        return (int)dp[target];
        



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
    // LOG_DEBUG << Solution().combinationSum4(p, 4);

    p={3,33,333};
    // LOG_DEBUG << Solution().combinationSum4(p, 10000);

    p={2,1,3};
    LOG_DEBUG << Solution().combinationSum4(p, 35); // 1132436852

    p={10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,370,380,390,400,410,420,430,440,450,460,470,480,490,500,510,520,530,540,550,560,570,580,590,600,610,620,630,640,650,660,670,680,690,700,710,720,730,740,750,760,770,780,790,800,810,820,830,840,850,860,870,880,890,900,910,920,930,940,950,960,970,980,990,111};
    LOG_DEBUG << Solution().combinationSum4(p, 999); // 1
}

