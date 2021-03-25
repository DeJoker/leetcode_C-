/*
 * @lc app=leetcode.cn id=517 lang=cpp
 *
 * [517] 超级洗衣机
 */
#include "../common/debugger.h"

// @lc code=start
class Solution {
public:
    int findMinMoves(vector<int>& machines) {

    }
};
// @lc code=end


// m：当前位置的数值；
// curr_sum：到当前位置为止的前缀和；
// max_sum：到当前位置为止的前缀和的绝对值的最大值。

// class Solution:
//     def findMinMoves(self, machines: List[int]) -> int:
//         n = len(machines)
//         dress_total = sum(machines)
//         if dress_total % n != 0:
//             return -1
        
//         dress_per_machine = dress_total // n
//         for i in range(n):
//             # Change the number of dresses in the machines to
//             # the number of dresses to be removed from this machine
//             # (could be negative)
//             machines[i] -= dress_per_machine
            
//         # curr_sum is a number of dresses to move at this point, 
//         # max_sum is a max number of dresses to move at this point or before,
//         # m is number of dresses to move out from the current machine.
//         curr_sum = max_sum = res = 0
//         for m in machines:
//             curr_sum += m
//             max_sum = max(max_sum, abs(curr_sum))
//             res = max(res, max_sum, m)
//         return res


