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

        int i(1), n=str.size();
        int value(-1); // 针对前导0的判断

        int curState;
        if (str[0]=='+' || str[0]=='-') {
            curState = 3;
        } else if (isdigit(str[0])) {
            curState = 0;
            value = str[0]!='0';
        } else if (str[0] == '.') {
            curState = 1;
        } else {
            return false;
        }



        // 有限状态机
        //  第一维度  curState当前所处状态
        //  第二维度  当前下标对应的类别（四种）
        static vector<vector<bool>> state = {
            {true, true, true, false},
            {true, false, false, false},
            {true, false, false, true},
            {true, true, false, false}, 
        };
        
        // 只有一位
        if (n==1 && curState != 0) {
            return false;
        }

        while(i<n) {
            if (isdigit(str[i])) {
                curState = 0;
                if (str[i]!='0') {
                    value = 1;
                } else if (value==-1) {
                    value = 0;
                }
            } else if (str[i]=='+' || str[i]=='-') {
                if (!state[curState][3]) {
                    return false;
                }
                curState = 3;
            } else if (str[i] == 'e' || str[i] == 'E') {
                if (!state[curState][2]) {
                    return false;
                } 
                if (value!=1) {
                    return false;
                }
                curState = 2;
                value = -1;
            } else if (str[i] == '.'){
                if (!state[curState][1]) {
                    return false;
                }
                curState = 1;
                value = -1;
            } else {
                return false;
            }

            ++i;
        }

        if (str.back() == 'e') {
            return false;
        }

        return true;
    }
};
// @lc code=end

int main() {
    LOG_DEBUG << Solution().isNumber("e"); // false


    LOG_DEBUG << Solution().isNumber("0"); // true
    LOG_DEBUG << Solution().isNumber(".1"); // true
    LOG_DEBUG << Solution().isNumber("-123.456e789"); // true
    LOG_DEBUG << Solution().isNumber("0089"); // true
    LOG_DEBUG << Solution().isNumber("-.9"); // true
    LOG_DEBUG << Solution().isNumber("53.5e93"); // true


    // // 未通过一下用例
    LOG_DEBUG << Solution().isNumber("."); // false

    LOG_DEBUG << Solution().isNumber("0e"); // false  前导0问题？？？
    // e要求前后都有值
    LOG_DEBUG << Solution().isNumber("5e"); // false
    // 只能有一个小数点？   1422/1488 cases passed (N/A)
    LOG_DEBUG << Solution().isNumber(".1."); // false
}

