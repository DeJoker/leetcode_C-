/*
 * @lc app=leetcode.cn id=971 lang=cpp
 *
 * [971] 翻转二叉树以匹配先序遍历
 */

#include "../common/debugger.h"
#include "../util/pretty_tree.h"

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> _res;
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        dfs(root, voyage, 0);
        return _res;
    }

    void dfs(TreeNode* root, vector<int>& voyage, int i) {
        if (!root)
            return;

        // 这里就是巧妙的地方一旦发现不符合就立即退出return，相当于不满足题意直接退出整个递归
        if (root->val != voyage[i]) {
            _res.clear();
            _res.emplace_back(-1);
            return;
        }

        ++i;
        if (root->left && root->left->val != voyage[i]) {
            _res.emplace_back(root->val);
            dfs(root->right, voyage, i);
            dfs(root->left, voyage, i);
        } else {
            dfs(root->left, voyage, i);
            dfs(root->right, voyage, i);
        }
    }
};
// @lc code=end

