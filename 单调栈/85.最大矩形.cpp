/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */
#include "../common/debugger.h"

// 输入二维数组如下
// ["1","0","1","0","0"],
// ["1","0",       "1","1","1"],
// ["1","1",       "1","1","1"],
// ["1","0","0","1","0"]

// 最大面积是6






// @lc code=start

// 规范单调栈解法
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int res = 0;

        vector<int> line(matrix[0].size() + 2, 0);
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                line[j + 1] = (matrix[i][j] == '0') ? 0 : line[j + 1] + 1;
            }
            res = max(res, largestRectangleArea(line));
        }
        
        return res;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;

        stack<int> st;
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int cur = st.top(); st.pop();
                int left = st.top() + 1;
                int right = i - 1;
                ans = max(ans, (right - left + 1) * heights[cur]);
            }
            st.push(i);
        }
        return ans;
    }
};

// https://leetcode-cn.com/problems/maximal-rectangle/solution/maximal-rectangle-by-ikaruga-idh2/



// 1、计算每个元素左边的最长连续1个数 left[i][j]
// 2、枚举所有点，计算以[i][j]为右下角点的最大矩形
// 关键就第二步如何计算：我们已知[i][j]左边最长也就是（行最长信息）
// 那么剩下就各列可能的面积


class Solution333 {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) {
            return 0;
        }
        int n = matrix[0].size();
        vector<vector<int>> left(m, vector<int>(n, 0));

        // left[i][j] 为矩阵第 i 行第 j 列元素的左边连续 1 的数量
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    left[i][j] = (j == 0 ? 0: left[i][j - 1]) + 1;
                }
            }
        }

        int ret = 0;
        for (int j = 0; j < n; j++) { // 对于每一列，使用基于柱状图的方法
            vector<int> up(m, 0), down(m, 0);

            stack<int> st;
            for (int i = 0; i < m; i++) {
                while (!st.empty() && left[st.top()][j] >= left[i][j]) {
                    st.pop();
                }
                up[i] = st.empty() ? -1 : st.top();
                st.push(i);
            }
            st = stack<int>();
            for (int i = m - 1; i >= 0; i--) {
                while (!st.empty() && left[st.top()][j] >= left[i][j]) {
                    st.pop();
                }
                down[i] = st.empty() ? m : st.top();
                st.push(i);
            }

            for (int i = 0; i < m; i++) {
                int height = down[i] - up[i] - 1;
                int area = height * left[i][j];
                ret = max(ret, area);
            }
        }
        return ret;
    }
};
// @lc code=end




int main() {
    vector<vector<char>> p;
    p = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'},
    };
    LOG_DEBUG << Solution().maximalRectangle(p);

}

