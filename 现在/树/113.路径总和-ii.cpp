/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<vector<int>> maxPaths;
    int Sum;
    void dfs(TreeNode* node, vector<int>& path) {
        if (!node) {
            return;
        }

        path.push_back(node->val);
        dfs(node->left, path);
        dfs(node->right, path);
        if (!node->left && !node->right) {
            int sum(0);
            for (int v : path) {
                sum += v;
            }
            if (Sum == sum)
                maxPaths.push_back(path);
        }
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        Sum = targetSum;
        vector<int> path;
        dfs(root, path);
        return maxPaths;
    }
};
// @lc code=end

int main() {
    auto node = stringToTreeNode("[5,4,8,11,null,13,4,7,2,null,null,5,1]");
    auto kk = Solution().pathSum(node, 22);
    DebugPlanarVector(kk);
}
