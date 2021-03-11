/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */
#include "../common/debugger.h"

// @lc code=start

// dp[i][j] 数组i，组成和为j的方案数



//     dp[i][j]表示到第i个字符和为j的方法数。
//     dp[i][j] = dp[i - 1][j - nums[i]] + dp[i - 1][j + nums[i]]
//     dp[i - 1][j - nums[i]] 表示这次是+时的方法数，
//     dp[i - 1][j + nums[i]] 表示这次是-时的方法数。
//     如果我们j正序遍历，把dp数组初始化为0.
//     则上面公式可以转化为：dp[i][j] == 0(计算前)
//     dp[i][j] = dp[i][j] + dp[i - 1][j - nums[i]]
//     dp[i][j] = dp[i][j] + dp[i - 1][j + nums[i]] ==>
//     遍历j时，我们利用上一次dp[i- 1][x]的计算结果，可以每次更新两个dp[i][x]的结果：
//     dp[i][j + nums[i]] = dp[i][j + nums[i]] + dp[i - 1][j]; 此时dp[i][j + nums[i]] = 0
//     dp[i][j - nums[i]] = dp[i][j - nums[i]] + dp[i - 1][j]; 此时dp[i][j - nums[i]] = 0 =>
//     编程如下形式：
//     dp[i][j + nums[i]] += dp[i - 1][j]
//     dp[i][j - nums[i]] += dp[i - 1][j]
//     这样，每次遍历j时，我们不计算dp[i][j]的值，而是利用dp[i - 1][j]的值，更新两个相关dp节点的值，会加速计算。


// class Solution {
//     public int findTargetSumWays(int[] nums, int S) {
//         int[][] dp = new int[nums.length][2001];
//         dp[0][nums[0] + 1000] = 1;
//         dp[0][-nums[0] + 1000] += 1;
//         for (int i = 1; i < nums.length; i++) {
//             for (int sum = -1000; sum <= 1000; sum++) {
//                 if (dp[i - 1][sum + 1000] > 0) {
//                     dp[i][sum + nums[i] + 1000] += dp[i - 1][sum + 1000];
//                     dp[i][sum - nums[i] + 1000] += dp[i - 1][sum + 1000];
//                 }
//             }
//         }
//         return S > 1000 ? 0 : dp[nums.length - 1][S + 1000];
//     }
// }

// 链接：https://leetcode-cn.com/problems/target-sum/solution/mu-biao-he-by-leetcode/


class Solution {
public:
    //dp[i][j] : 用数组中的前 i 个元素[0,1,...,i]，组成和为 j 的方案数。
    int findTargetSumWays(vector<int>& nums, int S) {
        int total=0;
        for(int i:nums) total+=i;
        if(total<abs(S)) return 0;

        int N=nums.size();   
        vector<vector<int>> dp(N, vector<int>(2*total+1));   //-total ... 0 ... total

        //用nums[0]形成的和j，对应的种数
        if(nums[0]==0) dp[0][total]=2;   //total对应索引位置 总和为0 +0或-0
        else{
            dp[0][total+nums[0]]=1;
            dp[0][total-nums[0]]=1;
        }

        for(int i=1; i<N; i++){
            for(int j=-total; j<=total; j++){   //通过 遍历总和j，映射到 对应数组索引
                if(total+j+nums[i]>=0 && total+j+nums[i]<2*total+1)
                    dp[i][total+j] += dp[i-1][total+j+nums[i]];   //减去nums[i]
                if(total+j-nums[i]>=0 && total+j-nums[i]<2*total+1)
                    dp[i][total+j] += dp[i-1][total+j-nums[i]];   //加上nums[i]
            }
        }

        return dp[N-1][total+S];   //total对应索引位置 总和为0，total+S对应索引位置 总和为S
    }
};


// 这道题不能只使用一个一维数组，因为在动态转移方程里，
// 每个状态dp[i][j]不仅依赖其上一行左边的值，也依赖上一行右边的值
// 因此无法实现一个一维数组更新，需要两个一维数组实现滚动更新。

class SolutionOnedimesion {
public:
    int findTargetSumWays(std::vector<int>& nums, int target) {
        int N = nums.size();
        int sum=0;

        for(const int& num : nums) sum += num;
        if(std::abs(target) > std::abs(sum)) 
        return 0;

        int boundary =  sum*2+1;
        std::vector<int> prev(boundary, 0);
        std::vector<int> curr(boundary, 0);

        // -sum 被映射到0
        // 0被映射到 sum
        // sum 被映射到 2*sum+1
        prev[sum + nums[0]] += 1;
        prev[sum - nums[0]] += 1;

        for(int i=1; i < N; ++i) { 
            for(int j=boundary-1; j >=0; --j) 
            { 
                int L = (j >= nums[i] ? prev[j - nums[i]] : 0);
                int R = (j + nums[i] < boundary ? prev[j + nums[i]] : 0);
                curr[j] = L + R;
            }
            prev.swap(curr);
        }

        // prev 在内循环后是填充完成的值，每次循环写是往curr写
        // 可以考虑边界，和一次循环内的情况：
        // 边界就是数组为0，那么返回prev合理
        // 循环一次后就退出，经过swap prev是填完成的值合理，因此返回prev
        return prev[sum + target];
    }
};

// @lc code=end



int main() {
    vector<int> p;
    p = {1,1,1,1,1,};
    LOG_DEBUG << Solution().findTargetSumWays(p, 3);
}
