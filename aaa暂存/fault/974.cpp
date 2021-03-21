#include "../common/debugger.h"


class Solution {
public:
    int subarraysDivByK(vector<int> A, int K) {
        vector<int> sum;
        int cur(0);
        for(auto & ele : A) {
            cur += ele;
            sum.push_back(cur);
        }

        int res(0);
        for(int i=0; i<A.size(); ++i) {
            for(int j=i+1; j<A.size(); ++j) {
                if ((sum[j]-sum[i]) % K == 0)
                    ++res;
            }
        }
        if (sum.back() % K ==0)
            ++res;
        
        return res;
    }
};

int main() {
    set<string> sss;
    sss.insert("fdwqefw");
    sss.insert("fdwqefwg");
    sss.insert("fdwq4f8we45fefw");
    sss.insert("fwef");
    
    cout << Solution().subarraysDivByK({4,5,0,-2,-3,1}, 5);
}