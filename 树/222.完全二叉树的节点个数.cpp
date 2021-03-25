/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
     int countNodes(TreeNode* root) {
        /**
        完全二叉树的高度可以直接通过不断地访问左子树就可以获取
        判断左右子树的高度: 
        如果相等说明左子树是满二叉树, 然后进一步判断右子树的节点数(最后一层最后出现的节点必然在右子树中)
        如果不等说明右子树是深度小于左子树的满二叉树, 然后进一步判断左子树的节点数(最后一层最后出现的节点必然在左子树中)
        **/
        if (!root) return 0;
        int ld = getDepth(root->left);
        int rd = getDepth(root->right);
        int ret;
        if(ld == rd) {
            ret = (1 << ld) + countNodes(root->right); // 1(根节点) + (1 << ld)-1(左完全左子树节点数) + 右子树节点数量
        } else {
            ret =  (1 << rd) + countNodes(root->left);  // 1(根节点) + (1 << rd)-1(右完全右子树节点数) + 左子树节点数量
        }
        return ret;
        
    }

    int getDepth(TreeNode* r) {
        int depth = 0;
        while(r != nullptr) {
            depth++;
            r = r->left;
        }
        return depth;
    }
};
// @lc code=end

int main() {
    int b = 1<<2;
    TreeNode* root;
    root = stringToTreeNode("[1,2,3,4,5,6]");
    LOG_DEBUG <<Solution().countNodes(root);
    return 0;
}

