/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 */
#include "../common/debugger.h"

// @lc code=start
class Solution333 {
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

// @lc code=end


int main() {
    vector<int> p;
    p = {2,6,4,8,10,9,15};
    LOG_DEBUG << Solution().findUnsortedSubarray(p);
    p = {1,2,3,4};
    LOG_DEBUG << Solution().findUnsortedSubarray(p);
    p = {1};
    LOG_DEBUG << Solution().findUnsortedSubarray(p);
    p = {1,2,3,4,1};
    LOG_DEBUG << Solution().findUnsortedSubarray(p);
    
}
