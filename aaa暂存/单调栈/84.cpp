
#include "../common/debugger.h"

class Solution {
public:
    int largestRectangleArea(vector<int> heights) {
        int n = heights.size();
        // 左向右遍历，找到左边起第一个比当前数字小的元素：left  右向左遍历，右边起比当前数字小的元素：right
        vector<int> left(n), right(n);

        stack<int> mono_st;
        // 递增栈得到的是小的第一个值
        for(int i=0; i<n; ++i) {
            // 单调递增栈（比我高的值都弹出我再插入我就是最高的），弹出过于大的值，所以保留下刚好比当前小的
            while (!mono_st.empty() && heights[mono_st.top()]>=heights[i]) {
                mono_st.pop();
            }
            // 哨兵
            left[i] = mono_st.empty() ? -1 : mono_st.top();
            mono_st.push(i);
            cout << n ;
        }

        mono_st = stack<int>{};
        for(int i=n-1; i>=0; --i) {
            while (!mono_st.empty() && heights[mono_st.top()]>=heights[i]) {
                mono_st.pop();
            }
            right[i] = mono_st.empty() ? n : mono_st.top();
            mono_st.push(i);
        }

        int ans(0);
        for(int i=0; i<n; ++i) {
            ans = max(ans, (right[i]-left[i]-1)*heights[i]);
        }
        return ans;
    }
};

int main() {
    Solution().largestRectangleArea({2,1,5,6,2,3});
}