/*
 * @lc app=leetcode.cn id=1325 lang=cpp
 *
 * [1325] 删除给定值的叶子节点
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
    int T;
    void dfs(TreeNode* node, TreeNode* par, bool leftN) {
        if (!node) return;
        dfs(node->left, node, true);
        dfs(node->right, node, false);
        if (node->val == T && par && node->left==nullptr && node->right==nullptr) {
            if (leftN) par->left=nullptr;
            else par->right=nullptr;
        }
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        T=target;
        TreeNode n(-1);
        n.left=root;
        dfs(&n, nullptr, true);
        return n.left;
    }
};
// @lc code=end

int main() {
    auto kk = Solution().removeLeafNodes(stringToTreeNode("[1,2,3,2,null,2,4]"), 2);
    prettyPrintTree(kk);
}
