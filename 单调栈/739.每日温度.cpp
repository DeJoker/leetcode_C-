/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */
#include "../common/debugger.h"

// @lc code=start


// 要想观测到更高的气温，至少需要等待的天数。如果气温在这之后都不会升高，请在该位置用 0 来代替
// 遇到更大的就弹出并算举例、递减栈
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> st;
        vector<int> res(T.size());
        for(int i=0; i<T.size(); i++) {
            while(!st.empty() && T[st.top()] < T[i]) {
                res[st.top()] = i-st.top();
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()) {
            res[st.top()] = 0;
            st.pop();
        }
        return res;
    }
};
// @lc code=end

int main() {
    vector<int> p,  r;
    p = {73, 74, 75, 71, 69, 72, 76, 73};
    r = Solution().dailyTemperatures(p);
    DebugVector(r);

}
