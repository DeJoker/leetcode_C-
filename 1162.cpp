#include "common/debugger.h"

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};

        int size = grid.size();
        queue<pair<int, int>> visit;
        for(int i=0; i<size; ++i) {
            for(int j=0; j<size; ++j) {
                if (grid[i][j] == 1)
                    visit.push(make_pair(i,j));
            }
        }
        
        int maxD = -1;
        while (!visit.empty()) {
            // 绝了，没事不要用引用，不然这里会有释放问题？？？神奇
            auto now = visit.front(); visit.pop();
            for(int i=0; i<4; ++i) {
                int nX = now.first+dx[i];
                int nY = now.second+dy[i];
                if (!(nX>=0 && nX<size && nY>=0 && nY<size)) continue;
                if (grid[nX][nY] == 0) {
                    grid[nX][nY] = grid[now.first][now.second]+1;
                    visit.push(make_pair(nX, nY));
                    maxD = max(maxD, grid[nX][nY]);
                }
            }
        }

        return maxD==-1 ? -1 : (maxD-1);
    }
};

int main() {
    for(int i=0; i<3; i++) {
        cout << "nima" << endl;
        if (i==0) continue;
    }

    Solution sol;
    vector<vector<int>> inland = {{1,0,0,0,0,1,0,0,0,1},{1,1,0,1,1,1,0,1,1,0},{0,1,1,0,1,0,0,1,0,0},{1,0,1,0,1,0,0,0,0,0},{0,1,0,0,0,1,1,0,1,1},{0,0,1,0,0,1,0,1,0,1},{0,0,0,1,1,1,1,0,0,1},{0,1,0,0,1,0,0,1,0,0},{0,0,0,0,0,1,1,1,0,0},{1,1,0,1,1,1,1,1,0,0}};
    cout << sol.maxDistance(inland);


    return 0;
}