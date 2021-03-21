/*
 * @lc app=leetcode.cn id=312 lang=cpp
 *
 * [312] 戳气球
 */
#include "../common/debugger.h"

// 认为i和j是开区间，将其中每个戳爆的气球状态情况到dp[i][j] 中。
// k为i到j中的下标，k最后戳爆，那么就是结束

// @lc code=start

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(n+2, vector<int>(n+2, -1));

        std::function<int(int lf, int rg)> solve;
        solve = [&](int lf, int rg) {
            // 下标相等，返回0,？
            if (lf+1 >= rg) {
                return 0;
            }
            if (dp[lf][rg] != -1) {
                return dp[lf][rg];
            }

            // 开区间
            for(int i=lf+1; i<rg; ++i) {
                int num = nums[lf]*nums[rg]*nums[i];
                dp[lf][rg] = max(dp[lf][rg], solve(lf, i)+solve(i, rg)+num);
            }
            return dp[lf][rg];
        };

        return solve(0, n+1);
    }
};


class SolutionDP {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n=nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        // 开区间因此1到n-2 （原数组的闭区间）
        for(int len=1; len<n-1; ++len) {
            // i+len最大取n-1然后j=n-2是（原数组的闭区间）
            for(int i=1; i+len<n; i++) {
                int j=i+len-1;
                for(int k=i; k<=j; ++k) {
                    dp[i][j] = max(dp[i][j], dp[i][k-1]+dp[k+1][j] + nums[k]*nums[i-1]*nums[j+1]);
                }
            }
        }

        return dp[1][n-2];
    }
};
// @lc code=end

int main() {
    vector<int> p;
    p = {3,1,5,8};
    // LOG_DEBUG << Solution().maxCoins(p);
    p = {1,5};
    // LOG_DEBUG << Solution().maxCoins(p);
    p = {1};
    LOG_DEBUG << Solution().maxCoins(p);
}

