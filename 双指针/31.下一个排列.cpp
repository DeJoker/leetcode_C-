/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */
#include "../common/debugger.h"

// @lc code=start
class Solution {
public:
    // 目的是找下一个较大数，刚好比现在排列大（如果最大找最小）

    // 两边扫描
    // 先从后往前找变小的数（后往前应该是递增的）
    // 再后往前找刚好比这个数大一点的数
    // 找到两数后交换再逆序
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i=n-2;
        while(i>=0 && nums[i]>=nums[i+1]) {
            i--;
        }
        if (i>=0) {
            int j=n-1;
            while(j>=0 && nums[i]>=nums[j]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        std::reverse(nums.begin()+i+1, nums.end());
    }
};
// @lc code=end

int main() {
    vector<int> p;
    p = {1,2,3};
    Solution().nextPermutation(p);
    DebugVector(p);

    p = {3,2,1};
    Solution().nextPermutation(p);
    DebugVector(p);

    p = {1};
    Solution().nextPermutation(p);
    DebugVector(p);
}

