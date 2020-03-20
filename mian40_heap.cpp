#include "common/debugger.h"


class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        make_heap(arr.begin(), arr.end(), 
            [](int a, int b)
            {
                return a > b;
            });
        return vector<int>(arr.begin(), arr.begin()+k);
    }
};

int main() {
    Solution sol;
    vector<int> arr{3,2,1};
    auto ret = sol.getLeastNumbers(arr , 2);

    DebugVecor(ret);
}
