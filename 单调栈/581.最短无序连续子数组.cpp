/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 */
#include "../common/debugger.h"

// @lc code=start



// 给你一个整数数组 nums ，你需要找出一个 连续子数组 ，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。
// [2,6,4,8,10,9,15]   output: 5 
// 只需要对 [6, 4, 8, 10, 9] 进行升序排序


// 选择排序的思想  我们需要找到无序子数组中最小元素和最大元素分别对应的正确位置，来求得我们想要的无序子数组的边界

// 正序遍历，递增栈，遇到小的弹出，弹出元素的位置一定不在正确位置上
// 逆序是反之亦然

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> st;
        int n=nums.size(), l=n, r=0;
        for(int i=0; i<n; i++) {
            while(!st.empty() && nums[st.top()] > nums[i]) {
                l = min(l, st.top()); st.pop();
            }
            st.push(i);
        }
        st = stack<int>();

        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && nums[st.top()] < nums[i]) {
                r = max(r, st.top()); st.pop();
            }
            st.push(i);
        }
        return r-l>0 ? r-l+1 : 0;

    }
};

class SolutionWrng {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start=-1, end=-1;
        int sv=INT_MAX, ev=INT_MIN;

        stack<int> st;
        for(int i=0; i<nums.size(); i++) {
            while(!st.empty() && nums[st.top()] > nums[i]) {
                if (start == -1) {
                    start = i; 
                }
                end = i;
                st.pop();
            }
            st.push(i);
        }
        return end-start+1;
    }
};


// public class Solution {
//     public int findUnsortedSubarray(int[] nums) {
//         Stack < Integer > stack = new Stack < Integer > ();
//         int l = nums.length, r = 0;
//         for (int i = 0; i < nums.length; i++) {
//             while (!stack.isEmpty() && nums[stack.peek()] > nums[i])
//                 l = Math.min(l, stack.pop());
//             stack.push(i);
//         }
//         stack.clear();
//         for (int i = nums.length - 1; i >= 0; i--) {
//             while (!stack.isEmpty() && nums[stack.peek()] < nums[i])
//                 r = Math.max(r, stack.pop());
//             stack.push(i);
//         }
//         return r - l > 0 ? r - l + 1 : 0;
//     }
// }


// @lc code=end


int main() {
    vector<int> p;
    p = {2,6,4,8,10,9,15};
    LOG_DEBUG << Solution().findUnsortedSubarray(p); // 5
    p = {1,2,3,4};
    LOG_DEBUG << Solution().findUnsortedSubarray(p); // 0
    p = {1};
    LOG_DEBUG << Solution().findUnsortedSubarray(p); // 0
    p = {1,2,3,4,1};
    LOG_DEBUG << Solution().findUnsortedSubarray(p); // 4
    
}
