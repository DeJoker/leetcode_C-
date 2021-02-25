/*
 * @lc app=leetcode.cn id=1372 lang=cpp
 *
 * [1372] 二叉树中的最长交错路径
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

// 超时，这里增加备忘录
class Solution {
public:

    map<pair<TreeNode*, bool>, int> memo;

    int dfs(TreeNode* node,  bool le) {
        if (!node) return 0;
        if (memo.find({node, le}) != memo.end()) {
            return memo[{node, le}];
        }

        if(le) {
            int leLen = int(node->left!=nullptr) + dfs(node->left, !le);
            memo[{node, le}] = leLen;
            return leLen;
        }

        int riLen = int(node->right!=nullptr) + dfs(node->right, !le);
        memo[{node, le}] = riLen;
        return riLen;
    }

    int longestZigZag(TreeNode* root) {
        if (!root) return 0;
        int rootMax = max(dfs(root, true), dfs(root, false));
        int dirMax = max(longestZigZag(root->left), longestZigZag(root->right));
        return max(rootMax, dirMax);
    }
};


class SolutionOK {
    int ans=0;
    void dfs(TreeNode* root,int dir,int dis){//(当前结点，左/右孩子，路径长度)
        if(!root)return;//空结点返回
        ans=max(ans,dis);//更新最大值
        if(dir){//如果当前结点是其父结点的右孩子
            dfs(root->left,0,dis+1);//搜索其左孩子时，满足ZigZig，路径长度+1
            dfs(root->right,1,1);//搜索其右孩子时，不满足ZigZig，路径长度置为1
        } 
        else{//如果当前结点是其父结点的左孩子
            dfs(root->left,0,1);//搜索其左孩子时，不满足ZigZig，路径长度置为1
            dfs(root->right,1,dis+1);//搜索其右孩子时，满足ZigZig，路径长度+1
        }       
    }
public:
    int longestZigZag(TreeNode* root) {
        dfs(root->left,0,1);//0左节点
        dfs(root->right,1,1);//1右结点
        return ans;
    }
};

// @lc code=end

int main() {
    TreeNode* root;
    root = stringToTreeNode("[1,null,1,1,1,null,null,1,1,null,1,null,null,null,1,null,1]");
    LOG_DEBUG << Solution().longestZigZag(root);
    root = stringToTreeNode("[1,1,1,null,1,null,null,1,1,null,1]");
    LOG_DEBUG << Solution().longestZigZag(root);
    root = stringToTreeNode("[1,null,1,1,1,null,null,1,1,null,1,null,null,null,1,null,1]");
    LOG_DEBUG << Solution().longestZigZag(root);
}

