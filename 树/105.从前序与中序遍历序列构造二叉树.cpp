/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */
#include "../common/debugger.h"



// 树中没有重复的元素



// @lc code=start


class Solution {
private:
    map<int, int> mp;

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        // 建立inorder值到下标的映射（用下标计算左子树长度）
        for(int i=0; i<n; i++) {
            mp[inorder[i]] = i;
        }

        std::function<TreeNode*(int, int, int, int)> build;
        build = [&](int preLeft, int preRight, int inLeft, int inRight) -> TreeNode* {
            if (preLeft > preRight) return nullptr;
            
            int inRoot = mp[preorder[preLeft]];
            // 左子树个数
            int leftSize = inRoot-inLeft;

            TreeNode* node = new TreeNode(preorder[preLeft]);

            // 因为已经所有左右子树长度都有-1出现（preRight-preLeft， inRight-inLeft）

            // 只看preorder就是以preLeft+leftSize作为属于左子树的最后一个节点
            // 只看inorder部分就是以inRoot分开
            node->left = build(preLeft+1, preLeft+leftSize, inLeft, inRoot-1);
            node->right = build(preLeft+leftSize+1, preRight, inRoot+1, inRight);

            return node;
        };

        return build(0, n-1, 0, n-1);
    }
};



class Solution2 {
private:
    unordered_map<int, int> index;
public:
    // 闭区间
    TreeNode* myBuildTree(const vector<int>& preorder, const vector<int>& inorder, 
                int preorder_left, int preorder_right, 
                int inorder_left, int inorder_right) 
    {
        if (preorder_left > preorder_right) {
            return nullptr;
        }
        
        // 前序遍历中的第一个节点就是根节点
        int preorder_root = preorder_left;
        // 在中序遍历中定位根节点
        int inorder_root = index[preorder[preorder_root]];
        
        // 先把根节点建立出来
        TreeNode* root = new TreeNode(preorder[preorder_root]);

        // 得到左子树中的节点数目
        int size_left_subtree = inorder_root - inorder_left;
        // 递归地构造左子树，并连接到根节点
        // 先序遍历中「从 左边界+1 开始的 size_left_subtree」个元素就对应了中序遍历中「从 左边界 开始到 根节点定位-1」的元素
        root->left = myBuildTree(preorder, inorder, preorder_left + 1, preorder_left + size_left_subtree, inorder_left, inorder_root - 1);
        // 递归地构造右子树，并连接到根节点
        // 先序遍历中「从 左边界+1+左子树节点数目 开始到 右边界」的元素就对应了中序遍历中「从 根节点定位+1 到 右边界」的元素
        root->right = myBuildTree(preorder, inorder, preorder_left + size_left_subtree + 1, preorder_right, inorder_root + 1, inorder_right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        // 构造哈希映射，帮助我们快速定位根节点
        for (int i = 0; i < n; ++i) {
            index[inorder[i]] = i;
        }
        return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};

// @lc code=end


int main() 
{
    TreeNode* root;
    vector<int> p, q;
//     3
//    / \
//   9  20
//     /  \
//    15   7
    p = {3,9,20,15,7}; q={9,3,15,20,7};
    root = Solution().buildTree(p, q);
    prettyPrintTree(root);
}



