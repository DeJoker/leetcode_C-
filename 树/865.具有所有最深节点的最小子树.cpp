/*
 * @lc app=leetcode.cn id=865 lang=cpp
 *
 * [865] 具有所有最深节点的最小子树
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
// 保证是最大深度靠ld和rd的比较，
    pair<TreeNode*, int> dfs(TreeNode* node, int d) {
        if (!node) return {node , d};
        auto [ln, ld] = dfs(node->left, d+1);
        auto [rn, rd] = dfs(node->right, d+1);
        if (ld == rd) return {node,ld+1};

        if (ld > rd) return {ln, ld+1};
        return {rn, rd+1};
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root, 0).first;
    }
};
// @lc code=end

