/*
 * @lc app=leetcode.cn id=65 lang=cpp
 *
 * [65] 有效数字
 */
#include "../common/debugger.h"

// 数字 小数点 e  +-

// 前导0问题

// @lc code=start


/*
 * 输入:
 *   0 : 空格
 *   1 : 数字
 *   2 : +/-
 *   3 : e
 *   4 : .
 *   5 : 其他
 * 状态：
 *   0 : 初始状态
 *   1 : 只有+/-
 *   2 : 合法整数
 *   3 : 指数等待输入指数部分
 *   4 : 指数部分等待输入数字
 *   5 : 合法指数
 *   6 : 小数待输入小数部分
 *   7 : 合法小数
 *   8 : 合法结束状态，可以输入空格.
 *   上述状态合法者，可以正确结束，否则以失败结束.
 */


// 用ascii画图也行  https://asciiflow.com/#/


//                                                    ┌───────────────────────────────────┐  
//    ┌─────────────────────────────┐                 ┌──────────────────│────────────────┐┌──────────────────────────┐
// 初始状态 ──────  符号位 ────── 整数部分  ────── 小数点【有整数】 ──────  小数部分 ────── 字符e ────── 指数符号 ────── 指数部分
//    │             │              └┘                │                     └┘                                         └┘
//    └ ───── 小数点【无整数部分】─────────────────────┘

// │── └┘┐┌
// <>v^


//  0 ms   5.9 MB
class Solution {

int fsm[9][6] = {
    {0, 2, 1, -1, 6, -1},
    {-1, 2, -1, -1, 6, -1},
    {8, 2, -1, 3, 7, -1},
    {-1, 5, 4, -1, -1, -1},
    {-1, 5, -1, -1, -1, -1},
    {8, 5, -1, -1, -1, -1},
    {-1, 7, -1, -1, -1, -1},
    {8, 7, -1, 3, -1, -1},
    {8, -1, -1, -1, -1, -1},
};

bool final[9] = {false, false, true, false, false, true, false, true, true,};

enum {
    BLANK=0,
    DIGIT=1,
    SIGN=2,
    E=3,
    DOT=4,
    OTHER=5, 
};

public:
int convertInput(char c) {
    switch (c) {
      case ' ':
        return 0;
      case '+':
      case '-':
        return 2;
      case 'e':
      case 'E':
        return 3;
      case '.':
        return 4;
      default:
        if (c >= '0' && c <= '9') {
          return 1;
        } else {
          return 5;
        }
    }
}

bool isNumber(string s) {
    if (s.empty()) {
      return true;
    }

    int cur_state = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
      int next_state = fsm[cur_state][convertInput(s[i])];
      if (next_state == -1) {
        return false;
      } else {
        cur_state = next_state;
      }
    }

    return final[cur_state];
}
};




class Solution333 {
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

