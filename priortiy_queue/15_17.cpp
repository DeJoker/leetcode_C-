#include "../common/debugger.h"

class Solution {
public:
    int getKthMagicNumber(int k) {
        priority_queue<int,deque<int>,greater<int>> smallqueue;
        vector<int> factor = {3,5,7};
        smallqueue.push(1);
        int count = 0;
        long long value = 0;

        while(!smallqueue.empty() && count<k){
            value = smallqueue.top();
            smallqueue.pop();
            count++;

            for(auto &num:factor){
                long long nextnum =value*num ;
                if(nextnum<= INT32_MAX){
                    smallqueue.push(nextnum);
                }
            }
        }
        return value;
    }
};



int main() {
    Solution sol;
    cout << sol.getKthMagicNumber(7) << endl;
    return 0;
}
