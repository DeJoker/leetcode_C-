/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
 */
#include "../common/debugger.h"

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
    int rob(TreeNode* root) {
        
        std::function<pair<int, int>(TreeNode*)> dfs;
        dfs = [&](TreeNode* node) {
            if (!node) {
                // return {0, 0};
                return make_pair(0,0);
            }

            auto [ls, ln] = dfs(node->left);
            auto [rs, rn] = dfs(node->right);

            int stole = node->val +ln+rn; // 抢，下家就不能抢了
            int notStole = max(ls, ln) + max(rs, rn); // 不抢，下家可抢可不抢，取决于收益大小
            return make_pair(stole, notStole);
            // return {stole, notStole};
        };

        auto [s, n] = dfs(root);
        return max(s, n);
    }
};
// @lc code=end
int main() {
    TreeNode* root;

    root = stringToTreeNode("[3,2,3,null,3,null,1]"); // 7
    LOG_DEBUG << Solution().rob(root);
    root = stringToTreeNode("[3,4,5,1,3,null,1]"); // 9
    LOG_DEBUG << Solution().rob(root);

    root = stringToTreeNode("[4,1,null,2,null,3]"); // 7
    LOG_DEBUG << Solution().rob(root);
}


