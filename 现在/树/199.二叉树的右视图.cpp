/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        
        queue<pair<TreeNode*, int>> qu;
        qu.push({root, 1});
        while(!qu.empty()) {
            auto [node, level] = qu.front();
            qu.pop();

            if (res.size() < level) {
                res.push_back(node->val);
            }
            if (node->right) qu.push({node->right, level+1});
            if (node->left) qu.push({node->left, level+1});
        }
        return res;
    }
};
// @lc code=end

int main() {
    auto root = stringToTreeNode("[1,2,3,null,5,null,4]");
    Solution().rightSideView(root);
}