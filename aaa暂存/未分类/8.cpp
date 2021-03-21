#include "../common/debugger.h"
#include <climits>

class Solution {
public:
    int myAtoi(string str) {
        int iStart(0) ,ret(0);
        for(; iStart<str.length() && str[iStart]==' '; ++iStart);
        bool minus(false);
        if(str[iStart]=='+') {
            minus = false;
            ++iStart;
        } else if (str[iStart]=='-') {
            minus = true;
            ++iStart;
        }

        while(iStart < str.length()) {
            int cur = str[iStart] - '0';
            if(cur < 10 && cur >=0) {
                if(ret > INT_MAX/10 || (ret==INT_MAX/10 && cur>7)) {
                    return minus ? INT_MIN : INT_MAX;
                }
                ret *= 10;
                ret += cur;
            } else {
                break;
            }
            ++iStart;
        }

        return minus ? -ret : ret;
    }
};

int main() {
    Solution sol;
    cout << sol.myAtoi("   -91283472332") << endl;


    priority_queue<int, vector<int>, less<int>> q1;
    for(int i=0; i<4; ++i)
        q1.push(i);
    while(!q1.empty()) {
        cout << q1.top() << " ";
        q1.pop();
    }
    return 0;
}