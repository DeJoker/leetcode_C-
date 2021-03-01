/*
 * @lc app=leetcode.cn id=887 lang=cpp
 *
 * [887] 鸡蛋掉落
 */
#include "../common/debugger.h"

// @lc code=start


// dp[m - 1][j - 1] + dp[m - 1][j] 就可以将[m - 1] 这个位置优化掉
class Solution {
public:
    int superEggDrop(int K, int N) {
		vector<int> dp(K + 1);
		int res = 0;
		for (; dp[K] < N; ++res) {
			for (int i = K; i > 0; --i) {
				dp[i] = dp[i] + dp[i - 1] + 1;
			}
		}
		return res;
    }
};

// @lc code=end

int main() {
    LOG_DEBUG << Solution().superEggDrop(1, 2);
}


class SolutionXXXXXXXXXX {
public:
    int superEggDrop(int K, int N) {
		vector<int> dp(K + 1);
		int res = 0;
		for (; dp[K] < N; ++res) {
			for (int i = K; i > 0; --i) {
				dp[i] = dp[i] + dp[i - 1] + 1;
			}
		}
		return res;
    }
};


// 时间复杂度为O(KN^2)，空间复杂度为O(KN)
class Solution1 {
public:
    int superEggDrop(int K, int N) {
        int eggNum = K, floorNum = N;
        if(eggNum < 1 || floorNum < 1)
            return 0;
        //备忘录，存储eggNum个鸡蛋，floorNum层楼条件下的最优化尝试次数
        vector<vector<int>> cache(eggNum + 1, vector<int>(floorNum + 1, 0));
        //把备忘录每个元素初始化成最大的尝试次数
        for(int i = 1; i <= eggNum; i ++){
            for(int j = 1; j <= floorNum; j ++)
                cache[i][j] = j;
        }
        for(int n = 2; n <= eggNum; n ++){
            for (int m = 1; m <= floorNum; m ++){
                for(int k = 1; k < m; k ++){
                    //扔鸡蛋的楼层从1到m枚举一遍，如果当前算出的尝试次数小于上一次的尝试次数
                    cache[n][m] = min(cache[n][m], max(cache[n - 1][k - 1], cache[n][m - k]) + 1);
                }
            }
        }
        return cache[eggNum][floorNum];
    }
};


// 空间复杂度很容易优化成O(N)   时间上超时
class Solution2 {
public:
    int superEggDrop(int K, int N) {
        int eggNum = K, floorNum = N;
        if(eggNum < 1 || floorNum < 1)
            return 0;
        //上一层备忘录，存储鸡蛋数量-1的相应情况
        vector<int> preCache(floorNum + 1, 0);
        //当前备忘录，存储当前鸡蛋数量的相应情况
        vector<int> currentCache(floorNum + 1, 0);
        //把备忘录每个元素初始化成最大的尝试次数
        for(int i = 1; i <= floorNum; i ++){
            currentCache[i] = i;
        }
        for(int n = 2; n <= eggNum; n ++){
            preCache = currentCache;
            for(int i = 1; i <= floorNum; i ++){
                currentCache[i] = i;
            }
            for (int m = 1; m <= floorNum; m ++){
                for(int k = 1; k < m; k ++){
                    //扔鸡蛋的楼层从1到m枚举一遍，如果当前算出的尝试次数小于上一次的尝试次数
                    currentCache[m] = min(currentCache[m], max(preCache[k - 1], currentCache[m - k]) + 1);
                }
            }
        }
        return currentCache[floorNum];
    }
};



// 重定义状态
class Solution3 {
public:
    int superEggDrop(int K, int N) {
		vector<vector<int>> dp(N + 1, vector<int>(K + 1));
		int m = 0;
		while (dp[m][K] < N) {
			++m;
			for (int j = 1; j <= K; ++j) {
				dp[m][j] = dp[m - 1][j - 1] + dp[m - 1][j] + 1;
			}
		}
		return m;
    }
};

// dp[m - 1][j - 1] + dp[m - 1][j] 就可以将[m - 1] 这个位置优化掉
class Solution4 {
public:
    int superEggDrop(int K, int N) {
		vector<int> dp(K + 1);
		int res = 0;
		for (; dp[K] < N; ++res) {
			for (int i = K; i > 0; --i) {
				dp[i] = dp[i] + dp[i - 1] + 1;
			}
		}
		return res;
    }
};



// 链接：https://leetcode-cn.com/problems/super-egg-drop/solution/c-duo-chong-jie-fa-chao-shi-de-dphe-you-hua-de-dp-/

