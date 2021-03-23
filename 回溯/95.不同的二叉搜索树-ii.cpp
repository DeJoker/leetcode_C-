/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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
    vector<TreeNode*> backtack(int start, int last) {
        if (start > last) {
            // 最后记得   base case 一定要返回空指针数组
            return {nullptr};
        }
        vector<TreeNode*> res;
        for(int i=start; i<=last; ++i) {
            vector<TreeNode*> left = backtack(start, i-1);
            vector<TreeNode*> right = backtack(i+1, last);
            for(auto& lf : left) {
                for(auto& rg : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = lf;
                    root->right = rg;
                    res.push_back(root);
                }
            }
        }
        return res;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (!n) {
            return {};
        }
        return backtack(1, n);
    }
};
// @lc code=end

void DebugVectorTreeNode(vector<TreeNode*>& r) {
    for(auto node : r) {
        prettyPrintTree(node);
    }
}

int main() {
    vector<TreeNode*> r;
    r = Solution().generateTrees(1);
    DebugVectorTreeNode(r);

    r = Solution().generateTrees(3);
    DebugVectorTreeNode(r);
}

