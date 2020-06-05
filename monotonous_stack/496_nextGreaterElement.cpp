#include "../common/debugger.h"

class Solution {
public:
// 既然是子集，那我们只用管理好nums2，然后用查找的方法找到数值即可
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        map<int, int> aMap;
        for(const auto& ele : nums2) {
            while(!st.empty() && st.top()<ele) {
                aMap[st.top()] = ele;
                st.pop();
            }
            st.emplace(ele);
        }

        while(!st.empty()) {
            aMap[st.top()] = -1;
            st.pop();
        }

        vector<int> res;
        for(auto num1 : nums1) {
            res.push_back(aMap[num1]);
        }
        return res;
    }
};


int main() {
    vector<int> num1{4,1,2}, num2{1,3,4,2};
    Solution().nextGreaterElement(num1, num2);
    
}
