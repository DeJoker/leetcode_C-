#include <iostream>
#include "../common/debugger.h"
#include <vector>
#include <functional>
using namespace std;

vector<vector<char>> print(vector<char>& vec) {
    vector<vector<char>> res;
    int n=vec.size();

    std::function<void(vector<bool>&, int, int)> backtrack;
    backtrack = [&](vector<bool>& pick, int idx, int end) {
        if (idx == end) {
            vector<char> path;
            for(int i=0; i<n; i++) {
                if (pick[i]) {
                    path.push_back(vec[i]);
                }
            }
            res.push_back(path);
            DebugVector(path);
            return;
        }

        for(int i=idx; i<end; i++) {
            pick[i] = true;
            backtrack(pick, i+1, end);
            pick[i] = false;
        }
    };

    vector<bool> p(n);
    backtrack(p, 0, n);
    return res;
}

// 递归深度过深的问题
vector<vector<char>> printRaw(vector<char>& vec) {
    vector<vector<char>> res;
    int n=vec.size();

    std::function<void(vector<bool>&, int, int)> backtrack;
    backtrack = [&](vector<bool>& pick, int idx, int end) {
        if (idx == end) {
            vector<char> path;
            for(int i=0; i<n; i++) {
                if (pick[i]) {
                    path.push_back(vec[i]);
                }
            }
            res.push_back(path);
            return;
        }

        for(int i=idx; i<end; i++) {
            pick[i] = true;
            backtrack(pick, i+1, end);
            pick[i] = false;
        }
    };

    vector<bool> p(n);
    backtrack(p, 0, n);
    return res; // 居然没写返回值
}


int main() {
    vector<char> k={'A', 'B', 'C'};
    auto pp = print(k);
    for(auto p2 : pp) {
        for(auto ret : p2) {
            cout << ret << " ";
        }
        cout << endl;
    }
    return 0;
}