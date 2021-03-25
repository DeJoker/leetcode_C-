/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
#include "../common/debugger.h"

// @lc code=start
// 弹出一个，然后跟栈内的比；栈内递减
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int res(0);
        for(int i=0; i<height.size(); i++) {
            while(!st.empty() && height[st.top()] < height[i]) {
                int t=st.top(); st.pop();
                if (st.empty()) break;

                int dis = i-st.top()-1;
                res += (min(height[i], height[st.top()])-height[t])*dis;
            }
            st.push(i);
        }
        return res;
    }
};
// @lc code=end

int main() {
    vector<int> p;
    p = {0,1,0,2,1,0,1,3,2,1,2,1};
    LOG_DEBUG << Solution().trap(p);
    p = {2,1,2};
    LOG_DEBUG << Solution().trap(p);
}

