/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

#include "../common/debugger.h"

// @lc code=start

// 应该直接使用backtack返回值，因为是整体遍历结束完全匹配，不存在中间过程达到目标强制返回
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<pair<int,int>> starts;
        int n=board.size(), m=board[0].size();
        if (word.empty()) return true;
        vector<vector<bool>> visit(n, vector<bool>(m));

        vector<pair<int,int>> dirct={{0,1},{0,-1},{1,0},{-1,0}};

        std::function<bool(int row, int col, int pos)> backtack;
        backtack = [&](int row, int col, int pos) {
            if (pos == word.size()-1) { // 这里是-1 比值
                return true;
            }
            bool ret(false);

            visit[row][col] = true;
            for(int i=0; i<4; i++) {
                int nexti=row+dirct[i].first;
                int nextj=col+dirct[i].second;

                if ((nexti>=0 && nexti<n) && (nextj>=0 && nextj<m) 
                    && !visit[nexti][nextj] && board[nexti][nextj] == word[pos+1]) 
                // pos+1 跟下一个比所以是+1
                {
                    ret = backtack(nexti, nextj, pos+1);
                    if (ret) break;
                }
            }
            visit[row][col] = false;
            return ret;
        };

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if (word[0]==board[i][j]) {
                    starts.push_back({i,j});
                }
            }
        }

        for(auto& start : starts) {
            bool res = backtack(start.first, start.second, 0);
            if (res)
                return true;
        }
        return false;
    }
};

class Solution222 {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<pair<int,int>> starts;
        int n=board.size(), m=board[0].size();
        if (word.empty()) return true;
        bool res(false);
        vector<vector<bool>> visit(n, vector<bool>(m));

        vector<pair<int,int>> dirct={{0,1},{0,-1},{1,0},{-1,0}};

        std::function<void(int row, int col, int pos)> backtack;
        backtack = [&](int row, int col, int pos) {
            if (pos == word.size()-1) { // 这里是-1 比值
                res=true;
                return;
            }

            visit[row][col] = true;
            for(int i=0; i<4; i++) {
                int nexti=row+dirct[i].first;
                int nextj=col+dirct[i].second;

                if ((nexti>=0 && nexti<n) && (nextj>=0 && nextj<m) 
                    && !visit[nexti][nextj] && board[nexti][nextj] == word[pos+1]) 
                // pos+1 跟下一个比所以是+1
                {
                    backtack(nexti, nextj, pos+1);
                }
            }
            visit[row][col] = false;
        };

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if (word[0]==board[i][j]) {
                    starts.push_back({i,j});
                }
            }
        }

        for(auto& start : starts) {
            backtack(start.first, start.second, 0);
            if (res)
                return true;
        }
        return res;
    }
};
// @lc code=end

int main() {
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    LOG_DEBUG << Solution().exist(board, "ABCCED"); // 1
    LOG_DEBUG << Solution().exist(board, "SEE"); // 1
    LOG_DEBUG << Solution().exist(board, "ABCB"); // 0

}

