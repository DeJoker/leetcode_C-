#include "common/debugger.h"

class Solution {
public:
    int CheckAndChange(vector<vector<int>>& board, int horizon, int para) {
        int d(0);
        for(int i=horizon-1; i<horizon+2; ++i) {
            for(int j=para-1; j<para+2; ++j) {
                if (i<0 || i>=board.size() || j<0 || j>=board[0].size())
                    continue;
                else if (board[i][j] == 1) {
                    if (i!=horizon || j!=para)
                        ++d;
                }
            }
        }

        if (d<2)
            return 0;
        if (d==2)
            return board[horizon][para];
        if (d == 3)
            return 1;
        // d>3
        return 0;
    }

    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> cur =  board;
        for(int i=0; i< board.size(); ++i) {
            for(int j=0; j<board[0].size(); ++j) {
                cur[i][j] = CheckAndChange(board, i, j);
            }
        }

        board = cur;
    }
};

int main() {
    vector<vector<int>> board;
    board = {
            {0,1,0},
            {0,0,1},
            {1,1,1},
            {0,0,0}
            };
    Solution sol;
    sol.gameOfLife(board);

    DebugPlanarVector(board);
}
