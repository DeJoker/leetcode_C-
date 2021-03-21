/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */
#include "../common/debugger.h"

// @lc code=start
class Solution {
public:
    map<int, int> memo;
    int climbStairs(int n) {
        if (memo.find(n)!=memo.end()) {
            return memo[n];
        }

        if (n<=2) return n;
        int res = climbStairs(n-1) + climbStairs(n-2);
        memo[n] = res;
        return res;
    }
};
// @lc code=end


int main() {
    LOG_DEBUG << Solution().climbStairs(2);
    LOG_DEBUG << Solution().climbStairs(3);
    LOG_DEBUG << Solution().climbStairs(10);
}
