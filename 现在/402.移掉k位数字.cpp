/*
 * @lc app=leetcode.cn id=402 lang=cpp
 *
 * [402] 移掉K位数字
 */
#include "../common/debugger.h"

// @lc code=start

// 递增栈
class Solution {
public:
    string removeKdigits(string num, int k) {
        // stack<char> st;
        vector<char> st;
        for(int i=0; i<num.size(); i++) {
            while(!st.empty() && st.back() > num[i] && k) {
                st.pop_back();
                --k;
            }
            st.push_back(num[i]);
        }
        while(k && !st.empty()) {
            st.pop_back();
            --k;
        }

        auto it = st.begin();
        while(it!=st.end() && *it == '0') ++it;

        if (it==st.end()) return "0";
        return string(it, st.end());
    }
};
// @lc code=end

int main() {
    LOG_DEBUG << Solution().removeKdigits("1432219", 3);
    LOG_DEBUG << Solution().removeKdigits("10200", 1);
    LOG_DEBUG << Solution().removeKdigits("10", 2);
    LOG_DEBUG << Solution().removeKdigits("9", 1);
    LOG_DEBUG << Solution().removeKdigits("19", 1);
}