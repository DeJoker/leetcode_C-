/*
 * @lc app=leetcode.cn id=879 lang=cpp
 *
 * [879] 盈利计划
 */
#include "../common/debugger.h"

// @lc code=start

// dpProfit[i][j]
// dpScheme[i] 方案数

// dp[i][profit] 方案数     当前负载、获取利润
// dp[k][profit] += dp[k-group[i]][profit-profit[i]]



class Solution {
    const int MOD = 1e9+7;
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int N = group.size();
        int maxProfit = accumulate(profit.begin(), profit.end(), 0); // #include <numeric>

        // 将大于P的利润的方案数，全部合在利润为P的方案数上
        // 可以理解为将原先[0,Sp]，在坐标轴上，向左平移，将小于0的方案数 ，全压在0的方案数上
        vector<vector<int>> dp(n+1, vector<int>(minProfit+1)); 
        dp[0][0] = 1;
        for(int i=1; i<=N; i++) {
            for(int j=n; j>=group[i-1]; j--) {
                for(int k=minProfit; k>=0; --k) {
                    dp[j][k] = (dp[j][k] + dp[j-group[i-1]][max(k-profit[i-1], 0)])%MOD;
                }
            }
        }

        int ans(0);
        for(int i=0; i<=n; i++)
            ans = (ans+dp[i][minProfit])%MOD;

        return ans;
    }
};


// 超时
class SolutionLimit {
    const int MOD = 1e9+7;
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int N = group.size();
        int maxProfit = accumulate(profit.begin(), profit.end(), 0); // #include <numeric>

        vector<vector<int>> dp(n+1, vector<int>(maxProfit+1));
        dp[0][0] = 1;
        for(int i=1; i<=N; i++) {
            for(int j=n; j>=group[i-1]; j--) {
                for(int k=maxProfit; k>=profit[i-1]; --k) {
                    dp[j][k] = (dp[j][k] + dp[j-group[i-1]][k-profit[i-1]])%MOD;
                }
            }
        }

        int ans(0);
        for(int i=0; i<=n; i++)
            for(int j=minProfit; j<=maxProfit; j++)
                ans = (ans+dp[i][j])%MOD;

        return ans;
    }
};

// 回溯法，复杂度pow（2， N）但是可以通过样例
// 数组元素最大100，2^100 时间复杂度
class SolutionBacktrack {
    const int MOD = 1e9+7;
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        const int N=group.size();
        vector<vector<vector<int>>> d(N+1,vector<vector<int>>(n+1,vector<int>(minProfit+1,-1)));
        
        std::function<int(int, int, int)> dfs;
        dfs = [&](int cur, int g, int p) {
            if(cur >= N){
                if(p == minProfit) {
                    return 1;
                }
                return 0;
            }

            int& ans = d[cur][g][p];
            if(ans != -1){
                return ans;
            }

            int a = dfs(cur+1, g, p);
            int b=0;
            if(g >= group[cur]){
                b=dfs(cur+1, g-group[cur], std::min(minProfit, p+profit[cur]));
            }

            ans=(a+b) % MOD;
            return ans;
        };

        return dfs(0,n,0);
    }
};

// 详细解法
// https://leetcode-cn.com/problems/profitable-schemes/solution/hui-su-dong-tai-gui-hua-by-jason-2-bxsw/

// 背包汇总
// https://leetcode-cn.com/problems/profitable-schemes/solution/leetcode-01bei-bao-zong-jie-by-pedantic-einstein/

// @lc code=end

int main() {
    vector<int> g, p;
    g={2,2}, p={2,3};
    LOG_DEBUG << Solution().profitableSchemes(5, 3, g, p); // 2

    g={2,3,5}, p={6,7,8,};
    LOG_DEBUG << Solution().profitableSchemes(10, 5, g, p); // 7
}

