/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */
#include "../common/debugger.h"

// @lc code=start

// 选择只有当前元素入选与否，但对状态定义没有帮助（不能这么考虑）


// 典型的01背包题目。。。。

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int ss=strs.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        
        auto getCnt = [](const string& s) {
            vector<int> res(2);
            for(auto& c : s) {
                res[c-'0']++;
            }
            return res;
        };

        for(int i=0; i<ss; i++) {
            vector<int> zeroOne = getCnt(strs[i]);
            for(int j=m; j>=0; j--) {
                for(int k=n; k>=0; k--) {
                    if (zeroOne[0]<=j && zeroOne[1]<=k)
                        dp[j][k] = max(dp[j][k], dp[j-zeroOne[0]][k-zeroOne[1]]+1);
                }
            }
        }
        return dp[m][n];
    }
};



// 离谱。。。
class SolutionLipu {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int ss=strs.size();
        vector<pair<int, int>> form(ss);
        for(int i=0; i<ss; i++) {
            int zero(0), one(0);
            for(auto c : strs[i]) {
                if (c=='0')
                    ++zero;
                else 
                    ++one;
            }
            form[i] = {zero, one};
        }


        vector<vector<vector<int>>> dp(ss, vector<vector<int>>(m, vector<int>(n)));

        for(int i=1; i<ss; i++) {
            for(int j=0; j<m; ++j) {
                for(int k=0; k<n; ++k) {
                    if (j-form[i].first >=0 && k-form[i].second>=0)
                        dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-form[i].first][k-form[i].second]+1);
                }
            }
        }
        return 1;
    }
};


// @lc code=end

int main() {
    vector<string> p;
    p={"10", "0001", "111001", "1", "0"};
    LOG_DEBUG << Solution().findMaxForm(p, 5, 3);

    p={"10", "0", "1"};
    LOG_DEBUG << Solution().findMaxForm(p, 1, 1);
}