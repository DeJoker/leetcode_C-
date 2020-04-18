#include "common/debugger.h"


class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        // 
        std::nth_element(arr.begin(), arr.begin()+k, arr.end());
        std::sort(arr.begin(), arr.begin()+k);

        std::partial_sort(arr.begin(), arr.begin()+k, arr.end());

        return vector<int>(arr.begin(), arr.begin()+k);

    }
};

int main() {
    Solution sol;
    vector<int> arr{0,0,1,2,4,2,2,3,1,4};
    auto ret = sol.getLeastNumbers(arr , 8);

    DebugVecor(ret);
}
