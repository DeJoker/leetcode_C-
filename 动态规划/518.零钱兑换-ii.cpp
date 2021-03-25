/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */
#include "../common/debugger.h"

// @lc code=start


// 01背包的for循环可以兑换
class SolutionOne {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();

        vector<int> dp(amount+1);
        dp[0]=1;

        for(int i=0; i<n; i++) {
            for (int j=coins[i]; j<=amount; j++) {
                dp[j] += dp[j-coins[i]];
            }
        }

        return dp[amount];
    }
};


class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        if (amount==0) return 1;
        if (n==0) return 0;
        vector<vector<int>> dp(n+1, vector<int>(amount+1));
        
        // 硬币凑0元应该有一种方案
        for(int i=0; i<=n; i++) {
            dp[i][0] = 1;
        }

        for(int i=1; i<=n; i++) {
            for (int j=1; j<=amount; j++) {
                if (j<coins[i-1])  {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
                }
            }
        }

        return dp[n][amount];
    }
};


class SolutionWrong {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        if (amount==0) return 1;
        if (n==0) return 0;
        vector<int> dp(amount+1);
        
        dp[0] = 1; // 缺了这里最终状态出错
        for(int i=0; i<n; i++) {
            if (coins[i]>amount) continue;
            dp[coins[i]] = 1;
        }
        for(int j=coins[0]; j+coins[0]<=amount; j+=coins[0]) {
            dp[j+coins[0]] = 1;
        }

        for(int i=1; i<n; i++) {
            for (int j=coins[i]; j<=amount; j++) {
                dp[j] += dp[j-coins[i]];
            }
        }

        return dp[amount];
    }
};




// dp[i][j] 数组前i元素中，能凑成j的方案数是

class Solution333 {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        if (amount==0) return 1;
        if (n==0) return 0;
        vector<vector<int>> dp(n, vector<int>(amount+1));
        
        for(int i=0; i<n; i++) {
            if (coins[i]>amount) continue;
            dp[i][coins[i]] += 1;
        }
        for(int j=coins[0]; j+coins[0]<=amount; j+=coins[0]) {
            dp[0][j+coins[0]] += dp[0][j];
        }

        for(int i=1; i<n; i++) {
            for (int j=1; j<=amount; j++) {
                dp[i][j] += dp[i-1][j];
                if (j<coins[i]) continue;

                dp[i][j] += dp[i][j-coins[i]];
            }
        }

        return dp[n-1][amount];
    }
};
// @lc code=end

int main() {
    vector<int> p;
    p={1,2,5,};
    LOG_DEBUG << Solution().change(5, p);  // 4
    LOG_DEBUG << SolutionWrong().change(5, p);  // 4
    p={2};
    LOG_DEBUG << Solution().change(3, p);
    p={10};
    LOG_DEBUG << Solution().change(10, p);

    p={5};
    LOG_DEBUG << Solution().change(10, p);
    p={};
    LOG_DEBUG << Solution().change(0, p);
}
