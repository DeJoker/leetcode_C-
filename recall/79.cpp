#include "../common/debugger.h"


class Solution233 {
public:
    bool res;
    int m,n;
    bool exist(vector<vector<char>>& board, string word) {
        m=board.size(); n=board[0].size();
        res = false;
        vector<pair<int,int>> starts;

        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j)
                if (board[i][j] == word[0])
                    starts.push_back({i,j});
        }
        for(int i=0; i<starts.size(); ++i) {
            if (res){
                return res;
            }
            dfs(board, word, 0, starts[i]);
        }
        return res;
    }

    void dfs(vector<vector<char>>& board, string& word, int cnt, pair<int,int> pos) {
        // if (pos.first<0 || pos.first>=m || pos.second<0 || pos.second>=n)
        //     return;
        if (cnt == word.size()-1) {
            res = true;
            return;
        }

        static constexpr int dirt[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        for(int i=0; i<4; ++i) {
            int nx = pos.first+dirt[i][0];
            int ny = pos.second+dirt[i][1];
            if (nx<0 || nx>=m || ny<0 || ny>=n)
                continue;
            if (word[cnt+1] == board[nx][ny])
                dfs(board, word, cnt+1, {nx, ny});
        }
    }
};
// 上面解法没有加入重复路径判断。



class Solution {
public:
    bool res;
    int m,n;
    bool exist(vector<vector<char>>& board, string word) {
        m=board.size(); n=board[0].size();
        res = false;
        vector<pair<int,int>> starts;
        set<pair<int,int>> visit;

        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j)
                if (board[i][j] == word[0])
                    starts.push_back({i,j});
        }
        for(int i=0; i<starts.size(); ++i) {
            if (res){
                return res;
            }
            visit.insert(starts[i]);
            dfs(board, word, 0, visit, starts[i]);
            visit.clear(); // 忘记清理
        }
        return res;
    }

    void dfs(vector<vector<char>>& board, string& word, int cnt, set<pair<int,int>>& visit, pair<int,int> pos) {
        // if (pos.first<0 || pos.first>=m || pos.second<0 || pos.second>=n)
        //     return;
        if (cnt == word.size()-1) {
            res = true;
            return;
        }

        static constexpr int dirt[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        for(int i=0; i<4; ++i) {
            int nx = pos.first+dirt[i][0];
            int ny = pos.second+dirt[i][1];
            if (nx<0 || nx>=m || ny<0 || ny>=n)
                continue;
            if (word[cnt+1] == board[nx][ny] && visit.find({nx, ny}) == visit.end()) {
                visit.insert({nx, ny});
                dfs(board, word, cnt+1, visit, {nx, ny});
            }
        }
    }
};

int main() {
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    // cout << Solution().exist(board, "ABCCED") <<endl;
    vector<vector<char>> board2 = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    // cout << Solution().exist(board2, "ABCB") <<endl;


    vector<vector<char>> board3 = {{'C','A','A'},{'A','A','A'},{'B','C','D'}};
    cout << Solution().exist(board3, "AAB") <<endl;

}