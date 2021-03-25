/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */
#include "../common/debugger.h"

// 给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证 返回结果的字典序最小
// （要求不能打乱其他字符的相对位置）

// @lc code=start


// 要求字典序自增，就是栈内递增，遇到小的弹出

// vis代表栈中是否存在该字符，存在则不能加入
// num代表后面位置还是否存在，没有则不能弹出（存在才能弹出）
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> vis(26), num(26);
        for (char ch : s) {
            num[ch - 'a']++;
        }

        string stk;
        for (char ch : s) {
            if (!vis[ch - 'a']) {
                while (!stk.empty() && stk.back() > ch) {
                    if (num[stk.back() - 'a'] > 0) {
                        vis[stk.back() - 'a'] = 0;
                        stk.pop_back();
                    } else {
                        break;
                    }
                }
                vis[ch - 'a'] = 1;
                stk.push_back(ch);
            }
            num[ch - 'a'] -= 1;
        }
        return stk;
    }
};

// @lc code=end


int main() {
    LOG_DEBUG << Solution().removeDuplicateLetters("bcabc");
    LOG_DEBUG << Solution().removeDuplicateLetters("cbacdcbc");
}
