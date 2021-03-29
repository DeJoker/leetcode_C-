/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */
#include "../common/debugger.h"

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        int len(1);
        set<int> setNum = { nums.begin(), nums.end() };
        for(auto it=setNum.begin(); it!=setNum.end(); ) {
            int tmp(1);
            auto cur = it; ++it;
            while(it!=setNum.end() && (*cur)+1 == *it) {
                ++tmp;
                cur = it; ++it;
            }
            len = max(len, tmp);
        }
        return len;
    }
};
// @lc code=end

int main() {
    vector<int> p;
    p = {100,4,200,1,3,2};
    LOG_DEBUG << Solution().longestConsecutive(p);

    p = {0,3,7,2,5,8,4,6,0,1};
    LOG_DEBUG << Solution().longestConsecutive(p);

}

