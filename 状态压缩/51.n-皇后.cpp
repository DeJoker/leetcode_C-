/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */
#include "../common/debugger.h"

// @lc code=start
class Solution {
public:

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> path(n, string(n, '.'));

        vector<int> col(n, 0);  //存储已有的列值
        vector<int> positive(2 * n, 0); //存储已有的正对角线的值
        vector<int> negative(2 * n, 0); //存储已有的反对角线的值

        // 正斜率 和 负斜率
        std::function<void(int row, vector<int>& col, vector<int>& positive, vector<int>& negative, vector<string>& path)> backtrack;
        backtrack = [&](int row, vector<int>& col, vector<int>& positive, vector<int>& negative, vector<string>& path) {
            if(row == n){
                res.push_back(path);
                return ;
            }

            for(int i = 0; i < n; i++){
                if(!col[i] && !positive[row-i + n] && !negative[row + i]){//说明该位置合法
                    //这里注意一下，因为行与列的差值可能为负，所以dg下标要加一个n
                    col[i] = positive[row-i + n] = negative[row + i] = 1; 
                    path[row][i] = 'Q'; 

                    backtrack(row+1, col, positive, negative, path); 

                    col[i] = positive[row-i + n] = negative[row + i] = 0; 
                    path[row][i] = '.';
                }
            }
        };

        backtrack(0, col, positive, negative, path); //深度优先搜索回溯
        return res;
    }
};

class Solution3 {
public:
    void dfs(int row, int n, vector<vector<string>>& res, vector<string> a, vector<int> col, vector<int> dg, vector<int> adg){
        if(row == n){ //符合条件，直接存进数组
            res.push_back(a);
            return ;
        }
        for(int i = 0; i < n; i++){
            if(!col[i] && !dg[row - i + n] && !adg[row + i]){//说明该位置合法
            //这里注意一下，因为行与列的差值可能为负，所以dg下标要加一个n
                col[i] = dg[row - i + n] = adg[row + i] = 1; //将该位置的列，正对角线，反对角线的值都置1
                a[row][i] = 'Q'; //设置Q
                dfs(row + 1, n, res, a, col, dg, adg); //深度优先搜索
                col[i] = dg[row - i + n] = adg[row + i] = 0; //重置，以便下次查找该行合适位置
                a[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res; //存储最终结果
        vector<string> a(n, string(n, '.')); //临时结果
        vector<int> col(n, 0);  //存储已有的列值
        vector<int> dg(2 * n, 0); //存储已有的正对角线的值
        vector<int> adg(2 * n, 0); //存储已有的反对角线的值
        dfs(0, n, res, a, col, dg, adg); //深度优先搜索回溯
        return res;
    }
};


class SolutionStateCompress {
void dfs(int n, int row, int col, int ld, int rd, vector<int>& pick, vector<vector<string>>& ans) {
    if (row == n) {
        vector<string> str(n, string(n, '.'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (pick[i] & (1 << j)) {
                    str[i][j] = 'Q';
                    break;
                }
            }
        }
        ans.push_back(str);
        return;
    }

    int pos = ~(col | ld | rd) & ((1 << n) - 1);
    while (pos != 0) {
        pick[row] = (pos & -pos);
        dfs(n, row + 1, (col | pick[row]), ((ld | pick[row]) << 1), ((rd | pick[row]) >> 1), pick, ans);
        pos &= (pos - 1);
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<int> pick(n, 0);
    dfs(n, 0, 0, 0, 0, pick, ans);
    return ans;
}
};


// 状态压缩版本看不懂
// https://leetcode-cn.com/problems/n-queens/solution/51-by-ikaruga/

// @lc code=end

int main()
{
    vector<vector<string>> res, res2;
    res = Solution().solveNQueens(8);
    res2 = Solution3().solveNQueens(8);

    if (res == res2) {
        LOG_DEBUG << "yeah";
    }

    // DebugPlanarVector(res);
}


