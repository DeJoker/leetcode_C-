#include "../common/debugger.h"
#include "../util/pretty_tree.h"

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<pair<bool, TreeNode*>> st;
        st.push({false, root});
        while(!st.empty()) {
            auto [visit, node] = st.top(); st.pop();
            if (!node) continue;
            if (!visit) {
                st.push({false, node->right});
                st.push({false, node->left});
                st.push({true, node});
            } else {
                ret.push_back(node->val);
            }
        }
        return ret;
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        string path;

        stack<pair<TreeNode*, bool>> st;
        st.push({root, false});

        while(!st.empty()) {
            auto [node, visit] = st.top();
            st.pop();
            if(!node) continue;
            if (!visit) {
                st.push({root->right, false});
                st.push({root->left, false});
                st.push({root, true});
            } else {
                path += to_string(root->val);
                if(!root->left && !root->right) {
                    ret.push_back(path);
                } else {
                    path += "->";
                }
            }
        }
        return ret;
    }

};


int search(vector<int>& nums, int target) {
    int left=0, right=nums.size()-1;

    while(left <= right) {
        int mid = left + (right-left)/2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            right = mid-1;
        } else {
            left = mid+1;
        }
    }
    return -1;
}

int searchBound(vector<int>& nums, int target) {
    int left=0, right=nums.size()-1;
    while(left <= right) {
        int mid = left + (right-left)/2;
        {
            // [left bound]  收紧右边界
            right = mid - 1; 
        }
    }
    // [left bound] 最后判断边界与返回
    if (left >= nums.size() || nums[left] != target)
        return -1;
    return left;

}

string xx()
{
    string s, t;
    // 在 s 中寻找 t 的「最小覆盖子串」
    int left = 0, right = 0;
    string res = s;

    while(right < s.size()) {
        window.add(s[right]);
        right++;
        // 如果符合要求，移动 left 缩小窗口
        while (window 符合要求) {
            // 如果这个窗口的子串更短，则更新 res
            res = minLen(res, window);
            window.remove(s[left]);
            left++;
        }
    }
    return res;
}

string minWindow(string s, string t) {
    // 记录最短子串的开始位置和长度
    int start = 0, minLen = INT_MAX;
    int left = 0, right = 0;
    
    unordered_map<char, int> window;
    unordered_map<char, int> needs;
    for (char c : t) needs[c]++;
    
    int match = 0;
    
    while (right < s.size()) {
        char c1 = s[right];
        if (needs.count(c1)) {
            window[c1]++;
            if (window[c1] == needs[c1]) 
                match++;
        }
        right++;
        
        while (match == needs.size()) {
            if (right - left < minLen) {
                // 更新最小子串的位置和长度
                start = left;
                minLen = right - left;
            }
            char c2 = s[left];
            if (needs.count(c2)) {
                window[c2]--;
                if (window[c2] < needs[c2])
                    match--;
            }
            left++;
        }
    }
    return minLen == INT_MAX ?
                "" : s.substr(start, minLen);
}

int searchBound(vector<int>& nums, int target) {
    int left=0, right=nums.size()-1;
    while(left <= right) {
        int mid = left + (right-left)/2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            // [left bound]  收紧右边界
            right = mid - 1; 

            // [right bound]  收紧左边界
            left = mid + 1;
        }
    }
    // [left bound] 最后判断边界与返回
    if (left >= nums.size() || nums[left] != target)
        return -1;
    return left;

    // [right bound] 最后判断边界与返回
    if (left < 0 || nums[right] != target)
        return -1;
    return right;
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ret;
    stack<TreeNode*> st;
    TreeNode* p=root;
    while(p || !st.empty()) {
        if (p) {
            st.push(p);
            // 这一句就是dfs过程中实际执行的语句（前序遍历）
            // ret.push_back(p->val);
            p=p->left;
        } else {
            p = st.top();
            st.pop();
            // 如果在这里操作就是中序遍历
            // ret.push_back(p->val);
            p = p->right;
        }
    }
    return ret;
}

vector<int> postorderTraversal(TreeNode* root) {
    if(!root) return {};
    stack<TreeNode*> st;
    st.push(root);
    vector<int> res;
    while(!st.empty()) {
        TreeNode* cur = st.top();
        if(cur == nullptr) {
            st.pop();
            res.push_back(st.top()->val);
            st.pop();
            // 注意continue，当然如果没有后面执行 nullptr->right
            continue;
        }

        st.push(nullptr);
        if (cur->right) st.push(cur->right);
        if (cur->left) st.push(cur->left);
    }
    return res;
}

vector<int> (TreeNode* root) {
    vector<int> ret;
    stack<pair<bool, TreeNode*>> st;
    st.push({false, root});
    while(!st.empty()) {
        auto [visit, node] = st.top(); st.pop();
        if (!node) continue;
        if (!visit) {
            // 中序
            st.push({false, node->right});
            st.push({true, node});
            st.push({false, node->left});

            // 先序
            st.push({false, node->right});
            st.push({false, node->left});
            st.push({true, node}); // 此时需要遍历的点在栈顶下一次迭代就会遇到

            // 后序
            st.push({true, node});
            st.push({false, node->right});
            st.push({false, node->left});
        } else {
            ret.push_back(node->val);
        }
    }
    return ret;
}









class NQueue {
    vector<vector<string>> res;

    /* 输入棋盘边长 n，返回所有合法的放置 */
    vector<vector<string>> solveNQueens(int n) {
        // '.' 表示空，'Q' 表示皇后，初始化空棋盘。
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0);
        return res;
    }

    // 路径：board 中小于 row 的那些行都已经成功放置了皇后
    // 选择列表：第 row 行的所有列都是放置皇后的选择
    // 结束条件：row 超过 board 的最后一行
    void backtrack(vector<string>& board, int row) {
        // 触发结束条件
        if (row == board.size()) {
            res.push_back(board);
            return;
        }
        
        int n = board[row].size();
        for (int col = 0; col < n; col++) {
            // 排除不合法选择
            if (!isValid(board, row, col)) 
                continue;
            // 做选择
            board[row][col] = 'Q';
            // 进入下一行决策
            backtrack(board, row + 1);
            // 撤销选择
            board[row][col] = '.';
        }
    }

    /* 是否可以在 board[row][col] 放置皇后？ */
    bool isValid(vector<string>& board, int row, int col) {
        int n = board.size();
        // 检查列是否有皇后互相冲突
        for (int i = 0; i < n; i++) {
            if (board[i][col] == 'Q')
                return false;
        }
        // 检查右上方是否有皇后互相冲突
        for (int i = row - 1, j = col + 1; 
                i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }
        // 检查左上方是否有皇后互相冲突
        for (int i = row - 1, j = col - 1;
                i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }
};


// 函数找到一个答案后就返回 true
bool backtrack(vector<string>& board, int row) {
    // 触发结束条件
    ... 
    for (int col = 0; col < n; col++) {
        ...
        board[row][col] = 'Q';

        if (backtrack(board, row + 1))
            return true;
        
        board[row][col] = '.';
    }

    return false;
}


int main() {
    Solution sol;
    // auto ret = sol.preorderTraversal(stringToTreeNode("[1,2,3,null,5]"));
    auto ret = sol.binaryTreePaths(stringToTreeNode("[1,2,3,null,5]"));
    DebugVecor(ret);
}