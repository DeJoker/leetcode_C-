/*
 * @lc app=leetcode.cn id=140 lang=cpp
 *
 * [140] 单词拆分 II
 */
#include "../common/debugger.h"

// @lc code=start
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> words{wordDict.begin(), wordDict.end()};

        int n=s.size();
        vector<bool> dp(n+1);
        dp[0] = true;
        for(int rg=1; rg<=n; rg++) {
            for(int lf=0; lf<rg; ++lf) {
                if (dp[lf]) {
                    if (words.find(s.substr(lf, rg-lf)) != words.end()) {
                        dp[rg] = true;
                        break;
                    }
                }
            }
        }

        vector<string> res;
        // s[0:len) 如果可以拆分成 wordSet 中的单词，把递归求解的结果加入 res 中
        std::function<void(int, vector<string>&)> backtack;
        backtack = [&](int len, vector<string>& path) {
            if (len == 0) {
                string tmp;
                for(auto it=path.rbegin(); it!=path.rend(); ++it) {
                    tmp += *it+" ";
                }
                tmp.pop_back();

                res.push_back(tmp);
                return;
            }

            for(int i=len-1; i>=0; i--) {
                string suf = s.substr(i, len-i);
                if (dp[i] && words.find(suf)!=words.end()) {
                    path.push_back(suf);
                    backtack(i, path); // 这里问什么是i不变，会导致死循环吗？
                    // 不会；因为迭代的起始不是i而是i-1   用i是因为和dp数组下标对应
                    path.pop_back();
                }

            }
        };

        if (dp[n]) {
            vector<string> path;
            backtack(n, path);
        }
        return res;
    }
};


// 纯回溯算法
class SolutionXX {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,vector<string> > m;
        return helper(m,wordDict,s);
    }
    vector<string> helper(unordered_map<string,vector<string> >& m,vector<string>& wordDict,string s){
        if(m.count(s)) return m[s];
        if(s.empty()) return {""};
        vector<string> res;
        for(auto word:wordDict){
            if(s.substr(0,word.size())!=word) continue;
            vector<string> tmp=helper(m,wordDict,s.substr(word.size()));
            for(auto itm:tmp){
                res.push_back(word+(itm.empty()?"":" "+itm));
            }
        }
        m[s]=res;
        return res;
    }
};


// @lc code=end

int main() {
    vector<string> r, dict;
    dict = {"apple", "pen", "applepen", "pine", "pineapple"};
    r = Solution().wordBreak("pineapplepenapple", dict);
    DebugVector(r);

    dict = {"cats", "dog", "sand", "and", "cat"};
    r = Solution().wordBreak("catsandog", dict);
    DebugVector(r);
}

