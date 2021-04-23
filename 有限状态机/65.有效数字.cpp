/*
 * @lc app=leetcode.cn id=65 lang=cpp
 *
 * [65] 有效数字
 */
#include "../common/debugger.h"

// 数字 小数点 e  +-

// 前导0问题

// @lc code=start
class Solution {
public:
    bool isNumber(string str) {
        if (str.empty()) return false;

        int curState;
        if (str[0]=='+' || str[0]=='-') {
            curState = 3;
        } else if (isdigit(str[0])) {
            curState = 0;
        } else if (str[0] == '.') {
            curState = 1;
        } else {
            return false;
        }

        int i(1), n=str.size();
        // 有限状态机
        //  第一维度  curState当前所处状态
        //  第二维度  当前下标对应的类别（四种）
        vector<vector<bool>> state = {
            {true, true, true, false},
            {true, false, false, false},
            {true, false, false, true},
            {true, true, false, false}, 
        };

        while(i<n) {
            if (isdigit(str[i])) {
                curState = 0;
            } else if (str[i]=='+' || str[i]=='-') {
                if (!state[curState][3]) {
                    return false;
                }
                curState = 3;
            } else if (str[i] == 'e' || str[i] == 'E') {
                if (!state[curState][2]) {
                    return false;
                }
                curState = 2;
            } else if (str[i] == '.'){
                if (!state[curState][1]) {
                    return false;
                }
                curState = 1;
            } else {
                return false;
            }

            ++i;
        }

        return true;
    }
};
// @lc code=end

int main() {
    LOG_DEBUG << Solution().isNumber("e"); // false

    
    LOG_DEBUG << Solution().isNumber("0"); // true
    LOG_DEBUG << Solution().isNumber("."); // true
    LOG_DEBUG << Solution().isNumber(".1"); // true
    LOG_DEBUG << Solution().isNumber("-123.456e789"); // true
    LOG_DEBUG << Solution().isNumber("0089"); // true
    LOG_DEBUG << Solution().isNumber("-.9"); // true
    LOG_DEBUG << Solution().isNumber("53.5e93"); // true
}

