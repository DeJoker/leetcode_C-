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


// 12 ms 19.7MB
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        vector<vector<int>> res;

        // root to current node sum value
        std::function<void(vector<int>& path, TreeNode* node, int sum)> dfs;
        dfs = [&](vector<int>& path, TreeNode* node, int sum) {
            if (!node) return;
            
            path.push_back(node->val);
            sum += node->val;
            dfs(path, node->left, sum);
            dfs(path, node->right, sum);

            if (!node->left && !node->right) {
                if (sum == targetSum) {
                    res.push_back(path);
                }
            }
            
            path.pop_back();
        };
        
        dfs(path, root, 0);
        return res;
    }
};

class Solution222 {
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
    auto kk = Solution().pathSum(node, 22); // [[5,4,11,2],[5,8,4,5]]
    DebugPlanarVector(kk);
}
