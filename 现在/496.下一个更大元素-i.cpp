/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */
#include "../common/debugger.h"

// @lc code=start


// 从后往前，单调递减栈；下一个更大就是当前top
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        map<int, int> mp;
        int n=nums2.size();
        for(int i=n-1; i>=0; i--) {
            while(!s.empty() && nums2[s.top()] < nums2[i]) {
                s.pop();
            }
            mp[nums2[i]] = s.empty() ? -1 : nums2[s.top()];
            s.push(i);
        }

        vector<int> res;
        for(int c : nums1) {
            res.push_back(mp[c]);
        }
        return res;
    }
};


// 将nums2每个元素下一个更大元素用map记录
// nums2建立单调栈
class SolutionCCC {
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
    p = {4,1,2}; q={1,3,4,2}; // -1 3 -1 
    r = Solution().nextGreaterElement(p, q);
    DebugVector(r);

    p = {2,4}; q={1,2,3,4}; // 3 -1 
    r = Solution().nextGreaterElement(p, q);
    DebugVector(r);
}

