#include "../common/debugger.h"


class Solution {
public:
    vector<int> findDivisors(int num) {
        vector<int> divsors;
        divsors.push_back(1);       
        divsors.push_back(num);
        
        int limit = sqrt(num);
        // 就TM少个等于号
        for(int i=2; i<=limit; ++i) {
            if (num % i ==0) {
                divsors.push_back(i);
                if (i != num/i)
                    divsors.push_back(num/i);
            }
        }
        
        return divsors;
    }
    
    int SumVec(vector<int>& xxx) {
        int res(0);
        for(auto xx : xxx) {
            res += xx;
        }
        return res;
    }
    
    int sumFourDivisors(vector<int>& nums) {
        int res(0);
        
        for(auto num : nums) {
            auto vec = findDivisors(num);
            if (vec.size() == 4) {
                res += SumVec(vec);
            }
        }
        
        return res;
    }
};

int main() {

    int x= 0xF0030001;
    cout << x <<endl;


    // Solution sol;
    // vector<int> res = {1,2,3,4,5,6,7,8,9,10};
    // cout << sol.sumFourDivisors(res);
}
