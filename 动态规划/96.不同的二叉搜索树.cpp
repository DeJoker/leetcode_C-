/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */
#include "../common/debugger.h"

// @lc code=start

class Solution {
public:
    int numTrees(int n) {
        vector<int> G(n + 1, 0);
        G[0] = 1;
        G[1] = 1;

        for (int i = 2; i <= n; ++i) { // 节点总数
            for (int j = 0; j < i; ++j) { // 左子树和右子树个数
                // 只要避免访问到G[-1] 并且两个乘数下标相加为i-1即可（需要排除根节点）
                G[i] += G[j] * G[i-j-1]; 
            }
        }
        return G[n];
    }
};


// 还是有误，正确是卡特兰数
class SolutionWrong {
public:
    map<int, int> memo;
    int dfs(int n) {
        if (memo.find(n)!=memo.end()) {
            return memo[n];
        }

        int res(0);
        for(int i=2; i<=n; i++) { // 取不到n，有一个节点作为根节点
            int lf = dfs(i-1);
            int rg = dfs(n-i);
            res += lf*rg;
        }
        memo[n] = res;
        return res;
    }

    int numTrees(int n) {
        memo[0] = 1; // 为什么这里是1，这里初始值有误导致以为递归写法有误
        memo[1] = 1;
        return dfs(n);
    }
};
// @lc code=end




int main() {
    LOG_DEBUG << Solution().numTrees(2);
    LOG_DEBUG << Solution().numTrees(3);
    LOG_DEBUG << Solution().numTrees(4);
    LOG_DEBUG << Solution().numTrees(5);

    LOG_DEBUG << SolutionWrong().numTrees(4);
    LOG_DEBUG << SolutionWrong().numTrees(5);
}
