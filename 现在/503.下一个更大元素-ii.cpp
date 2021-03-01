/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */
#include "../common/debugger.h"

// @lc code=start

// 从后往前，维护一个递减栈，那么对于当前位置i，下一个最大的元素就是当前top
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n);
        stack<int> st;

        for(int i=2*n-1; i>=0; i--) {
            while(!st.empty() && nums[st.top()] <= nums[i%n]) {
                st.pop();
            }
            res[i%n] = st.empty() ? -1 : nums[st.top()];
            st.push(i%n);
        }
        return res;
    }
};

// @lc code=end

int main() {
    vector<int> p, r;

    p={1,2,1}; // 2 -1 2
    r = Solution().nextGreaterElements(p);
    DebugVector(r);
}

