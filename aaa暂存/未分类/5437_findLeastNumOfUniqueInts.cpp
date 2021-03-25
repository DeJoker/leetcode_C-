#include "../common/debugger.h"

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int, int> cnt;
        for(auto& cur : arr) {
            ++cnt[cur];
        }

        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto& [f, s] : cnt) {
            pq.push({s, f});
        }

        while(k && !pq.empty()) {
            auto top = pq.top();
            if (top.first <= k) {
                k -= top.first;
            } else {
                break;
            }
            pq.pop();
        }
        return pq.size();
    }
};


int main() {
    vector<int> arr = {4,3,1,1,3,3,2};
    auto res = Solution().findLeastNumOfUniqueInts(arr, 3);
    cout << res;
}