/*
 * @lc app=leetcode.cn id=301 lang=cpp
 *
 * [301] 删除无效的括号
 */

#include "../common/debugger.h"

// @lc code=start
class Solution {
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
                    _expressions.clear();
                    _minRemove = remove;
                }
                _expressions.insert(curExpr);
            }
            return;
        } 

        char c = s[idx];
        int len = curExpr.length();
        if (c!='(' && c!=')') {
            curExpr.push_back(c);
            Recurse(s, idx+1, left, right, curExpr, remove);
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

// @lc code=end

