/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
#include "../common/debugger.h"

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char, string> mp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
        };

        int n=digits.size();
        if (n==0) return {};
        vector<string> res;

        std::function<void(int, string&)> backtack;
        backtack = [&](int i, string& path) {
            if (path.size()==n) {
                res.push_back(path);
                return;
            }

            for(; i<n; i++) {
                for(auto c : mp[digits[i]]) {
                    path.push_back(c);
                    backtack(i+1, path);
                    path.pop_back();
                }
            }
        };
        
        string p;
        backtack(0, p);
        return res;
    }
};

class SolutionXXX {
public:
    vector<string> letterCombinations(string digits) {
        map<char, string> mp = {
            {'2', "abc"},
            {'3', "def"},
        };

        int n=digits.size();
        if (n==0) return {};
        vector<string> res;

        std::function<void(int, string&)> backtack;
        backtack = [&](int i, string& path) {
            if (i==n) {
                res.push_back(path);
                return;
            }

            for(int i=0; i<=n; i++) {
                for(auto c : mp[digits[i]]) {
                    path.push_back(c);
                    backtack(i, path);
                    path.pop_back();
                }
            }
        };
        
        string p;
        backtack(0, p);
        return res;
    }
};
// @lc code=end

int main() {
    vector<string> r;
    r = Solution().letterCombinations("23");
    DebugVector(r);
    r = Solution().letterCombinations("");
    DebugVector(r);
}


