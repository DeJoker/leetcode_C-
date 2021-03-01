#!/usr/bin/python3

from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        if n<=1: return 0

        dp = [[None, None] for _ in range(n)]
        dp[0][0] = 0
        dp[0][1] = -prices[0]
        dp[1][0] = max(dp[0][0], dp[0][1]+prices[1])  # 昨天就没有 或者 昨天买入今天卖出
        dp[1][1] = max(dp[0][1], -prices[1])  # 昨天就有 或者 昨天没有而今天买入

        for i in range(2, n):
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i])
            dp[i][1] = max(dp[i-1][1], dp[i-2][0]-prices[i])    # 买入股票时注意冷冻期

        print(dp)
        return dp[-1][0]


x = Solution()
x.maxProfit([1,4,2,7])
