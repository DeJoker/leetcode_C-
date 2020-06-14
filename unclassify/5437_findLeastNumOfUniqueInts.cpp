
#include "../common/debugger.h"


bool CompByTimes(const pair<int, int>& lhs, const pair<int, int>& rhs) {
    return lhs.second<rhs.second;
}

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        // map<int, vector<int>, decltype(CompByTimes)> cnt;
        map<int, vector<int>> cnt;
        int s;
        {
            map<int, int> eee;
            for(int i=0; i<arr.size(); ++i) {
                eee[arr[i]]++;
            }
            s = eee.size();
            for(auto& [num,size] : eee) {
                cnt[size].push_back(num);
            }
        }
        
        while(k) {
            auto iter = cnt.begin();
            if (iter->first <= k) {
                int second = iter->second.size();
                int eraseC = k/iter->first;
                if (eraseC <= second) {
                    k -= eraseC;
                    s -= eraseC;
                    break;
                } else {
                    k -= iter->first*second;
                    s -= second;
                }
                cnt.erase(iter);
            } else {
                k = 0;
            }
        }
        
        return s;
    }
};


int main() {
    vector<int> arr = {4,3,1,1,3,3,2};
    auto res = Solution().findLeastNumOfUniqueInts(arr, 3);
    cout << res;
}