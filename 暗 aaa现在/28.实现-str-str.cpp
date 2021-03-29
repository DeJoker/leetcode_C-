/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */
#include "../common/debugger.h"

// @lc code=start
class Solution {

    void getNext(vector<int>& next, const string& str) {
        int k=-1;
        next[0] = -1;

        // 从第二个字符开始才有前缀后，因此i=1开始
        for(int i=1; i<str.size(); i++) {
            while (k>=0 && str[i]!=str[k+1]) { // 前后缀不同时向前回溯
                k = next[k]; // 向前回溯
            }
            if (str[i] == str[k+1]) { // 找到相同的前后缀
                ++k;
            }
            next[i] = k;
        }
    }
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
            
        vector<int> next(needle.size());
        getNext(next, needle);

        // 因为next数组里记录的起始位置为-1
        int j = -1;
        for (int i = 0; i < haystack.size(); i++) {
            // 不匹配寻找之前匹配的位置
            while(j >= 0 && haystack[i] != needle[j + 1]) { 
                j = next[j];
            }
            if (haystack[i] == needle[j + 1]) { // 匹配，两指针向后移动
                j++;
            }

            // 匹配成功
            if (j == (needle.size() - 1) ) {
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
};
// @lc code=end


int main() {
    LOG_DEBUG << Solution().strStr("hello", "ll");
    LOG_DEBUG << Solution().strStr("aaaaa", "bba");
}
