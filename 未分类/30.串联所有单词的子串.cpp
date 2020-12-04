/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

#include "../common/debugger.h"

// 第一，没有移动i指针      没写+= word.size()
// 插入值错误，内部循环应该有一个下标，实际插入应该是i，而向前移动应该是k
// 没有考虑vector中可能有重复元素就放入set，应该用map

// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string& s, vector<string>& words) {
        vector<int> res;
        int len(0);
        for(int i=0; i<words.size(); ++i) {
            len += words[i].size();
        }
        if (s.size() < len) {
            return res;
        }

        for(int i=0; i+len<s.size(); ++i) {
            bool match(false);
            set<string> pattern = {words.begin(), words.end()};
            int k(i);
            do {
                match = false;
                for(auto& word : pattern) {
                    if (s.substr(k, word.size()) == word) {
                        match = true;
                        pattern.erase(word);
                        k += word.size();
                        break;
                    }
                }
            } while(match && !pattern.empty());
            if (match) {
                res.push_back(i);
            }
        }

        return res;
    }
};
// @lc code=end


int main() {
    string s("barfoothefoobarman");
    vector<string> vec = {"foo","bar"};
    DebugVector( Solution().findSubstring(s, vec) );
}
