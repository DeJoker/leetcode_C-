/*
 * @lc app=leetcode.cn id=464 lang=cpp
 *
 * [464] 我能赢吗
 */
#include "../common/debugger.h"


// 最后看起来是备忘录的回溯解法

// 如何定义稳赢
// 如果从某个节点开始，有这么一条路径，在先手选了之后，无论后手怎么选都会赢
// 同理如果后手有一种选择方式可以让先手输，那么这条路径就被否决

// 不过编写递归时考虑的却是：
// 如果我先手，遍历所有可能，有一条路径可以成功，我就能成功
// 有一条路径让我稳赢，那我就稳赢

// @lc code=start

// 44 ms
class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal) return true;
        if ((1+maxChoosableInteger)*maxChoosableInteger/2 < desiredTotal) return false;

        // maxChoosableInteger个全1的二进制数
        vector<bool> dp((1<<maxChoosableInteger) -1);
        map<string, bool> memo;

        std::function<bool(int desired, int state)> backtrack;
        backtrack = [&](int desired, int state) -> bool {
            if (dp[state]) {
                return dp[state]; // ‘std::_Bit_reference’ 显示指定bool让其类型转换
            }

            for(int i=1; i<=maxChoosableInteger; i++) {
                int tmp = (1<< (i-1));
                // 取第i位，是否被占用，没有占用开始判断
                if ((tmp&state) == 0) {
                    // 直接取可以赢 or 回溯判断后手会输
                    if (desired-i <=0 || !backtrack(desired-i, tmp|state)) {
                        dp[state] = true;
                        return true;
                    }
                }
            }

            return false;
        };

        return backtrack(desiredTotal, 0);
    }
};


// 超时
class SolutionLimit {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal) return true;
        if ((1+maxChoosableInteger)*maxChoosableInteger/2 < desiredTotal) return false;

        vector<int> state(maxChoosableInteger+1); // 仅使用1到max+1
        map<string, bool> memo;

        auto vec2Str = [](vector<int>& vec) {
            string k;
            for(auto v : vec) {
                k += to_string(v);
            }
            return k;
        };

        std::function<bool(int desired, vector<int>& state)> backtrack;
        backtrack = [&](int desired, vector<int>& state) {
            string key = vec2Str(state);
            if (memo.find(key) != memo.end()) {
                return memo[key];
            }

            for(int i=1; i<state.size(); i++) {
                if (state[i]==0) {

                    state[i] = 1;
                    // 直接取可以赢 or 回溯判断后手会输
                    if (desired-i <=0 || !backtrack(desired-i, state)) {
                        memo[key] = true;
                        state[i] = 0;
                        return true;
                    }
                    // 赢不赢都要回溯
                    state[i] = 0;
                }
            }

            memo[key] = false;
            return false;
        };

        return backtrack(desiredTotal, state);
    }
};
// @lc code=end


int main() {
    LOG_DEBUG << Solution().canIWin(10, 11); // 0
}



// 错误的思考

// 2..8 可以在1/9/10中取
// 定义dp[i][j]first 是从i到j数组中构成的先手获得最大收益
// dp[i][j]first = max(dp[i][j]second) + max
// 如果first和sceond谁先到Total就结束
