/*
 * @lc app=leetcode.cn id=814 lang=cpp
 *
 * [814] 二叉树剪枝
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

    int dfs(TreeNode* node) {
        if (!node) return 0;

        int l = dfs(node->left);
        int r = dfs(node->right);

        if (l==0) node->left = nullptr;
        if (r==0) node->right = nullptr;

        return node->val + l + r;
    }

    TreeNode* pruneTree(TreeNode* root) {
        TreeNode p(-1);
        p.left = root;
        dfs(&p);
        return p.left;
    }
};
// @lc code=end

