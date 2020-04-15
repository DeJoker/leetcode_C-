#include "common/debugger.h"

class Solution {
public:
    // 0找1 反向找？
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        vector<vector<int>> dist(m, vector<int>(n));
        vector<vector<bool>> seen(m, vector<bool>(n, false));

        queue<pair<int, int>> one;
        for(int i=0; i<matrix.size(); ++i) {
            for(int j=0;j<matrix[0].size(); ++j) {
                if (matrix[i][j]==0) {
                    one.push(make_pair(i,j));
                    seen[i][j] = true;
                    // dist[i][j] = 0;
                }
            }
        }

        // int dx[4] = {1,0,-1,0};
        // int dy[4] = {0,1,0,-1};
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        while(!one.empty()) {
            auto [x, y] = one.front();
            // seen[x][y] = true;
            one.pop();
            for(int i=0; i<4; i++) {
                int nx = x+dx[i], ny = y+dy[i];
                if(nx<0 || nx>=m || ny<0 || ny>=n || seen[x][y]) continue;
                dist[nx][ny] = dist[x][y]+1;
                one.push(make_pair(nx, ny));
                seen[nx][ny] = true;
            }
        }

        return dist;
    }
};


int main() {
    Solution sol;
    vector<vector<int>> rr = {{0,0,0},{0,1,0},{0,0,0}};

    auto vec = sol.updateMatrix(rr);
    DebugPlanarVector(vec);
}
