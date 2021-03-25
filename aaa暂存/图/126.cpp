#include "../common/debugger.h"

class Solution {
public:
    bool Connect(const string& s1, const string& s2) {
        int n=s1.size(), diff(0);
        for(int i=0; i<n && diff<2; ++i) {
            if (s1[i]!=s2[i])
                ++diff;
        }
        return diff==1;
    }

    void ConstructGraph(vector<vector<int>>& graph, vector<string>& wordList) {
        int n = wordList.size();
        for(int i=0; i<n; ++i) {
            for(int j=i+1; j<n; ++j) {
                if (Connect(wordList[i], wordList[j])) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        vector<vector<string>> res;
        vector<vector<int>> graph(wordList.size());
        ConstructGraph(graph, wordList);

        int beginPos = wordList.size()-1;
        bool found(false);
        queue<pair<int, vector<int>>> Q;
        Q.push({beginPos, {beginPos}});
        vector<bool> visited(wordList.size());
        visited[beginPos] = true;

        while(!Q.empty()) {
            auto [pos, vec] = Q.front(); Q.pop();
            for(int j=0; j<graph[pos].size(); ++j) {
                if (!visited[graph[pos][j]]) {
                    auto tmp = vec;
                    tmp.push_back(j);
                    Q.push({j, tmp});
                    visited[graph[pos][j]] = true;
                    if (wordList[j] == endWord) {
                        vector<string> path;
                        for(auto k : tmp) {
                            
                        }
                    }
                }
                
            }
        }
    }
};


int main() {
    vector<string> vec = {"hot","dot","dog","lot","log","cog"};
    // cout << Solution2().ladderLength("hit", "cog", vec);
    auto res =  Solution().findLadders("hit", "cog", vec);
    DebugPlanarVector(res);
}
