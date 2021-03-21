/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
#include "../common/debugger.h"

// @lc code=start

// count 只返回0和1
// equal_range 么有实际含义 这对multi_map才返回范围，这里只返回唯一元素
// https://blog.csdn.net/qq_37264095/article/details/103730879
// https://blog.csdn.net/ZZS_SZZ/article/details/114193454


class Solution {
public:
    string minWindow(string s, string t) {
        int left(0), right(0);
        unordered_map<char, int> window, need;
        for(auto c : t) {
            need[c]++;
        }

        int match(0);
        int minLen(INT_MAX), start(INT_MAX);
        while(right < s.size()) {
            char a = s[right];
            if (need.count(a)) {  // 只插入need中的值
                ++window[a];
                if(need[a] == window[a]) {
                    ++match;
                }
            }
            ++right; // right应该先加，这里涉及到长度的问题

            while (match==need.size()) {
                if (minLen > right-left) {
                    minLen = right-left;
                    start = left;
                }
                auto c = s[left];
                if (need.count(c)) {
                    --window[c];
                    // if (need.count(c) > window.count(c)) {
                    if (need[c] > window[c]) {
                        match--;
                    }
                }
                ++left;
            }
        }
        return minLen==INT_MAX ? "" : s.substr(start, minLen);
    }
};
// @lc code=end


int main() {
    LOG_DEBUG << Solution().minWindow("ADOBECODEBANC", "ABC");
    LOG_DEBUG << Solution().minWindow("a", "a");
}
