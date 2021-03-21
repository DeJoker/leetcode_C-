/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */
#include "../common/debugger.h"

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int left(0), right(0);
        unordered_map<char, int> window, need;
        for(auto& c : p) {
            need[c]++;
        }

        vector<int> res;
        int match(0);
        while(right < s.size()) {
            char a=s[right];
            ++right;
            if (need.count(a)) {
                ++window[a];
                if (need[a]==window[a]) 
                    ++match;
            }

            while(match == need.size()) {
                if (right-left == p.size()) {
                    res.push_back(left);
                }
                char c = s[left];
                if (need.count(c)) {
                    --window[c];
                    if (need[c] > window[c]) {
                        --match;
                    }
                }
                ++left;
            }
        }
        return res;
    }
};
// @lc code=end

int main() {
    vector<int> r;
    
    r = Solution().findAnagrams("cbaebabacd", "abc");
    DebugVector(r);
    r = Solution().findAnagrams("abab", "ab");
    DebugVector(r);
}
