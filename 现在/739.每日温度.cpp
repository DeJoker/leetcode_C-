/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */
#include "../common/debugger.h"

// @lc code=start

// 递减
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> s;
        vector<int> res(T.size());
        for(int i=0; i<T.size(); i++) {
            while(!s.empty() && T[s.top()] < T[i]) {
                res[s.top()] = i-s.top();
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()) {
            res[s.top()] = 0;
            s.pop();
        }
        return res;
    }
};
// @lc code=end

int main() {
    vector<int> p,  r;
    p = {73, 74, 75, 71, 69, 72, 76, 73};
    r = Solution().dailyTemperatures(p);
    DebugVector(r);

}
