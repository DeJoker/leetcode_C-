/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
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
class Solution333 {
public:
    TreeNode* ans;
    // 返回是否找到其中之一
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return false;
        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q);
        // 怎么确保是最近的？ 跟我们判断的规则有关
        // 第一条是左右子树的pq，对于其他节点其实只会在一颗字数上
        // 第二个条件更不可能，自身是其中一个节点，子数还有另一个
        if ((lson && rson) || ((root->val == p->val || root->val == q->val) && (lson || rson))) {
            ans = root;
        } 
        return lson || rson || (root->val == p->val || root->val == q->val);
    }

    // (f[left] && f[right])   左右子树为p、q两节点
    // ||
    // ((x==p || x==q) || (f[left] || f[right]))   自己为其中之一，左右子树有其一
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }
};

class Solution {
public:
    TreeNode* ans = nullptr;

    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return false;
        bool fleft = dfs(root->left, p, q);
        bool fright = dfs(root->right, p, q);
        if ((fleft&&fright) || ((root==p || root==q) && (fleft || fright))) {
            ans = root;
        }
        return fleft || fright || root==p || root==q;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p ,q);
        return ans;
    }
};
// @lc code=end

int main() {

}

