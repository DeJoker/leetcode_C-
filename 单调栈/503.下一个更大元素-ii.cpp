/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */
#include "../common/debugger.h"

// @lc code=start

// 针对循环数组一定要记得特殊处理（所有元素初始化为异常值，循环中没有赋值的就认为是异常）
// 不要再最后while弹出所有元素！！！！
class Solution {
public:
    // 递减栈，遇到大的就是下一个更大
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n, -1); // 初始化为-1，如果没填对应值就代表没有下一个更大
        
        stack<int> st;
        for(int i=0; i<2*n; i++) { // 为什么这里只拼接n-1个元素？？？
            while(!st.empty() && nums[st.top()] < nums[i%n]) {
                res[st.top()] = nums[i%n];
                st.pop();
            }
            st.push(i%n);
        }
        return res;
    }
};


class SolutionWrong {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n);
        
        stack<int> st;
        // 无论是2n还是2n-1 都会有样例出错，正常应该只有双数个（必然有元素没有更大的）
        // 遍历两次相同下标所以是双数，但有的样例是单数
        // 因为最末端元素必然被push进去的
        for(int i=0; i<2*n; i++) {
            while(!st.empty() && nums[st.top()] < nums[i%n]) {
                res[st.top()] = nums[i%n];
                st.pop();
            }
            st.push(i%n);
        }

        while(!st.empty()) {
            res[st.top()] = -1;
            st.pop();
        }
        return res;
    }
};



// 逆序遍历出处
// https://leetcode-cn.com/problems/next-greater-element-ii/solution/dan-diao-zhan-jie-jue-next-greater-number-yi-lei-2/
// 从后往前，维护一个递减栈，那么对于当前位置i，下一个最大的元素就是当前top
class SolutionReverse {
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

    p={1,2,3,4,3}; // 2,3,4,-1,4
    r = Solution().nextGreaterElements(p);
    DebugVector(r);

    p={1,2,3,4,5}; // 2,3,4,5,-1
    r = Solution().nextGreaterElements(p);
    DebugVector(r);
}

