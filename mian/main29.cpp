#include "../common/debugger.h"


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> matrix) {
        vector<int> res;
        int n=matrix.size(), m=matrix[0].size();
        vector<vector<bool>> visit(n, vector<bool>(m));
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};

        int nx(0), ny(0);
        res.push_back(matrix[nx][ny]);
        visit[nx][ny] = true;
        // 3*3数组，dy撞了南墙ny=3就没办法继续往下了，所以要恢复原值才继续
        while(res.size() != m*n) {
            for(int i=0; i<4; ++i) {
                nx += dx[i]; ny += dy[i];
                // res.push_back(matrix[nx][ny]);
                // visit[nx][ny] = true;
                while(nx>=0 && nx<n && ny>=0 && ny<m && !visit[nx][ny]) {
                    res.push_back(matrix[nx][ny]);
                    visit[nx][ny] = true;
                    nx += dx[i]; ny += dy[i];
                }
            }
        }
        return res;
    }
};

int main() {
    auto res = Solution().spiralOrder({{1,2,3},{4,5,6},{7,8,9}});
    DebugVector(res);
}