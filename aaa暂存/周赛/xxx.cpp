#include "../common/debugger.h"


class Solution {
public:
    int maximalNetworkRank(int n, const vector<vector<int>>& roads) {
        vector<set<int>> graph(n);
        for(auto& road : roads) {
            graph[road[0]].insert(road[1]);
            graph[road[1]].insert(road[0]);
        }
        
        // if (n==2 && roads.size()!=0) {
        //     return 1;
        // }
        
        set<int> maxOrder;
        int maxConnect(0);
        for(int i=0; i<n; ++i) {
            if (maxOrder.size() < graph[i].size()) {
                maxOrder = graph[i];
                maxConnect = i;
            }
        }
        
        int res(maxOrder.size());
        for(int i=0; i<n; ++i) {
            if (i == maxConnect) {
                continue;
            }
            set<int> order(maxOrder);
            
            order.insert(graph[i].begin(), graph[i].end());
            if (maxOrder.find(i) == maxOrder.end() || graph[i].find(maxConnect) == graph[i].end()) {
                order.erase(maxConnect);
            }
            
            if (order.size() > res) {
                res = order.size();
            }
        }
        
        return res;
        
    }
};


int main() {
    Solution().maximalNetworkRank(4, {{0,1},{0,3},{1,2},{1,3}} );
}