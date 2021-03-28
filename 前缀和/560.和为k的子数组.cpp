/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
 */
#include "../common/debugger.h"

// @lc code=start

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if (nums.empty()) return 0;

        map<int, int> mp; // preSum -> sumCount
        mp[0] = 1;
        int preSum(0), res(0);

        for(int i=0; i<nums.size(); i++) {
            preSum += nums[i];
            if (mp.find(preSum-k) != mp.end()) {
                res += mp[preSum-k];
            }
            mp[preSum] = mp[preSum]+1;
        }
        return res;
    }
};

class Solution33 {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> mp; // preSum -> position

        int preSum(0), res(0);
        for(int i=0; i<nums.size(); i++) {
            preSum += nums[i];
            if (mp.find(k-nums[i]) != mp.end()) {
                res++;
            }
            mp[preSum] = i;
        }
        return res;
    }
};

// @lc code=end

int main() {
    vector<int> p;
    p = {1,1,1,};
    // LOG_DEBUG << Solution().subarraySum(p, 2); // 2
    p = {1,2,3,};
    LOG_DEBUG << Solution().subarraySum(p, 3); // 2

    p = {1,2,1,2,1};
    LOG_DEBUG << Solution().subarraySum(p, 3); // 4
}
