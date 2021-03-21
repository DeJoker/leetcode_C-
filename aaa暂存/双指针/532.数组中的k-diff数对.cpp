/*
 * @lc app=leetcode.cn id=532 lang=cpp
 *
 * [532] 数组中的K-diff数对
 */

#include "../common/debugger.h"

// @lc code=start

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n=nums.size(), res(0);
        int i=0, j=i+1;
        while(j<n) {
            int diff=nums[j]-nums[i];
            if (diff > k) {
                ++i;
                j=i+1;
            } else if (diff < k) {
                ++j;
            } else {
                if (i==0 || nums[i]!=nums[i-1])
                    ++res;
                ++i, j=i+1;
            }
        }
        return res;
    }
};
// @lc code=end

int main() {
    vector<int> aa({3,1,4,1,5});
    cout << Solution().findPairs(aa, 2) << endl;
}

