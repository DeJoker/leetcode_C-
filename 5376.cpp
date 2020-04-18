#include "common/debugger.h"

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int leftsum(0),rightsum(0);
        int mid(nums.size()/2);
        for(int i=0; i<mid; ++i) {
            leftsum += nums[i];
        }
        for(int i=mid; i<nums.size(); ++i) {
            rightsum += nums[i];
        }

        vector<int> ret;
        while(leftsum < rightsum) {
            leftsum += nums[mid];
            rightsum -= nums[mid];
            ++mid;
        }

        // ret = {nums.rbegin(), nums.rbegin()+mid-2};
        ret = {nums.begin()+mid-1, nums.end()};
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

int main() {
    Solution sol;
    // vector<int> vec = {4,4,7,6,7};
    vector<int> vec = {4};
    auto aa = sol.minSubsequence(vec);
    DebugVecor(aa);
}
