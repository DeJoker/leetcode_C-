/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

#include "../common/debugger.h"
// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        int pos(0), n(s.size());
        for (; pos<n && s[pos]==' '; ++pos);

        bool posit;
        if ((s[pos]>='0' && s[pos]<='9') || s[pos]=='+') {
            posit = true;
            if (s[pos]=='+') ++pos;
        } else if (s[pos]=='-') {
            posit = false;
            ++pos;
        } else {
            return 0;
        }

        int64_t res(0);
        while (s[pos]>='0' && s[pos]<='9') {
            res *= 10;
            res += s[pos]-'0';
            if (res > INT_MAX) {
                if (posit) {
                    return INT_MAX;
                }
                return INT_MIN;
            } 
            ++pos;
        }

        return posit ? res : -res;
    }
};
// @lc code=end

int main() {
    LOG_DEBUG << Solution().myAtoi("42");
    LOG_DEBUG << Solution().myAtoi("   -42");
    LOG_DEBUG << Solution().myAtoi("4193 with words");
    LOG_DEBUG << Solution().myAtoi(" with words 99");
    LOG_DEBUG << Solution().myAtoi("-91283472332");

}

