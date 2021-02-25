/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根到叶子节点数字之和
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
    vector<int> nums;
    void dfs(TreeNode* node, int sum) {
        if (node->left==nullptr && node->right==nullptr) {
            nums.push_back(sum*10+node->val);
            return;
        }
        if (node->left) dfs(node->left, sum*10+node->val);
        if (node->right) dfs(node->right, sum*10+node->val);
    }

    int sumNumbers(TreeNode* root) {
        // if (!root) return 0;
        dfs(root, 0);
        int res(0);
        for(int num : nums) {
            res += num;
        }
        return res;
    }
};
// @lc code=end

int main() {
    TreeNode* root;
    root = stringToTreeNode("[1,2,3]");
    LOG_DEBUG << Solution().sumNumbers(root);
    root = stringToTreeNode("[4,9,0,5,1]");
    LOG_DEBUG << Solution().sumNumbers(root);
}
