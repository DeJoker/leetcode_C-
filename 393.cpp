#include "common/debugger.h"

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        vector<int> utfState = {1<<7, 1<<6, 1<<5, 1<<4};
        auto iter = data.begin();
        while(iter != data.end()) {
            int cur = *iter;
            if (cur > 255) {
                return false;
            }
            int count(0);
            // 
            while(count<utfState.size() && cur&utfState[count]) ++count;
            // 1111 0
            if ((count==utfState.size() && cur&(1<<3)) || count == 1)
                return false;
            if(count > 1)
                --count;

            while(count) {
                ++iter;
                if (iter == data.end())
                    return false;
                if( (((*iter)>>6) & 0x03) != 0x02 )
                    return false;
                --count;
            }
            ++iter;
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<int> vec = {235, 140, 4};
    cout << sol.validUtf8(vec);
}
