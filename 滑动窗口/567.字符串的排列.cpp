/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */
#include "../common/debugger.h"

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int left(0), right(0);
        unordered_map<char, int> window, need;
        for(auto c : s1) {
            need[c]++;
        }

        int match(0);
        while (right < s2.size()) {
            char a=s2[right];
            ++right;
            if (need.count(a)) {
                ++window[a];
                if (need[a] == window[a])
                    ++match;
            }

            while (match==need.size()) {
                if (right-left == s1.size()) {
                    return true;
                }
                char c = s2[left];
                if (need.count(c)) {
                    --window[c];
                    if (window[c] < need[c])
                        --match;
                }
                ++left;
            }
        }

        return false;
    }
};
// @lc code=end

int main() {
    LOG_DEBUG << Solution().checkInclusion("ab", "eidbaooo");
    LOG_DEBUG << Solution().checkInclusion("ab", "eidboaoo");
    LOG_DEBUG << Solution().checkInclusion("ky", "ainwkckifykxlribaypk");
}
