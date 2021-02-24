/*
 * @lc app=leetcode.cn id=1008 lang=cpp
 *
 * [1008] 前序遍历构造二叉搜索树
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
// {4,2} 在第一次mid == -1 返回空了
class Solution333 {
public:
    TreeNode* dfs(vector<int>& preorder, int s, int e) {
        if (s > e) return nullptr;
        TreeNode* root = new TreeNode(preorder[s]);
        if (s == e) return root;
        int mid(-1);
        for(int i=s+1; i<=e; ++i) {
            if (preorder[i] > preorder[s]) {
                mid = i; break;
            }
        }
        if (mid == -1) {
            return nullptr;
        }
        root->left = dfs(preorder, s+1, mid-1);
        root->right = dfs(preorder, mid, e);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return dfs(preorder, 0, preorder.size()-1);
    }
};

class Solution444 {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = constructor(preorder,0,preorder.size()-1);
        return root;
    }
    
    TreeNode* constructor(vector<int>& nums,int lo,int hi)
    {
        if(lo > hi) return NULL;
        TreeNode* root = new TreeNode(nums[lo]);
        if(lo == hi) return root;
        int j = lo + 1;
        while(nums[j]<nums[lo])
        {
            j++;
            if(j >= nums.size()) break;
        }
        root->left = constructor(nums,lo+1,j-1);
        root->right = constructor(nums,j,hi);
        return root;
    }
};

// func bstFromPreorder(preorder []int) *TreeNode {
//     if devide := len(preorder); devide > 0 {
//         for i, val := range preorder {
//             if val > preorder[0] {
//                 devide = i
//                 break
//             }
//         }
//         return &TreeNode{
//             Val: preorder[0],
//             Left: bstFromPreorder(preorder[1: devide]),
//             Right: bstFromPreorder(preorder[devide: ]),
//         }
//     }
//     return nil
// }


class SolutionXXXXXXXXX {
public:

    TreeNode* dfs(vector<int>& preorder, int s, int e) {
        if (s > e) return nullptr;
        if (s == e) return new TreeNode(preorder[s]);
        int mid(e-s);
        for(int i=s+1; i<=e; ++i) {
            if (preorder[i] > preorder[s]) {
                mid = i; break;
            }
        }
        TreeNode* root = new TreeNode(preorder[s]);
        root->left = dfs(preorder, s+1, mid-1);
        root->right = dfs(preorder, mid, e);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return dfs(preorder, 0, preorder.size()-1);
    }
};


class Solution {
    int idx = 0;
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int>& p = preorder;
        return dfs(p, INT_MIN, INT_MAX);
    }

    TreeNode* dfs(vector<int>& p, int l, int r) {
        if (idx == p.size() || p[idx] < l || p[idx] > r) return nullptr;
        TreeNode* ans = new TreeNode(p[idx++]);
        ans->left = dfs(p, l, ans->val);
        ans->right = dfs(p, ans->val, r);
        return ans;
    }
};

// @lc code=end

int main() {
    vector<int> xx;

    xx  = {8,5,1,7,10,12};
    prettyPrintTree( Solution().bstFromPreorder(xx) );
    xx  = {4,2};
    prettyPrintTree( Solution444().bstFromPreorder(xx) );

}