/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */
#include "../common/debugger.h"

// 石头相撞，最小剩余大小

// @lc code=start

// 分为两组，组间差距最小即可
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum(0);
        for(int s : stones) sum += s;
        int target = sum/2;

        vector<int> dp(target+1);
        for(int i=0; i<stones.size(); i++) {
            for(int j=target; j>=stones[i]; --j) {
                dp[j] = max(dp[j], dp[j-stones[i]]+stones[i]);
            }
        }
        // dp[target] 是最大容纳石头个数
        // 两堆分别是 dp[target] 和 sum - dp[target] 两者相减就是差距
        return (sum - dp[target]) - dp[target];
    }
};
// @lc code=end


int main() {
    vector<int> p;

    p={2,7,4,1,8,1};
    LOG_DEBUG << Solution().lastStoneWeightII(p);
}
