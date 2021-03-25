
#include "../common/debugger.h"

class Solution {
public:
    vector<int> dailyTemperatures(vector<int> T) {
        vector<int> res(T.size());
        stack<int> mono_st;
        // 单调递减栈  找的是比当前大的值， 比当前大的都出栈  保留刚好比自己大的值
        for(int i=T.size()-1; i>=0; --i) {
            while (!mono_st.empty() && T[mono_st.top()]<=T[i]) {
                mono_st.pop();
            }
            int diff = mono_st.empty() ? 0 : mono_st.top()-i;
            mono_st.push(i);
            res[i] = diff;
        }
        return res;
    }
};


int main() {
    Solution().dailyTemperatures({73,74,75,71,69,72,76,73});
}
