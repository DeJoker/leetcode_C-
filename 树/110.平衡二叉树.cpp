/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 */
#include "../common/debugger.h"

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool ans = true;
    int dfs(TreeNode* node) {
        if (!node) return 0;

        int lf = dfs(node->left);
        int rg = dfs(node->right);
        if (abs(rg-lf) > 1) {
            ans = false;
        }
        return max(lf, rg) + 1;
    }
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
// @lc code=end


int main() {
    TreeNode* root;
    root = stringToTreeNode("[3,9,20,null,null,15,7]"); // 1
    LOG_DEBUG << Solution().isBalanced(root);
    root = stringToTreeNode("[1,2,2,3,3,null,null,4,4]"); // 0
    LOG_DEBUG << Solution().isBalanced(root);
    root = stringToTreeNode("[]"); // 1
    LOG_DEBUG << Solution().isBalanced(root);
    root = stringToTreeNode("[1,null,2,null,3]"); // 0
    LOG_DEBUG << Solution().isBalanced(root);

    root = stringToTreeNode("[3,9,20,null,null,15,7]"); // 1
    LOG_DEBUG << Solution().isBalanced(root);
}
