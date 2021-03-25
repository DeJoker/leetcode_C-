/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */
#include "../common/debugger.h"

// @lc code=start

// dp[i] = max(dp[i-j]*j);
// 将i拆成 i-j和j，并继续拆分 dp[i-j]*j
// 将i拆成 i-j和j，且不再拆分 (i-j)*j   
// 为什么一开始忽略了这种情况呢，还是我们的状态定义：dp[i-j]没有包含 拆分i-j这种情况，最边界是i-j-1 和 1
// 而且初始值有误导致了误导，应该全为0

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        for(int i=1; i<=n; i++) {
            int maxk = 1;
            for(int j=i; j>0; --j) {
                // maxk = max(maxk, dp[i-j]*j);
                maxk = max(maxk, max(dp[i-j]*j, (i-j)*j) );
            }
            dp[i] = maxk;
        }
        return dp[n];
    }
};


class SolutionWrong {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 1);
        dp[0]=0;
        for(int i=1; i<=n; i++) {
            int maxk = 1;
            for(int j=i; j>0; --j) {
                maxk = max(maxk, dp[i-j]*j);
            }
            dp[i] = maxk;
        }
        return dp[n];
    }
};
// @lc code=end

int main() {
    LOG_DEBUG << Solution().integerBreak(2); // 1
    LOG_DEBUG << Solution().integerBreak(10); // 36
    LOG_DEBUG << Solution().integerBreak(58);
}

