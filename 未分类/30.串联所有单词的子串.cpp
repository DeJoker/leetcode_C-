/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

#include "../common/debugger.h"

// 第一，没有移动i指针      没写+= word.size()
// 插入值错误，内部循环应该有一个下标，实际插入应该是i，而向前移动应该是k
// 没有考虑vector中可能有重复元素就放入set，应该用map
// <= 的边界条件   因为加了长度， 0+长度就是末尾
// 都用map了为什么不上搜索？？


// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string& s, vector<string>& words) {
        vector<int> res;
        int len(0);
        map<string, int> patternWord;
        for(int i=0; i<words.size(); ++i) {
            len += words[i].size();
            patternWord[words[i]]++;
        }
        if (s.size() < len) {
            return res;
        }

        for(int i=0; i+len<=s.size(); ++i) { // 这里为什么是<=
            bool match(false);
            map<string, int> pattern(patternWord);
            int k(i);
            do {
                match = false;
                for(auto& [word,cnt] : pattern) {
                    if (s.substr(k, word.size()) == word) {
                        match = true;
                        pattern[word]--;
                        if (pattern[word] == 0) {
                            pattern.erase(word);
                        }
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
    // string s("barfoothefoobarman");
    // vector<string> vec = {"foo","bar"};

    string s("wordgoodgoodgoodbestword");
    vector<string> vec = {"word","good","best","good"};
    DebugVector( Solution().findSubstring(s, vec) );
}
