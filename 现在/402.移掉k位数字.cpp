#include "../common/debugger.h"
/*
 * @lc app=leetcode.cn id=402 lang=cpp
 *
 * [402] 移掉K位数字
 */

// @lc code=start
class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;
        stack<char> st;
        st.push(num[0]);
        int i=1;
        while(i<num.size()) {
            if (num[i] > st.top() && k>0) {
                --k;
            } else {
                st.push(num[i]);
            }
            i++;
        }

        // 忽略了k最后一定要为0
        

        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        std::reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

