/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include "../common/debugger.h"

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left(0), right(0);
        int res(0);
        unordered_map<char, int> window;

        while(right < s.size()) {
            char a=s[right];
            ++window[a];
            ++right;
            // if (window.count(a)) {}

            // while (right-left == window.size()) { // 记得不能判断size因为减到0还会占用kv空间

            // 这里现在变成弹出非法值
            while (window[a] > 1) {
                char c = s[left];
                --window[c];
                ++left;
            }
            res = max(res, right-left);
        }
        return res;
    }
};
// @lc code=end

int main() {
    LOG_DEBUG << Solution().lengthOfLongestSubstring("abcabcbb");
    LOG_DEBUG << Solution().lengthOfLongestSubstring("bbbbb");
    LOG_DEBUG << Solution().lengthOfLongestSubstring("pwwkew");
    LOG_DEBUG << Solution().lengthOfLongestSubstring("");
}
