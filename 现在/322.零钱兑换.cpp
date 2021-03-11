/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */
#include "../common/debugger.h"

// dp[i][j] = min(dp[i][j], dp[i-1][j-coins[i]]+1)

// @lc code=start

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        if (n==0) return -1;
        vector<int> dp(amount+1, INT_MAX);

        // base case
        dp[0] = 0;
        for(int i=0; i<n; i++) {
            if (amount>=coins[i])
                dp[coins[i]] = 1;
        }


        for (int j=0; j<=amount; ++j) {
            for (int i=0; i<n; i++) {
                if (j<coins[i]) continue;

                int coin = dp[j-coins[i]];
                if (coin != INT_MAX)
                    dp[j] = min(dp[j], coin+1);
            }
        }

        return dp[amount]==INT_MAX ? -1 : dp[amount];
    }
};

class SolutionTwo {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        if (n==0) return -1;
        vector<vector<int>> dp(n, vector<int>(amount+1, INT_MAX));

        // base case
        // for (int i=0; i<n; i++) {
        //     for (int k=1; k*coins[i]<=amount; ++k) {
        //         dp[i][k*coins[i]] = k;
        //     }
        // }

        for (int i=0; i<n; i++) {
            dp[i][0] = 0;
        }
        for (int k=1; k*coins[0]<=amount; ++k) {
            dp[0][k*coins[0]] = k;
        }
        for(int i=0; i<n; i++) {
            if (amount>=coins[i])
                dp[i][coins[i]] = 1;
        }


        for (int j=0; j<=amount; ++j) {
            for (int i=1; i<n; i++) {
                dp[i][j] = dp[i-1][j]; // 忘了加这句
                if (j<coins[i]) continue;

                int coin = min(dp[i-1][j-coins[i]], dp[i][j-coins[i]]);
                if (coin != INT_MAX)
                    dp[i][j] = min(dp[i][j], coin+1);
            }
        }

        return dp[n-1][amount]==INT_MAX ? -1 : dp[n-1][amount];
    }
};
// @lc code=end

int main() {
    vector<int> p;
    p = {1,2,5,};
    LOG_DEBUG << Solution().coinChange(p, 11); // 3
    p = {2};
    LOG_DEBUG << Solution().coinChange(p, 3); // -1
    p = {1};
    LOG_DEBUG << Solution().coinChange(p, 0); // -1
}
