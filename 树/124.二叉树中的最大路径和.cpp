/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
    int maxPath = INT_MIN;

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxPath;
    }
    // 包含当前节点的最大路径
    int dfs(TreeNode* root) {
        if (!root) return 0;

        int maxL = max(dfs(root->left), 0);
        int maxR = max(dfs(root->right), 0);

        // 递归中以自己为中心的最大路径，判断是否最大
        int maxCur = root->val + maxL + maxR;
        maxPath = max(maxPath, maxCur);

        // 选左右最大分支为向上返回过程的最大
        return root->val + max(maxL, maxR);
    }
};
// @lc code=end
int main() {
    auto root = stringToTreeNode("[1,2,3]");
    Solution().maxPathSum(root);
}
