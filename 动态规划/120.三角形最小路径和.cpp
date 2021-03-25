/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */
#include "../common/debugger.h"

// @lc code=start

// 二维dp空间优化
// 既然是两边的特殊情况，就在循环外开头结尾先设置就行

// 不能正序，因为前一个状态已经被赋值了
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty()) return 0;
        int n=triangle.size();

        vector<int> dp(n, 0);
        dp[0] = triangle[0][0];

        for(int i=1; i<n; i++) {

            // 逆序
            dp[i] = dp[i - 1] + triangle[i][i];
            for (int j = i - 1; j > 0; --j) {
                dp[j] = min(dp[j - 1], dp[j]) + triangle[i][j];
            }
            dp[0] += triangle[i][0];

            
            // dp[0] = dp[0] + triangle[i][0];
            // for(int j=1; j<i; j++) {
            //     dp[j] = min(dp[j-1], dp[j]) + triangle[i][j];
            // }
            // dp[i] = dp[i-1] + triangle[i][i];
        }

        return *min_element(dp.begin(), dp.end());
    }
};

class SolutionTwoDimen {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty()) return 0;
        int n=triangle.size();

        vector<vector<int>> dp(n, vector<int>(n));
        dp[0][0] = triangle[0][0];
        for(int i=1; i<n; i++) {
            for(int j=0; j<=i; ++j) {
                if (j==0)
                    dp[i][j] = dp[i-1][j]+triangle[i][j];
                else if (j==i)
                    dp[i][j] = dp[i-1][j-1]+triangle[i][j];
                else
                    dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
            }
        }

        int res(INT_MAX);
        for(int i=0; i<n; i++) {
            res = min(res, dp[n-1][i]);
        }
        return res;

    }
};


class Solution3333 {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty()) return 0;

        vector<int> dp(1, triangle[0][0]);
        auto fill = [&](int prev, int i, int j) {
            if (j==triangle[i].size()) return;

            if (dp.size() <= j) {
                dp.push_back(prev+triangle[i][j]);
            } else {
                dp[j] = prev+triangle[i][j];
            }
        };

        int n=triangle.size();
        for(int i=1; i<n; i++) {
            for(int j=0; j+1<triangle[i].size(); j+=2) {
                int prev = dp[j];
                fill(prev, i, j);
                fill(prev, i, j+1);
            }
        }

        int res(INT_MAX);
        for(int i=0; i<dp.size(); i++) {
            res = min(res, dp[i]);
        }
        return res;
    }
};
// @lc code=end

int main() {
    vector<vector<int>> p;
    p = {{2},{3,4},{6,5,7},{4,1,8,3}}; // 15 11 18 16
    LOG_DEBUG << Solution().minimumTotal(p);
}

