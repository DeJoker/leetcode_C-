/*
 * @lc app=leetcode.cn id=301 lang=cpp
 *
 * [301] 删除无效的括号
 */

#include "../common/debugger.h"

// @lc code=start
class Solution33 {
public:
    set<string> _expressions;
    int _minRemove = INT_MAX;

    void Recurse(const string& s, int idx, 
            int left, int right,
            string curExpr, int remove)
    {
        if (idx == s.size()) {
            if (left == right) {
                if (remove <= _minRemove) {
                    if (remove < _minRemove) {
                        _expressions.clear();
                        _minRemove = remove;
                    }
                    _expressions.insert(curExpr);
                }
            }
            return;
        } 

        char c = s[idx];
        int len = curExpr.length();

        if (c!='(' && c!=')') {
            curExpr.push_back(c);
            Recurse(s, idx+1, left, right, curExpr, remove);
            // curExpr.replace(len, 1, "");
            curExpr.pop_back();
        } else {

            // 认为无效
            Recurse(s, idx+1, left, right, curExpr, remove+1);

            curExpr.push_back(c);
            // 认为有效
            if (c == '(') {
                Recurse(s, idx+1, left+1, right, curExpr, remove);
            } else if (right < left) {
                Recurse(s, idx+1, left, right+1, curExpr, remove);
            }

            curExpr.pop_back();
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        Recurse(s, 0, 0, 0, "", 0);
        return vector<string> {_expressions.begin(), _expressions.end()};
    }
};


class Solution {
public:
    set<string> _exprs;

    void Recurse(const string& s, int idx, string curExpr,
                    int left, int right,
                    int leftRemove, int rightRemove)
    {
        if (idx == s.size()) {
            if (leftRemove == 0 && rightRemove == 0) {
                _exprs.insert(curExpr);
            }
            return;
        }

        char c = s[idx];
        int len = curExpr.length();

        // 这里就是剪枝的地方
        if ((c=='(' && leftRemove>0) || (c==')' && rightRemove>0)) {
            Recurse(s, idx+1, curExpr, left, right, 
                    leftRemove - (c=='(' ? 1 : 0),
                    rightRemove - (c==')' ? 1 : 0)
            );
        }

        curExpr.push_back(c);

        if (c!='(' && c!=')') {
            Recurse(s, idx+1, curExpr, left, right, leftRemove, rightRemove);
        } else {
            if (c=='(') {
                Recurse(s, idx+1, curExpr, left+1, right, leftRemove, rightRemove);
            } else if (right < left) {
                Recurse(s, idx+1, curExpr, left, right+1, leftRemove, rightRemove);
            }
        }

        curExpr.pop_back();
    }

    vector<string> removeInvalidParentheses(string s) {
        int leftR(0), rightR(0);
        for(int i=0; i<s.length(); i++) {
            if (s[i] == '(') {
                ++leftR;
            } else if (s[i] == ')') {
                if (left == 0)   ++rightR;
                else --leftR;
            }
        }
        Recurse(s, 0, "", 0, 0, leftR, rightR);
        return {_exprs.begin(), _exprs.end()};
    }
};

// @lc code=end

int main() {
    DebugVector( Solution().removeInvalidParentheses("()())()") );
}