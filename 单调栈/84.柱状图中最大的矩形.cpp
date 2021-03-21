/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */
#include "../common/debugger.h"

// @lc code=start


// 栈内递增
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // if (heights.empty()) return 0;
        heights.insert(heights.begin(), -1);
        heights.push_back(-1); // 需要所有数据最后都出栈

        stack<int> s;
        int res(0);
        for(int i=0; i<heights.size(); i++) {
            while(!s.empty() && heights[s.top()] > heights[i]) {
                int t=s.top(); s.pop();
                res = max(res, (i-s.top()-1)*heights[t]);
            }
            s.push(i);
        }
        return res;
    }
};


// @lc code=end


int largestRectangleArea(vector<int>& heights)
{
    int ans = 0;
    vector<int> st;
    heights.insert(heights.begin(), 0);
    heights.push_back(0);
    for (int i = 0; i < heights.size(); i++)
    {
        while (!st.empty() && heights[st.back()] > heights[i])
        {
            int cur = st.back();
            st.pop_back();
            int left = st.back() + 1;
            int right = i - 1;
            // i-st.back()-1;
            ans = max(ans, (right - left + 1) * heights[cur]);
        }
        st.push_back(i);
    }
    return ans;
}

// 再次强调栈中现在为单调递增
// 这里修改了原数组，不只是追加
class Solution222 {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(-1);
        stack<int> st;
        int ret = 0, top;
        for (int i = 0; i < heights.size(); i++)
        {
            if (st.empty() || heights[st.top()] <= heights[i])
            {
                st.push(i);
            }
            else
            {
                while (!st.empty() && heights[st.top()] > heights[i])
                {
                    top = st.top();
                    st.pop();
                    //i-top指的是当前矩形的宽度，heights[top]就是当前的高度
                    ret = max(ret, (i - top)*heights[top]);
                }
                st.push(top);
                heights[top] = heights[i];
            }
        }
        return ret;
    }
};


int main() {
    vector<int> p;
    p = {2,1,5,6,7,8,2,3}; // 20
    LOG_DEBUG << Solution().largestRectangleArea(p);
    p = {2,1,2}; // 3
    LOG_DEBUG << Solution().largestRectangleArea(p);
}

