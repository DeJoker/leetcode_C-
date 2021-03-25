#include <iostream>
#include <set>
#include <stack>
#include <functional>
#include <queue>
#include <list>
#include <map>
using namespace std;

#include <cstring>

template<typename Ty>
void DebugPlanarVector(vector<vector<Ty>>& data)
{
    for (auto parallel : data)
    {
        cout << "[";
        for (auto val : parallel)
        {
            cout << val << ",";
        }
        cout << "]" << endl;
    }
}


class Solution {
public:
    int checkEdge(vector<int>& edge) {
        int edgeSize(0);
        for(int i=1; i<edge.size(); ++i) {
            if (edge[i] != 0)
                edgeSize++;
        }
        return edgeSize;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // vector<vector<int>> adjacency(prerequisites.size(), vector<int>(prerequisites[0].size()));
        // {
        //     vector<vector<int>> adjacency(numCourses, vector<int>(numCourses));

        //     // 要求1 每层开始元素指向剩余元素
        //     for (auto vec : prerequisites) {
        //         auto& cur = adjacency[vec[0]];
        //         for (int i=1; i<vec.size(); ++i) {
        //             cur[vec[i]] = 1;
        //         }
        //     }
        // }
        queue<int> traverse;
        traverse.size();

        vector<vector<int>> adjacency(numCourses, vector<int>(numCourses));
        vector<int> indegrees(numCourses);

        // 要求2 邻接表初始化入度
        for (auto vec : prerequisites) {
            for (int i=1; i<vec.size(); ++i) {
                adjacency[vec[i-1]][vec[i]] = 1;
                indegrees[vec[i-1]]++;
            }
        }
        DebugPlanarVector(adjacency);

        queue<int> nodes;
        for(int i=0; i<adjacency.size(); ++i)
            if (checkEdge(adjacency[i]) == 0)
                nodes.push(i);
        
        while(nodes.empty()) {
            int pre = nodes.front();  nodes.pop();
            numCourses--;
            for(int cur : adjacency[pre])
                if (--indegrees[cur] == 0) {
                    nodes.push(cur);
                    cout << pre << endl;
                }
        }
        return numCourses == 0;
    }
};


int main() {
    Solution sol;
    vector<vector<int>> request = {
        {0, 1},
        {4, 2, 1},
        {2, 3},
        {1, 2},
    };
    cout  << sol.canFinish(5, request) << "xxxx" << endl;
}
