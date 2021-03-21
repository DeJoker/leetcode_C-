/*
 * @lc app=leetcode.cn id=783 lang=cpp
 *
 * [783] 二叉搜索树节点最小距离
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
    // base case 就是
    // dfs是在当前节点中所有子节点的最小差值
    int dfs(TreeNode* node, int lower, int upper) {
        if (!node) {
            return upper - lower;
        }
        // 搜索树只和左右子节点有关，没有传导
        int ldiff = dfs(node->left, lower, node->val);
        int rdiff = dfs(node->right, node->val, upper);
        return min(rdiff, ldiff);
    }
    int minDiffInBST(TreeNode* root) {
        return dfs(root, INT_MIN/2, INT_MAX/2);
    }
};
// @lc code=end

int main() {
    TreeNode* root;

    root = stringToTreeNode("[4,2,6,1,3]");

    LOG_DEBUG << Solution().minDiffInBST(root);
}
