/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */
#include "../common/debugger.h"

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int last(nums.size()-1);

        int i=last-1;
        for (; i>0 && nums[i]>nums[i+1]; --i);

        int j(last);
        if (i!=0) {
            for(; j>i && nums[j]<nums[i]; --j);
            std::swap(nums[i], nums[j]);
        }

        for(int k=i+1, o=last; k<=o; ++k, --o) {
            std::swap(nums[k], nums[o]);
        }
    }
};
// @lc code=end

int main() {
    // vector<int> a{1,2,3};
    // for(int i=0; i<6; ++i) {
    //     Solution().nextPermutation(a);
    //     DebugVector( a );
    // }

    vector<int> a{3,2,1};
    Solution().nextPermutation(a);
    DebugVector( a );
}
