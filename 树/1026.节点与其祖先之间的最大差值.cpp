/*
 * @lc app=leetcode.cn id=1026 lang=cpp
 *
 * [1026] 节点与其祖先之间的最大差值
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
    int ans = 0;

    // base case 到叶子才计算一条路径上的差值
    // dfs返回的是当前节点最大差值
    int dfs(TreeNode* node, int low, int high) {
        if (!node) return high-low;
        int ldiff = dfs(node->left, min(low, node->val), max(high, node->val));
        int rdiff = dfs(node->right, min(low, node->val), max(high, node->val));
        return max(ldiff, rdiff);
    }
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, INT_MAX, INT_MIN);
    }
};
// @lc code=end

