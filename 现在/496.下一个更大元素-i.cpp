/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */
#include "../common/debugger.h"

// @lc code=start


// 将nums2每个元素下一个更大元素用map记录
// nums2建立单调栈，
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        map<int, int> mp;
        for(int i=0; i<nums2.size(); i++) {
            while(!s.empty() && nums2[s.top()] < nums2[i]) {
                int t=s.top(); s.pop();
                mp[nums2[t]] = nums2[i];
            }
            s.push(i);
        }
        while(!s.empty()) {
            mp[nums2[s.top()]] = -1;
            s.pop();
        }

        vector<int> res;
        for(int c : nums1) {
            res.push_back(mp[c]);
        }
        return res;
    }
};
// @lc code=end

int main() {
    vector<int> p, q, r;
    p = {4,1,2}; q={1,3,4,2};
    r = Solution().nextGreaterElement(p, q);
    DebugVector(r);

    p = {2,4}; q={1,2,3,4};
    r = Solution().nextGreaterElement(p, q);
    DebugVector(r);
}

