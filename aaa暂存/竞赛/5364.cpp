#include "../common/debugger.h"


class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> res(nums.size());
        for(int i=0; i<nums.size(); i++) {
            if (res[index[i]] != 0)
                res[index[i]] = nums[i];
            else
                res.emplace(res.begin()+i, nums[i]);
        }
    }
};

int main() {
    
}